/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP$"

#include "bgp_mib_traps_xif.hh"

bool
XrlBgpMibTrapsV0p1Client::send_send_bgp_established_trap(
	const char*	the_tgt, 
	const string&	bgp_last_error, 
	const uint32_t&	bgp_state, 
	const SendBgpEstablishedTrapCB&	cb
)
{
    Xrl x(the_tgt, "bgp_mib_traps/0.1/send_bgp_established_trap");
    x.args().add("bgp_last_error", bgp_last_error);
    x.args().add("bgp_state", bgp_state);
    return _sender->send(x, callback(this, &XrlBgpMibTrapsV0p1Client::unmarshall_send_bgp_established_trap, cb));
}


/* Unmarshall send_bgp_established_trap */
void
XrlBgpMibTrapsV0p1Client::unmarshall_send_bgp_established_trap(
	const XrlError&	e, 
	XrlArgs*	a, 
	SendBgpEstablishedTrapCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlBgpMibTrapsV0p1Client::send_send_bgp_backward_transition_trap(
	const char*	the_tgt, 
	const string&	bgp_last_error, 
	const uint32_t&	bgp_state, 
	const SendBgpBackwardTransitionTrapCB&	cb
)
{
    Xrl x(the_tgt, "bgp_mib_traps/0.1/send_bgp_backward_transition_trap");
    x.args().add("bgp_last_error", bgp_last_error);
    x.args().add("bgp_state", bgp_state);
    return _sender->send(x, callback(this, &XrlBgpMibTrapsV0p1Client::unmarshall_send_bgp_backward_transition_trap, cb));
}


/* Unmarshall send_bgp_backward_transition_trap */
void
XrlBgpMibTrapsV0p1Client::unmarshall_send_bgp_backward_transition_trap(
	const XrlError&	e, 
	XrlArgs*	a, 
	SendBgpBackwardTransitionTrapCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != 0)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}
