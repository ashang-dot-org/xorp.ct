/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP$"

#include "mld6igmp_xif.hh"

bool
XrlMld6igmpV0p1Client::send_enable_vif(
	const char*	the_tgt, 
	const string&	vif_name, 
	const EnableVifCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/enable_vif");
    x.args().add("vif_name", vif_name);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_enable_vif, cb));
}


/* Unmarshall enable_vif */
void
XrlMld6igmpV0p1Client::unmarshall_enable_vif(
	const XrlError&	e, 
	XrlArgs*	a, 
	EnableVifCB		cb
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
XrlMld6igmpV0p1Client::send_disable_vif(
	const char*	the_tgt, 
	const string&	vif_name, 
	const DisableVifCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/disable_vif");
    x.args().add("vif_name", vif_name);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_disable_vif, cb));
}


/* Unmarshall disable_vif */
void
XrlMld6igmpV0p1Client::unmarshall_disable_vif(
	const XrlError&	e, 
	XrlArgs*	a, 
	DisableVifCB		cb
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
XrlMld6igmpV0p1Client::send_start_vif(
	const char*	the_tgt, 
	const string&	vif_name, 
	const StartVifCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/start_vif");
    x.args().add("vif_name", vif_name);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_start_vif, cb));
}


/* Unmarshall start_vif */
void
XrlMld6igmpV0p1Client::unmarshall_start_vif(
	const XrlError&	e, 
	XrlArgs*	a, 
	StartVifCB		cb
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
XrlMld6igmpV0p1Client::send_stop_vif(
	const char*	the_tgt, 
	const string&	vif_name, 
	const StopVifCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/stop_vif");
    x.args().add("vif_name", vif_name);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_stop_vif, cb));
}


