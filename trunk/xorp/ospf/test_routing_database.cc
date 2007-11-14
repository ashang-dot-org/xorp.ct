// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

// Copyright (c) 2001-2007 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/ospf/test_routing.cc,v 1.27 2007/11/07 03:53:52 atanu Exp $"

#define DEBUG_LOGGING
#define DEBUG_PRINT_FUNCTION_NAME

#include "ospf_module.h"

#include "libxorp/xorp.h"
#include "libxorp/test_main.hh"
#include "libxorp/debug.h"
#include "libxorp/xlog.h"
#include "libxorp/callback.hh"
#include "libxorp/tlv.hh"
#include "libxorp/ipv4.hh"
#include "libxorp/ipv6.hh"
#include "libxorp/ipnet.hh"
#include "libxorp/status_codes.h"
#include "libxorp/service.hh"
#include "libxorp/eventloop.hh"

#include <map>
#include <list>
#include <set>
#include <deque>

#include "libproto/spt.hh"

#include "ospf.hh"
#include "debug_io.hh"
#include "delay_queue.hh"
#include "vertex.hh"
#include "area_router.hh"
#include "test_common.hh"


// Make sure that all tests free up any memory that they use. This will
// allow us to use the leak checker program.

inline
bool
type_check(TestInfo& info, string message, uint32_t expected, uint32_t actual)
{
    if (expected != actual) {
	DOUT(info) << message << " should be " << expected << " is " << 
	    actual << endl;
	return false;
    }

    return true;
}

/**
 * Read in LSA database files written by print_lsas.cc and pretty
 * print it.
 */
bool
pp(TestInfo& info, string fname)
{
    if (0 == fname.size()) {
	DOUT(info) << "No filename supplied\n";
	return true;
    }

    OspfTypes::Version version = OspfTypes::V2;

    Tlv tlv;

    if (!tlv.open(fname, true /* read */)) {
	DOUT(info) << "Failed to open " << fname << endl;
	return false;
    }
    vector<uint8_t> data;
    uint32_t type;

    while (tlv.read(type, data)) {
	switch(static_cast<TLV>(type)) {
	case TLV_VERSION:
	    uint32_t tlv_version;
	    if (!tlv.get32(data, 0, tlv_version)) {
		return false;
	    }

	    DOUT(info) << "Version: " << tlv_version << endl;
	    break;
	case TLV_SYSTEM_INFO:
	    data.resize(data.size() + 1);
	    data[data.size() - 1] = 0;
    
	    DOUT(info) << "Built on " << &data[0] << endl;
	    break;
	case TLV_OSPF_VERSION:
	    uint32_t ospf_version;
	    if (!tlv.get32(data, 0, ospf_version)) {
		return false;
	    }

	    switch(ospf_version) {
	    case 2:
		version = OspfTypes::V2;
		break;
	    case 3:
		version = OspfTypes::V3;
		break;
	    }

	    DOUT(info) << "OSPFv" << ospf_version << endl;
	    break;
	case TLV_AREA:
	    OspfTypes::AreaID area;
	    if (!tlv.get32(data, 0, area)) {
		return false;
	    }

	    DOUT(info) << "Area: " << pr_id(area) << endl;
	    break;
	case TLV_LSA:
	    // By the time we get here we are assuming that
	    // TLV_OSPF_VERSION has been read.
	    LsaDecoder lsa_decoder(version);
	    initialise_lsa_decoder(version, lsa_decoder);

	    size_t len = data.size();
	    Lsa::LsaRef lsar = lsa_decoder.decode(&data[0], len);

	    DOUT(info) << lsar->str() << endl;
	    break;
	}
    }

    return true;
}

/**
 * Read in LSA database files written by print_lsas.cc and run the
 * routing computation.
 */
