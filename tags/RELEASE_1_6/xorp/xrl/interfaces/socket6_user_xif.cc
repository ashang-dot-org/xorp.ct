/*
 * Copyright (c) 2001-2009 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/socket6_user_xif.cc,v 1.18 2008/10/02 21:58:40 bms Exp $"

#include "socket6_user_xif.hh"

bool
XrlSocket6UserV0p1Client::send_recv_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const string&	if_name,
	const string&	vif_name,
	const IPv6&	src_host,
	const uint32_t&	src_port,
	const vector<uint8_t>&	data,
	const RecvEventCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket6_user/0.1/recv_event");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(if_name));
        x->args().add(XrlAtom(vif_name));
        x->args().add(XrlAtom(src_host));
        x->args().add(XrlAtom(src_port));
        x->args().add(XrlAtom(data));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, if_name);
    x->args().set_arg(2, vif_name);
    x->args().set_arg(3, src_host);
    x->args().set_arg(4, src_port);
    x->args().set_arg(5, data);

    return _sender->send(*x, callback(this, &XrlSocket6UserV0p1Client::unmarshall_recv_event, cb));
}


/* Unmarshall recv_event */
void
XrlSocket6UserV0p1Client::unmarshall_recv_event(
	const XrlError&	e,
	XrlArgs*	a,
	RecvEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket6UserV0p1Client::send_inbound_connect_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv6&	src_host,
	const uint32_t&	src_port,
	const string&	new_sockid,
	const InboundConnectEventCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket6_user/0.1/inbound_connect_event");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(src_host));
        x->args().add(XrlAtom(src_port));
        x->args().add(XrlAtom(new_sockid));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, src_host);
    x->args().set_arg(2, src_port);
    x->args().set_arg(3, new_sockid);

    return _sender->send(*x, callback(this, &XrlSocket6UserV0p1Client::unmarshall_inbound_connect_event, cb));
}


/* Unmarshall inbound_connect_event */
void
XrlSocket6UserV0p1Client::unmarshall_inbound_connect_event(
	const XrlError&	e,
	XrlArgs*	a,
	InboundConnectEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool accept;
    try {
	a->get("accept", accept);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &accept);
}

bool
XrlSocket6UserV0p1Client::send_outgoing_connect_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const OutgoingConnectEventCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket6_user/0.1/outgoing_connect_event");
        x->args().add(XrlAtom(sockid));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);

    return _sender->send(*x, callback(this, &XrlSocket6UserV0p1Client::unmarshall_outgoing_connect_event, cb));
}


/* Unmarshall outgoing_connect_event */
void
XrlSocket6UserV0p1Client::unmarshall_outgoing_connect_event(
	const XrlError&	e,
	XrlArgs*	a,
	OutgoingConnectEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket6UserV0p1Client::send_error_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const string&	error,
	const bool&	fatal,
	const ErrorEventCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket6_user/0.1/error_event");
        x->args().add(XrlAtom(sockid));
        x->args().add(XrlAtom(error));
        x->args().add(XrlAtom(fatal));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);
    x->args().set_arg(1, error);
    x->args().set_arg(2, fatal);

    return _sender->send(*x, callback(this, &XrlSocket6UserV0p1Client::unmarshall_error_event, cb));
}


/* Unmarshall error_event */
void
XrlSocket6UserV0p1Client::unmarshall_error_event(
	const XrlError&	e,
	XrlArgs*	a,
	ErrorEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket6UserV0p1Client::send_disconnect_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const DisconnectEventCB&	cb
)
{
    static Xrl* x = NULL;

    if (!x) {
        x = new Xrl(dst_xrl_target_name, "socket6_user/0.1/disconnect_event");
        x->args().add(XrlAtom(sockid));
    }

    x->set_target(dst_xrl_target_name);

    x->args().set_arg(0, sockid);

    return _sender->send(*x, callback(this, &XrlSocket6UserV0p1Client::unmarshall_disconnect_event, cb));
}


/* Unmarshall disconnect_event */
void
XrlSocket6UserV0p1Client::unmarshall_disconnect_event(
	const XrlError&	e,
	XrlArgs*	a,
	DisconnectEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}