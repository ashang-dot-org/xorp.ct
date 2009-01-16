// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2009 XORP, Inc.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License, Version
// 2.1, June 1999 as published by the Free Software Foundation.
// Redistribution and/or modification of this program under the terms of
// any other version of the GNU Lesser General Public License is not
// permitted.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For more details,
// see the GNU Lesser General Public License, Version 2.1, a copy of
// which can be found in the XORP LICENSE.lgpl file.
// 
// XORP, Inc, 2953 Bunker Hill Lane, Suite 204, Santa Clara, CA 95054, USA;
// http://xorp.net

#ident "$XORP: xorp/libxipc/xrl_error.cc,v 1.17 2008/10/02 21:57:24 bms Exp $"

#include "xrl_module.h"

#include "libxorp/xorp.h"
#include "libxorp/c_format.hh"

#include "xrl_error.hh"


class XrlErrlet {
public:
    XrlErrlet(XrlErrorCode n, const char *s) : _error_code(n), _error_msg(s)
    {
	if (find(n)) abort(); // programming error, definitely
	_next = _errlet_head; // plumb in entry
	_errlet_head = this;
    }

    static const XrlErrlet* find(uint32_t error_code) {
	for (const XrlErrlet* e = _errlet_head; e != 0; e = e->_next) {
	    if (e->_error_code == XrlErrorCode(error_code)) return e;
	}
	return 0;
    }

    XrlErrorCode error_code() const	{ return _error_code; }
    const char*  error_msg() const	{ return _error_msg; }

protected:
    XrlErrorCode _error_code;
    const char*  _error_msg;

    // Node for list of all known errlets
    XrlErrlet*	   _next;
    // Head pointer for all known errlets
    static XrlErrlet* _errlet_head;
};

XrlErrlet* XrlErrlet::_errlet_head = 0;

// Macro that glues together XrlErrlet and XrlError
#define XRL_ERROR_GLUE(ename, oname, reason)				      \
static const XrlErrlet ename(oname, reason); 				      \
static const XrlError E_##oname(&ename);				      \
const XrlError& XrlError::oname() { return E_##oname; }

// Dispatch Method Errors - generated by user callback
// NB BAD_ARGS and COMMAND_FAILED have additional magic at the end of this file
XRL_ERROR_GLUE(okay, OKAY, "Okay");
XRL_ERROR_GLUE(bad_args, BAD_ARGS, "Bad argument(s)");
XRL_ERROR_GLUE(command_failed, COMMAND_FAILED, "Command failed");

// Transport Errors - generated by transport library
XRL_ERROR_GLUE(resolve_failed, RESOLVE_FAILED, "Resolve failed");
XRL_ERROR_GLUE(no_finder, NO_FINDER, "Finder not present/ready");
XRL_ERROR_GLUE(no_such_method, NO_SUCH_METHOD, "No such method");

XRL_ERROR_GLUE(send_failed, SEND_FAILED, "Transport failed");
XRL_ERROR_GLUE(reply_timed_out, REPLY_TIMED_OUT, "Reply timed out");
XRL_ERROR_GLUE(send_failed_transient, SEND_FAILED_TRANSIENT, "Transient transport failure");

XRL_ERROR_GLUE(internal_error, INTERNAL_ERROR, "Internal error");

XrlError::XrlError() : _errlet(&okay) {}

XrlError::XrlError(const XrlErrlet* errlet) : _errlet(errlet) {}

XrlError::XrlError(XrlErrorCode errcode, const string& note)
    : _note(note)
{
    _errlet = XrlErrlet::find(errcode);
    if (_errlet == 0) {
	_errlet = &internal_error;
	_note = c_format("Errorcode %d unknown", errcode);
	if (note.empty() == false)
	    _note += " " + note;
    }
}

bool
XrlError::known_code(uint32_t errcode)
{
    return (XrlErrlet::find(errcode) != 0);
}

XrlErrorCode
XrlError::error_code() const
{
    return _errlet->error_code();
}

const char*
XrlError::error_msg() const
{
    return _errlet->error_msg();
}