template <typename A> 
bool
routing(TestInfo& info, OspfTypes::Version version, string fname)
{
    if (0 == fname.size()) {
	DOUT(info) << "No filename supplied\n";

	return true;
    }

    EventLoop eventloop;
    DebugIO<A> io(info, version, eventloop);
    io.startup();
    
    Ospf<A> ospf(version, eventloop, &io);
    ospf.trace().all(info.verbose());
    Tlv tlv;

    if (!tlv.open(fname, true /* read */)) {
	DOUT(info) << "Failed to open " << fname << endl;
	return false;
    }

    vector<uint8_t> data;
    uint32_t type;

    // Read the version field and check it.
    if (!tlv.read(type, data)) {
	DOUT(info) << "Failed to read " << fname << endl;
	return false;
    }

    if (!type_check(info, "TLV Version", TLV_VERSION, type))
	return false;

    uint32_t tlv_version;
    if (!tlv.get32(data, 0, tlv_version)) {
	return false;
    }

    if (!type_check(info, "Version", TLV_CURRENT_VERSION, tlv_version))
	return false;

    // Read the system info
    if (!tlv.read(type, data)) {
	DOUT(info) << "Failed to read " << fname << endl;
	return false;
    }

    if (!type_check(info, "TLV System info", TLV_SYSTEM_INFO, type))
	return false;

    data.resize(data.size() + 1);
    data[data.size() - 1] = 0;
    
    DOUT(info) << "Built on " << &data[0] << endl;

    // Get OSPF version
    if (!tlv.read(type, data)) {
	DOUT(info) << "Failed to read " << fname << endl;
	return false;
    }
    
    if (!type_check(info, "TLV OSPF Version", TLV_OSPF_VERSION, type))
	return false;

    uint32_t ospf_version;
    if (!tlv.get32(data, 0, ospf_version)) {
	return false;
    }

    if (!type_check(info, "OSPF Version", version, ospf_version))
	return false;

    // OSPF area
    if (!tlv.read(type, data)) {
	DOUT(info) << "Failed to read " << fname << endl;
	return false;
    }
    
    if (!type_check(info, "TLV OSPF Area", TLV_AREA, type))
	return false;
    
    OspfTypes::AreaID area;
    if (!tlv.get32(data, 0, area)) {
	return false;
    }

    PeerManager<A>& pm = ospf.get_peer_manager();
    pm.create_area_router(area, OspfTypes::NORMAL);
    AreaRouter<A> *ar = pm.get_area_router(area);
    XLOG_ASSERT(ar);

    // The first LSA is this routers Router-LSA.
    if (!tlv.read(type, data)) {
	DOUT(info) << "Failed to read " << fname << endl;
	return false;
    }
    
    if (!type_check(info, "TLV LSA", TLV_LSA, type))
	return false;

    LsaDecoder lsa_decoder(version);
    initialise_lsa_decoder(version, lsa_decoder);

    size_t len = data.size();
    Lsa::LsaRef lsar = lsa_decoder.decode(&data[0], len);

    DOUT(info) << lsar->str() << endl;

    ospf.set_router_id(lsar->get_header().get_advertising_router());

    lsar->set_self_originating(true);
    ar->testing_replace_router_lsa(lsar);

    bool first_in_area = false;

    while (tlv.read(type, data)) {
	switch(static_cast<TLV>(type)) {
	case TLV_VERSION:
	    uint32_t tlv_version;
	    if (!tlv.get32(data, 0, tlv_version)) {
		return false;
	    }

	    DOUT(info) << "Version: " << tlv_version << endl;
	    break;
	case TLV_SYSTEM_INFO:
	    data.resize(data.size() + 1);
	    data[data.size() - 1] = 0;
    
	    DOUT(info) << "Built on " << &data[0] << endl;
	    break;
	case TLV_OSPF_VERSION:
	    uint32_t ospf_version;
	    if (!tlv.get32(data, 0, ospf_version)) {
		return false;
	    }

	    switch(ospf_version) {
	    case 2:
		version = OspfTypes::V2;
		break;
	    case 3:
		version = OspfTypes::V3;
		break;
	    }

	    DOUT(info) << "OSPFv" << ospf_version << endl;
	    break;
	case TLV_AREA:
	    OspfTypes::AreaID area;
	    if (!tlv.get32(data, 0, area)) {
		return false;
	    }

	    pm.create_area_router(area, OspfTypes::NORMAL);
	    ar = pm.get_area_router(area);
	    XLOG_ASSERT(ar);
	    
	    first_in_area = true;

	    DOUT(info) << "Area: " << pr_id(area) << endl;
	    break;
	case TLV_LSA:
	    // By the time we get here we are assuming that
	    // TLV_OSPF_VERSION has been read.
	    LsaDecoder lsa_decoder(version);
	    initialise_lsa_decoder(version, lsa_decoder);

	    size_t len = data.size();
	    Lsa::LsaRef lsar = lsa_decoder.decode(&data[0], len);

	    if (first_in_area) {
		lsar->set_self_originating(true);
		ar->testing_replace_router_lsa(lsar);
		first_in_area = false;
	    } else {
		ar->testing_add_lsa(lsar);
	    }

	    DOUT(info) << lsar->str() << endl;
	    break;
	}
    }

    pm.routing_recompute_all_areas();

    return true;
}

int
main(int argc, char **argv)
{
    XorpUnexpectedHandler x(xorp_unexpected_handler);

    xlog_init(argv[0], NULL);
    xlog_set_verbose(XLOG_VERBOSE_HIGH);
    xlog_add_default_output();
    xlog_start();

    TestMain t(argc, argv);

    string test =
	t.get_optional_args("-t", "--test", "run only the specified test");
    string fname = t.get_optional_args("-f", "--filename", "lsa database");
    t.complete_args_parsing();

    struct test {
	string test_name;
	XorpCallback1<bool, TestInfo&>::RefPtr cb;
    } tests[] = {
	{"pp", callback(pp, fname)},
	{"v2", callback(routing<IPv4>, OspfTypes::V2, fname)},
	{"v3", callback(routing<IPv6>, OspfTypes::V3, fname)},
    };

    try {
	if (test.empty()) {
	    for (size_t i = 0; i < sizeof(tests) / sizeof(struct test); i++)
		t.run(tests[i].test_name, tests[i].cb);
	} else {
	    for (size_t i = 0; i < sizeof(tests) / sizeof(struct test); i++)
		if (test == tests[i].test_name) {
		    t.run(tests[i].test_name, tests[i].cb);
		    return t.exit();
		}
	    t.failed("No test with name " + test + " found\n");
	}
    } catch(...) {
	xorp_catch_standard_exceptions();
    }

    xlog_stop();
    xlog_exit();

    return t.exit();
}
