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

#ident "$XORP: xorp/libxipc/xrl_pf.cc,v 1.8 2008/10/02 21:57:24 bms Exp $"

#include "xrl_pf.hh"

// ----------------------------------------------------------------------------
// XrlPFListener

XrlPFListener::XrlPFListener(EventLoop& e, XrlDispatcher* d)
    : _eventloop(e), _dispatcher(d)
{
}

XrlPFListener::~XrlPFListener()
{
}

bool
XrlPFListener::set_dispatcher(const XrlDispatcher* d)
{
    if (_dispatcher == 0) {
	_dispatcher = d;
	return true;
    }
    return false;
}

// ----------------------------------------------------------------------------
// XrlPFSender

XrlPFSender::XrlPFSender(EventLoop& e, const char* address)
    : _eventloop(e), _address(address)
{
}

XrlPFSender::~XrlPFSender()
{
}