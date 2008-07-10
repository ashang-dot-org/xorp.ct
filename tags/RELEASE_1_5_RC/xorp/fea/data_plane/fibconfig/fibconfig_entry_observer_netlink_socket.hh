// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2008 International Computer Science Institute
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

// $XORP: xorp/fea/data_plane/fibconfig/fibconfig_entry_observer_netlink_socket.hh,v 1.4 2008/01/03 22:59:36 pavlin Exp $

#ifndef __FEA_DATA_PLANE_FIBCONFIG_FIBCONFIG_ENTRY_OBSERVER_NETLINK_SOCKET_HH__
#define __FEA_DATA_PLANE_FIBCONFIG_FIBCONFIG_ENTRY_OBSERVER_NETLINK_SOCKET_HH__

#include "fea/fibconfig_entry_observer.hh"
#include "fea/data_plane/control_socket/netlink_socket.hh"


class FibConfigEntryObserverNetlinkSocket : public FibConfigEntryObserver,
					    public NetlinkSocket,
					    public NetlinkSocketObserver {
public:
    /**
     * Constructor.
     *
     * @param fea_data_plane_manager the corresponding data plane manager
     * (@ref FeaDataPlaneManager).
     */
    FibConfigEntryObserverNetlinkSocket(FeaDataPlaneManager& fea_data_plane_manager);

    /**
     * Virtual destructor.
     */
    virtual ~FibConfigEntryObserverNetlinkSocket();

    /**
     * Start operation.
     * 
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int start(string& error_msg);
    
    /**
     * Stop operation.
     * 
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    virtual int stop(string& error_msg);
    
    /**
     * Receive data from the underlying system.
     * 
     * @param buffer the buffer with the received data.
     */
    virtual void receive_data(const vector<uint8_t>& buffer);
    
    void netlink_socket_data(const vector<uint8_t>& buffer);
    
private:
};

#endif // __FEA_DATA_PLANE_FIBCONFIG_FIBCONFIG_ENTRY_OBSERVER_NETLINK_SOCKET_HH__