/* Unmarshall stop_vif */
void
XrlMld6igmpV0p1Client::unmarshall_stop_vif(
	const XrlError&	e, 
	XrlArgs*	a, 
	StopVifCB		cb
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
XrlMld6igmpV0p1Client::send_enable_all_vifs(
	const char*	the_tgt, 
	const EnableAllVifsCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/enable_all_vifs");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_enable_all_vifs, cb));
}


/* Unmarshall enable_all_vifs */
void
XrlMld6igmpV0p1Client::unmarshall_enable_all_vifs(
	const XrlError&	e, 
	XrlArgs*	a, 
	EnableAllVifsCB		cb
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
XrlMld6igmpV0p1Client::send_disable_all_vifs(
	const char*	the_tgt, 
	const DisableAllVifsCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/disable_all_vifs");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_disable_all_vifs, cb));
}


/* Unmarshall disable_all_vifs */
void
XrlMld6igmpV0p1Client::unmarshall_disable_all_vifs(
	const XrlError&	e, 
	XrlArgs*	a, 
	DisableAllVifsCB		cb
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
XrlMld6igmpV0p1Client::send_start_all_vifs(
	const char*	the_tgt, 
	const StartAllVifsCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/start_all_vifs");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_start_all_vifs, cb));
}


/* Unmarshall start_all_vifs */
void
XrlMld6igmpV0p1Client::unmarshall_start_all_vifs(
	const XrlError&	e, 
	XrlArgs*	a, 
	StartAllVifsCB		cb
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
XrlMld6igmpV0p1Client::send_stop_all_vifs(
	const char*	the_tgt, 
	const StopAllVifsCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/stop_all_vifs");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_stop_all_vifs, cb));
}


/* Unmarshall stop_all_vifs */
void
XrlMld6igmpV0p1Client::unmarshall_stop_all_vifs(
	const XrlError&	e, 
	XrlArgs*	a, 
	StopAllVifsCB		cb
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
XrlMld6igmpV0p1Client::send_enable_mld6igmp(
	const char*	the_tgt, 
	const EnableMld6IgmpCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/enable_mld6igmp");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_enable_mld6igmp, cb));
}


/* Unmarshall enable_mld6igmp */
void
XrlMld6igmpV0p1Client::unmarshall_enable_mld6igmp(
	const XrlError&	e, 
	XrlArgs*	a, 
	EnableMld6IgmpCB		cb
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
XrlMld6igmpV0p1Client::send_disable_mld6igmp(
	const char*	the_tgt, 
	const DisableMld6IgmpCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/disable_mld6igmp");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_disable_mld6igmp, cb));
}


/* Unmarshall disable_mld6igmp */
void
XrlMld6igmpV0p1Client::unmarshall_disable_mld6igmp(
	const XrlError&	e, 
	XrlArgs*	a, 
	DisableMld6IgmpCB		cb
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
XrlMld6igmpV0p1Client::send_enable_cli(
	const char*	the_tgt, 
	const EnableCliCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/enable_cli");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_enable_cli, cb));
}


/* Unmarshall enable_cli */
void
XrlMld6igmpV0p1Client::unmarshall_enable_cli(
	const XrlError&	e, 
	XrlArgs*	a, 
	EnableCliCB		cb
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
XrlMld6igmpV0p1Client::send_disable_cli(
	const char*	the_tgt, 
	const DisableCliCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/disable_cli");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_disable_cli, cb));
}


/* Unmarshall disable_cli */
void
XrlMld6igmpV0p1Client::unmarshall_disable_cli(
	const XrlError&	e, 
	XrlArgs*	a, 
	DisableCliCB		cb
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
XrlMld6igmpV0p1Client::send_start_mld6igmp(
	const char*	the_tgt, 
	const StartMld6IgmpCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/start_mld6igmp");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_start_mld6igmp, cb));
}


/* Unmarshall start_mld6igmp */
void
XrlMld6igmpV0p1Client::unmarshall_start_mld6igmp(
	const XrlError&	e, 
	XrlArgs*	a, 
	StartMld6IgmpCB		cb
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
XrlMld6igmpV0p1Client::send_stop_mld6igmp(
	const char*	the_tgt, 
	const StopMld6IgmpCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/stop_mld6igmp");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_stop_mld6igmp, cb));
}


/* Unmarshall stop_mld6igmp */
void
XrlMld6igmpV0p1Client::unmarshall_stop_mld6igmp(
	const XrlError&	e, 
	XrlArgs*	a, 
	StopMld6IgmpCB		cb
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
XrlMld6igmpV0p1Client::send_start_cli(
	const char*	the_tgt, 
	const StartCliCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/start_cli");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_start_cli, cb));
}


/* Unmarshall start_cli */
void
XrlMld6igmpV0p1Client::unmarshall_start_cli(
	const XrlError&	e, 
	XrlArgs*	a, 
	StartCliCB		cb
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
XrlMld6igmpV0p1Client::send_stop_cli(
	const char*	the_tgt, 
	const StopCliCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/stop_cli");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_stop_cli, cb));
}


/* Unmarshall stop_cli */
void
XrlMld6igmpV0p1Client::unmarshall_stop_cli(
	const XrlError&	e, 
	XrlArgs*	a, 
	StopCliCB		cb
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
XrlMld6igmpV0p1Client::send_get_vif_proto_version(
	const char*	the_tgt, 
	const string&	vif_name, 
	const GetVifProtoVersionCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/get_vif_proto_version");
    x.args().add("vif_name", vif_name);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_get_vif_proto_version, cb));
}


/* Unmarshall get_vif_proto_version */
void
XrlMld6igmpV0p1Client::unmarshall_get_vif_proto_version(
	const XrlError&	e, 
	XrlArgs*	a, 
	GetVifProtoVersionCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != 1)", (uint32_t)a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    uint32_t proto_version;
    try {
	a->get("proto_version", proto_version);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &proto_version);
}

bool
XrlMld6igmpV0p1Client::send_set_vif_proto_version(
	const char*	the_tgt, 
	const string&	vif_name, 
	const uint32_t&	proto_version, 
	const SetVifProtoVersionCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/set_vif_proto_version");
    x.args().add("vif_name", vif_name);
    x.args().add("proto_version", proto_version);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_set_vif_proto_version, cb));
}


/* Unmarshall set_vif_proto_version */
void
XrlMld6igmpV0p1Client::unmarshall_set_vif_proto_version(
	const XrlError&	e, 
	XrlArgs*	a, 
	SetVifProtoVersionCB		cb
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
XrlMld6igmpV0p1Client::send_reset_vif_proto_version(
	const char*	the_tgt, 
	const string&	vif_name, 
	const ResetVifProtoVersionCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/reset_vif_proto_version");
    x.args().add("vif_name", vif_name);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_reset_vif_proto_version, cb));
}


/* Unmarshall reset_vif_proto_version */
void
XrlMld6igmpV0p1Client::unmarshall_reset_vif_proto_version(
	const XrlError&	e, 
	XrlArgs*	a, 
	ResetVifProtoVersionCB		cb
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
XrlMld6igmpV0p1Client::send_enable_log_trace(
	const char*	the_tgt, 
	const EnableLogTraceCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/enable_log_trace");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_enable_log_trace, cb));
}


/* Unmarshall enable_log_trace */
void
XrlMld6igmpV0p1Client::unmarshall_enable_log_trace(
	const XrlError&	e, 
	XrlArgs*	a, 
	EnableLogTraceCB		cb
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
XrlMld6igmpV0p1Client::send_disable_log_trace(
	const char*	the_tgt, 
	const DisableLogTraceCB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/disable_log_trace");
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_disable_log_trace, cb));
}


/* Unmarshall disable_log_trace */
void
XrlMld6igmpV0p1Client::unmarshall_disable_log_trace(
	const XrlError&	e, 
	XrlArgs*	a, 
	DisableLogTraceCB		cb
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
XrlMld6igmpV0p1Client::send_add_protocol4(
	const char*	the_tgt, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const AddProtocol4CB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/add_protocol4");
    x.args().add("xrl_sender_name", xrl_sender_name);
    x.args().add("protocol_name", protocol_name);
    x.args().add("protocol_id", protocol_id);
    x.args().add("vif_name", vif_name);
    x.args().add("vif_index", vif_index);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_add_protocol4, cb));
}


/* Unmarshall add_protocol4 */
void
XrlMld6igmpV0p1Client::unmarshall_add_protocol4(
	const XrlError&	e, 
	XrlArgs*	a, 
	AddProtocol4CB		cb
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
XrlMld6igmpV0p1Client::send_add_protocol6(
	const char*	the_tgt, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const AddProtocol6CB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/add_protocol6");
    x.args().add("xrl_sender_name", xrl_sender_name);
    x.args().add("protocol_name", protocol_name);
    x.args().add("protocol_id", protocol_id);
    x.args().add("vif_name", vif_name);
    x.args().add("vif_index", vif_index);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_add_protocol6, cb));
}


/* Unmarshall add_protocol6 */
void
XrlMld6igmpV0p1Client::unmarshall_add_protocol6(
	const XrlError&	e, 
	XrlArgs*	a, 
	AddProtocol6CB		cb
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
XrlMld6igmpV0p1Client::send_delete_protocol4(
	const char*	the_tgt, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const DeleteProtocol4CB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/delete_protocol4");
    x.args().add("xrl_sender_name", xrl_sender_name);
    x.args().add("protocol_name", protocol_name);
    x.args().add("protocol_id", protocol_id);
    x.args().add("vif_name", vif_name);
    x.args().add("vif_index", vif_index);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_delete_protocol4, cb));
}


/* Unmarshall delete_protocol4 */
void
XrlMld6igmpV0p1Client::unmarshall_delete_protocol4(
	const XrlError&	e, 
	XrlArgs*	a, 
	DeleteProtocol4CB		cb
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
XrlMld6igmpV0p1Client::send_delete_protocol6(
	const char*	the_tgt, 
	const string&	xrl_sender_name, 
	const string&	protocol_name, 
	const uint32_t&	protocol_id, 
	const string&	vif_name, 
	const uint32_t&	vif_index, 
	const DeleteProtocol6CB&	cb
)
{
    Xrl x(the_tgt, "mld6igmp/0.1/delete_protocol6");
    x.args().add("xrl_sender_name", xrl_sender_name);
    x.args().add("protocol_name", protocol_name);
    x.args().add("protocol_id", protocol_id);
    x.args().add("vif_name", vif_name);
    x.args().add("vif_index", vif_index);
    return _sender->send(x, callback(this, &XrlMld6igmpV0p1Client::unmarshall_delete_protocol6, cb));
}


/* Unmarshall delete_protocol6 */
void
XrlMld6igmpV0p1Client::unmarshall_delete_protocol6(
	const XrlError&	e, 
	XrlArgs*	a, 
	DeleteProtocol6CB		cb
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
