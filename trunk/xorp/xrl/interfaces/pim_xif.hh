/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/pim_xif.hh,v 1.7 2003/02/25 01:38:50 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_PIM_XIF_HH__
#define __XRL_INTERFACES_PIM_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifPim"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlPimV0p1Client {
public:
    XrlPimV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlPimV0p1Client() {}

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB0;
    /**
     *  Send Xrl intended to:
     *  
     *  Enable/disable/start/stop a PIM vif interface.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param vif_name the name of the vif to enable/disable/start/stop.
     */
    bool send_enable_vif(
	const char*	target_name, 
	const string&	vif_name, 
	const CB0&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB1;

    bool send_disable_vif(
	const char*	target_name, 
	const string&	vif_name, 
	const CB1&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB2;

    bool send_start_vif(
	const char*	target_name, 
	const string&	vif_name, 
	const CB2&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB3;

    bool send_stop_vif(
	const char*	target_name, 
	const string&	vif_name, 
	const CB3&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB4;
    /**
     *  Send Xrl intended to:
     *  
     *  Enable/disable/start/stop all PIM vif interfaces.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_enable_all_vifs(
	const char*	target_name, 
	const CB4&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB5;

    bool send_disable_all_vifs(
	const char*	target_name, 
	const CB5&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB6;

    bool send_start_all_vifs(
	const char*	target_name, 
	const CB6&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB7;

    bool send_stop_all_vifs(
	const char*	target_name, 
	const CB7&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB8;
    /**
     *  Send Xrl intended to:
     *  
     *  Enable/disable/start/stop PIM protocol and PIM CLI access.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_enable_pim(
	const char*	target_name, 
	const CB8&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB9;

    bool send_disable_pim(
	const char*	target_name, 
	const CB9&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB10;

    bool send_enable_cli(
	const char*	target_name, 
	const CB10&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB11;

    bool send_disable_cli(
	const char*	target_name, 
	const CB11&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB12;

    bool send_start_pim(
	const char*	target_name, 
	const CB12&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB13;

    bool send_stop_pim(
	const char*	target_name, 
	const CB13&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB14;

    bool send_start_cli(
	const char*	target_name, 
	const CB14&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB15;

    bool send_stop_cli(
	const char*	target_name, 
	const CB15&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB16;
    /**
     *  Send Xrl intended to:
     *  
     *  Enable/disable/start/stop BSR.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_enable_bsr(
	const char*	target_name, 
	const CB16&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB17;

    bool send_disable_bsr(
	const char*	target_name, 
	const CB17&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB18;

    bool send_start_bsr(
	const char*	target_name, 
	const CB18&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB19;

    bool send_stop_bsr(
	const char*	target_name, 
	const CB19&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB20;
    /**
     *  Send Xrl intended to:
     *  
     *  Add/delete candidate-BSR configuration.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param scope_zone_id the ID of the configured zone.
     *  
     *  @param is_scope_zone true if configuring administratively scoped zone.
     *  
     *  @param vif_name the name of the vif to use its address as a
     *  candidate-BSR.
     *  
     *  @param bsr_priority the BSR priority (larger is better).
     *  
     *  @param hash_masklen the hash mask length.
     */
    bool send_add_config_cand_bsr_by_vif_name4(
	const char*	target_name, 
	const IPv4Net&	scope_zone_id, 
	const bool&	is_scope_zone, 
	const string&	vif_name, 
	const uint32_t&	bsr_priority, 
	const uint32_t&	hash_masklen, 
	const CB20&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB21;

    bool send_add_config_cand_bsr_by_vif_name6(
	const char*	target_name, 
	const IPv6Net&	scope_zone_id, 
	const bool&	is_scope_zone, 
	const string&	vif_name, 
	const uint32_t&	bsr_priority, 
	const uint32_t&	hash_masklen, 
	const CB21&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB22;

    bool send_add_config_cand_bsr_by_addr4(
	const char*	target_name, 
	const IPv4Net&	scope_zone_id, 
	const bool&	is_scope_zone, 
	const IPv4&	cand_bsr_addr, 
	const uint32_t&	bsr_priority, 
	const uint32_t&	hash_masklen, 
	const CB22&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB23;

    bool send_add_config_cand_bsr_by_addr6(
	const char*	target_name, 
	const IPv6Net&	scope_zone_id, 
	const bool&	is_scope_zone, 
	const IPv6&	cand_bsr_addr, 
	const uint32_t&	bsr_priority, 
	const uint32_t&	hash_masklen, 
	const CB23&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB24;

    bool send_delete_config_cand_bsr4(
	const char*	target_name, 
	const IPv4Net&	scope_zone_id, 
	const bool&	is_scope_zone, 
	const CB24&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB25;

    bool send_delete_config_cand_bsr6(
	const char*	target_name, 
	const IPv6Net&	scope_zone_id, 
	const bool&	is_scope_zone, 
	const CB25&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB26;
    /**
     *  Send Xrl intended to:
     *  
     *  Add/delete Candidate-RP configuration.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param group_prefix the group prefix of the configured zone.
     *  
     *  @param is_scope_zone true if configuring administratively scoped zone.
     *  
     *  @param vif_name the name of the vif to use its address as a
     *  candidate-RP.
     *  
     *  @param rp_priority the Cand-RP priority (smaller is better).
     *  
     *  @param rp_holdtime the Cand-RP holdtime (in seconds).
     */
    bool send_add_config_cand_rp_by_vif_name4(
	const char*	target_name, 
	const IPv4Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const string&	vif_name, 
	const uint32_t&	rp_priority, 
	const uint32_t&	rp_holdtime, 
	const CB26&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB27;

    bool send_add_config_cand_rp_by_vif_name6(
	const char*	target_name, 
	const IPv6Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const string&	vif_name, 
	const uint32_t&	rp_priority, 
	const uint32_t&	rp_holdtime, 
	const CB27&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB28;

    bool send_add_config_cand_rp_by_addr4(
	const char*	target_name, 
	const IPv4Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const IPv4&	cand_rp_addr, 
	const uint32_t&	rp_priority, 
	const uint32_t&	rp_holdtime, 
	const CB28&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB29;

    bool send_add_config_cand_rp_by_addr6(
	const char*	target_name, 
	const IPv6Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const IPv6&	cand_rp_addr, 
	const uint32_t&	rp_priority, 
	const uint32_t&	rp_holdtime, 
	const CB29&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB30;

    bool send_delete_config_cand_rp_by_vif_name4(
	const char*	target_name, 
	const IPv4Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const string&	vif_name, 
	const CB30&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB31;

    bool send_delete_config_cand_rp_by_vif_name6(
	const char*	target_name, 
	const IPv6Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const string&	vif_name, 
	const CB31&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB32;

    bool send_delete_config_cand_rp_by_addr4(
	const char*	target_name, 
	const IPv4Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const IPv4&	cand_rp_addr, 
	const CB32&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB33;

    bool send_delete_config_cand_rp_by_addr6(
	const char*	target_name, 
	const IPv6Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const IPv6&	cand_rp_addr, 
	const CB33&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB34;
    /**
     *  Send Xrl intended to:
     *  
     *  Add/delete/complete static RP configuration.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param group_prefix the group prefix for the RP.
     *  
     *  @param rp_addr the RP address.
     *  
     *  @param rp_priority the RP priority (smaller is better).
     *  
     *  @param hash_masklen the hash masklen used in computing an RP for a
     *  group. It should be same across all RPs. If set to zero, the default
     *  one will be used.
     */
    bool send_add_config_rp4(
	const char*	target_name, 
	const IPv4Net&	group_prefix, 
	const IPv4&	rp_addr, 
	const uint32_t&	rp_priority, 
	const uint32_t&	hash_masklen, 
	const CB34&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB35;

    bool send_add_config_rp6(
	const char*	target_name, 
	const IPv6Net&	group_prefix, 
	const IPv6&	rp_addr, 
	const uint32_t&	rp_priority, 
	const uint32_t&	hash_masklen, 
	const CB35&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB36;

    bool send_delete_config_rp4(
	const char*	target_name, 
	const IPv4Net&	group_prefix, 
	const IPv4&	rp_addr, 
	const CB36&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB37;

    bool send_delete_config_rp6(
	const char*	target_name, 
	const IPv6Net&	group_prefix, 
	const IPv6&	rp_addr, 
	const CB37&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB38;

    bool send_config_rp_done(
	const char*	target_name, 
	const CB38&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const uint32_t*, const bool*, const string*>::RefPtr CB39;
    /**
     *  Send Xrl intended to:
     *  
     *  Configure PIM Hello-related metrics. The 'set_foo' XRLs set the
     *  particular values. The 'reset_foo' XRLs reset the metrics to their
     *  default values.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param vif_name the name of the vif to configure.
     */
    bool send_get_vif_proto_version(
	const char*	target_name, 
	const string&	vif_name, 
	const CB39&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB40;

    bool send_set_vif_proto_version(
	const char*	target_name, 
	const string&	vif_name, 
	const uint32_t&	proto_version, 
	const CB40&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB41;

    bool send_reset_vif_proto_version(
	const char*	target_name, 
	const string&	vif_name, 
	const CB41&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const uint32_t*, const bool*, const string*>::RefPtr CB42;

    bool send_get_vif_hello_triggered_delay(
	const char*	target_name, 
	const string&	vif_name, 
	const CB42&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB43;

    bool send_set_vif_hello_triggered_delay(
	const char*	target_name, 
	const string&	vif_name, 
	const uint32_t&	hello_triggered_delay, 
	const CB43&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB44;

    bool send_reset_vif_hello_triggered_delay(
	const char*	target_name, 
	const string&	vif_name, 
	const CB44&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const uint32_t*, const bool*, const string*>::RefPtr CB45;

    bool send_get_vif_hello_period(
	const char*	target_name, 
	const string&	vif_name, 
	const CB45&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB46;

    bool send_set_vif_hello_period(
	const char*	target_name, 
	const string&	vif_name, 
	const uint32_t&	hello_period, 
	const CB46&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB47;

    bool send_reset_vif_hello_period(
	const char*	target_name, 
	const string&	vif_name, 
	const CB47&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const uint32_t*, const bool*, const string*>::RefPtr CB48;

    bool send_get_vif_hello_holdtime(
	const char*	target_name, 
	const string&	vif_name, 
	const CB48&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB49;

    bool send_set_vif_hello_holdtime(
	const char*	target_name, 
	const string&	vif_name, 
	const uint32_t&	hello_holdtime, 
	const CB49&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB50;

    bool send_reset_vif_hello_holdtime(
	const char*	target_name, 
	const string&	vif_name, 
	const CB50&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const uint32_t*, const bool*, const string*>::RefPtr CB51;

    bool send_get_vif_dr_priority(
	const char*	target_name, 
	const string&	vif_name, 
	const CB51&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB52;

    bool send_set_vif_dr_priority(
	const char*	target_name, 
	const string&	vif_name, 
	const uint32_t&	dr_priority, 
	const CB52&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB53;

    bool send_reset_vif_dr_priority(
	const char*	target_name, 
	const string&	vif_name, 
	const CB53&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const uint32_t*, const bool*, const string*>::RefPtr CB54;

    bool send_get_vif_lan_delay(
	const char*	target_name, 
	const string&	vif_name, 
	const CB54&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB55;

    bool send_set_vif_lan_delay(
	const char*	target_name, 
	const string&	vif_name, 
	const uint32_t&	lan_delay, 
	const CB55&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB56;

    bool send_reset_vif_lan_delay(
	const char*	target_name, 
	const string&	vif_name, 
	const CB56&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const uint32_t*, const bool*, const string*>::RefPtr CB57;

    bool send_get_vif_override_interval(
	const char*	target_name, 
	const string&	vif_name, 
	const CB57&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB58;

    bool send_set_vif_override_interval(
	const char*	target_name, 
	const string&	vif_name, 
	const uint32_t&	override_interval, 
	const CB58&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB59;

    bool send_reset_vif_override_interval(
	const char*	target_name, 
	const string&	vif_name, 
	const CB59&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const bool*, const bool*, const string*>::RefPtr CB60;

    bool send_get_vif_is_tracking_support_disabled(
	const char*	target_name, 
	const string&	vif_name, 
	const CB60&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB61;

    bool send_set_vif_is_tracking_support_disabled(
	const char*	target_name, 
	const string&	vif_name, 
	const bool&	is_tracking_support_disabled, 
	const CB61&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB62;

    bool send_reset_vif_is_tracking_support_disabled(
	const char*	target_name, 
	const string&	vif_name, 
	const CB62&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const bool*, const bool*, const string*>::RefPtr CB63;

    bool send_get_vif_accept_nohello_neighbors(
	const char*	target_name, 
	const string&	vif_name, 
	const CB63&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB64;

    bool send_set_vif_accept_nohello_neighbors(
	const char*	target_name, 
	const string&	vif_name, 
	const bool&	accept_nohello_neighbors, 
	const CB64&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB65;

    bool send_reset_vif_accept_nohello_neighbors(
	const char*	target_name, 
	const string&	vif_name, 
	const CB65&	cb
    );

    typedef XorpCallback4<void, const XrlError&, const uint32_t*, const bool*, const string*>::RefPtr CB66;

    bool send_get_vif_join_prune_period(
	const char*	target_name, 
	const string&	vif_name, 
	const CB66&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB67;

    bool send_set_vif_join_prune_period(
	const char*	target_name, 
	const string&	vif_name, 
	const uint32_t&	join_prune_period, 
	const CB67&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB68;

    bool send_reset_vif_join_prune_period(
	const char*	target_name, 
	const string&	vif_name, 
	const CB68&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB69;
    /**
     *  Send Xrl intended to:
     *  
     *  Enable/disable the PIM trace log.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_enable_log_trace(
	const char*	target_name, 
	const CB69&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB70;

    bool send_disable_log_trace(
	const char*	target_name, 
	const CB70&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB71;
    /**
     *  Send Xrl intended to:
     *  
     *  Test-related methods: add Join/Prune entries, and send them to a
     *  neighbor.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_add_test_jp_entry4(
	const char*	target_name, 
	const IPv4&	source_addr, 
	const IPv4&	group_addr, 
	const uint32_t&	group_masklen, 
	const string&	mrt_entry_type, 
	const string&	action_jp, 
	const uint32_t&	holdtime, 
	const bool&	new_group_bool, 
	const CB71&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB72;

    bool send_add_test_jp_entry6(
	const char*	target_name, 
	const IPv6&	source_addr, 
	const IPv6&	group_addr, 
	const uint32_t&	group_masklen, 
	const string&	mrt_entry_type, 
	const string&	action_jp, 
	const uint32_t&	holdtime, 
	const bool&	new_group_bool, 
	const CB72&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB73;

    bool send_send_test_jp_entry4(
	const char*	target_name, 
	const IPv4&	nbr_addr, 
	const CB73&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB74;

    bool send_send_test_jp_entry6(
	const char*	target_name, 
	const IPv6&	nbr_addr, 
	const CB74&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB75;
    /**
     *  Send Xrl intended to:
     *  
     *  Test-related methods: send an Assert message on an interface.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param vif_name the name of the vif to send the Assert on.
     *  
     *  @param source_addr the source address inside the Assert message.
     *  
     *  @param group_addr the group address inside the Assert message.
     *  
     *  @param rpt_bit the RPT-bit inside the Assert message.
     *  
     *  @param metric_preference the metric preference inside the Assert
     *  message.
     *  
     *  @param metric the metric inside the Assert message.
     */
    bool send_send_test_assert4(
	const char*	target_name, 
	const string&	vif_name, 
	const IPv4&	source_addr, 
	const IPv4&	group_addr, 
	const bool&	rpt_bit, 
	const uint32_t&	metric_preference, 
	const uint32_t&	metric, 
	const CB75&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB76;

    bool send_send_test_assert6(
	const char*	target_name, 
	const string&	vif_name, 
	const IPv6&	source_addr, 
	const IPv6&	group_addr, 
	const bool&	rpt_bit, 
	const uint32_t&	metric_preference, 
	const uint32_t&	metric, 
	const CB76&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB77;
    /**
     *  Send Xrl intended to:
     *  
     *  Test-related methods: send Bootstrap and Cand-RP-Adv messages.
     *  
     *  @param tgt_name Xrl Target name
     *  
     *  @param zone_id_scope_zone_prefix the zone prefix of the zone ID.
     *  
     *  @param zone_id_is_scope_zone true if the zone is scoped.
     *  
     *  @param bsr_addr the address of the Bootstrap router.
     *  
     *  @param bsr_priority the priority of the Bootstrap router.
     *  
     *  @param hash_masklen the hash masklen inside the Bootstrap messages.
     *  
     *  @param fragment_tag the fragment tag inside the Bootstrap messages.
     */
    bool send_add_test_bsr_zone4(
	const char*	target_name, 
	const IPv4Net&	zone_id_scope_zone_prefix, 
	const bool&	zone_id_is_scope_zone, 
	const IPv4&	bsr_addr, 
	const uint32_t&	bsr_priority, 
	const uint32_t&	hash_masklen, 
	const uint32_t&	fragment_tag, 
	const CB77&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB78;

    bool send_add_test_bsr_zone6(
	const char*	target_name, 
	const IPv6Net&	zone_id_scope_zone_prefix, 
	const bool&	zone_id_is_scope_zone, 
	const IPv6&	bsr_addr, 
	const uint32_t&	bsr_priority, 
	const uint32_t&	hash_masklen, 
	const uint32_t&	fragment_tag, 
	const CB78&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB79;

    bool send_add_test_bsr_group_prefix4(
	const char*	target_name, 
	const IPv4Net&	zone_id_scope_zone_prefix, 
	const bool&	zone_id_is_scope_zone, 
	const IPv4Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const uint32_t&	expected_rp_count, 
	const CB79&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB80;

    bool send_add_test_bsr_group_prefix6(
	const char*	target_name, 
	const IPv6Net&	zone_id_scope_zone_prefix, 
	const bool&	zone_id_is_scope_zone, 
	const IPv6Net&	group_prefix, 
	const bool&	is_scope_zone, 
	const uint32_t&	expected_rp_count, 
	const CB80&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB81;

    bool send_add_test_bsr_rp4(
	const char*	target_name, 
	const IPv4Net&	zone_id_scope_zone_prefix, 
	const bool&	zone_id_is_scope_zone, 
	const IPv4Net&	group_prefix, 
	const IPv4&	rp_addr, 
	const uint32_t&	rp_priority, 
	const uint32_t&	rp_holdtime, 
	const CB81&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB82;

    bool send_add_test_bsr_rp6(
	const char*	target_name, 
	const IPv6Net&	zone_id_scope_zone_prefix, 
	const bool&	zone_id_is_scope_zone, 
	const IPv6Net&	group_prefix, 
	const IPv6&	rp_addr, 
	const uint32_t&	rp_priority, 
	const uint32_t&	rp_holdtime, 
	const CB82&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB83;

    bool send_send_test_bootstrap(
	const char*	target_name, 
	const string&	vif_name, 
	const CB83&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB84;

    bool send_send_test_bootstrap_by_dest4(
	const char*	target_name, 
	const string&	vif_name, 
	const IPv4&	dest_addr, 
	const CB84&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB85;

    bool send_send_test_bootstrap_by_dest6(
	const char*	target_name, 
	const string&	vif_name, 
	const IPv6&	dest_addr, 
	const CB85&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const bool*, const string*>::RefPtr CB86;

    bool send_send_test_cand_rp_adv(
	const char*	target_name, 
	const CB86&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall0(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB0		cb
    );

    void unmarshall1(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB1		cb
    );

    void unmarshall2(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB2		cb
    );

    void unmarshall3(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB3		cb
    );

    void unmarshall4(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB4		cb
    );

    void unmarshall5(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB5		cb
    );

    void unmarshall6(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB6		cb
    );

    void unmarshall7(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB7		cb
    );

    void unmarshall8(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB8		cb
    );

    void unmarshall9(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB9		cb
    );

    void unmarshall10(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB10		cb
    );

    void unmarshall11(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB11		cb
    );

    void unmarshall12(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB12		cb
    );

    void unmarshall13(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB13		cb
    );

    void unmarshall14(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB14		cb
    );

    void unmarshall15(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB15		cb
    );

    void unmarshall16(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB16		cb
    );

    void unmarshall17(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB17		cb
    );

    void unmarshall18(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB18		cb
    );

    void unmarshall19(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB19		cb
    );

    void unmarshall20(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB20		cb
    );

    void unmarshall21(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB21		cb
    );

    void unmarshall22(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB22		cb
    );

    void unmarshall23(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB23		cb
    );

    void unmarshall24(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB24		cb
    );

    void unmarshall25(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB25		cb
    );

    void unmarshall26(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB26		cb
    );

    void unmarshall27(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB27		cb
    );

    void unmarshall28(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB28		cb
    );

    void unmarshall29(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB29		cb
    );

    void unmarshall30(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB30		cb
    );

    void unmarshall31(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB31		cb
    );

    void unmarshall32(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB32		cb
    );

    void unmarshall33(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB33		cb
    );

    void unmarshall34(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB34		cb
    );

    void unmarshall35(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB35		cb
    );

    void unmarshall36(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB36		cb
    );

    void unmarshall37(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB37		cb
    );

    void unmarshall38(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB38		cb
    );

    void unmarshall39(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB39		cb
    );

    void unmarshall40(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB40		cb
    );

    void unmarshall41(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB41		cb
    );

    void unmarshall42(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB42		cb
    );

    void unmarshall43(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB43		cb
    );

    void unmarshall44(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB44		cb
    );

    void unmarshall45(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB45		cb
    );

    void unmarshall46(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB46		cb
    );

    void unmarshall47(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB47		cb
    );

    void unmarshall48(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB48		cb
    );

    void unmarshall49(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB49		cb
    );

    void unmarshall50(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB50		cb
    );

    void unmarshall51(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB51		cb
    );

    void unmarshall52(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB52		cb
    );

    void unmarshall53(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB53		cb
    );

    void unmarshall54(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB54		cb
    );

    void unmarshall55(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB55		cb
    );

    void unmarshall56(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB56		cb
    );

    void unmarshall57(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB57		cb
    );

    void unmarshall58(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB58		cb
    );

    void unmarshall59(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB59		cb
    );

    void unmarshall60(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB60		cb
    );

    void unmarshall61(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB61		cb
    );

    void unmarshall62(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB62		cb
    );

    void unmarshall63(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB63		cb
    );

    void unmarshall64(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB64		cb
    );

    void unmarshall65(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB65		cb
    );

    void unmarshall66(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB66		cb
    );

    void unmarshall67(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB67		cb
    );

    void unmarshall68(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB68		cb
    );

    void unmarshall69(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB69		cb
    );

    void unmarshall70(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB70		cb
    );

    void unmarshall71(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB71		cb
    );

    void unmarshall72(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB72		cb
    );

    void unmarshall73(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB73		cb
    );

    void unmarshall74(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB74		cb
    );

    void unmarshall75(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB75		cb
    );

    void unmarshall76(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB76		cb
    );

    void unmarshall77(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB77		cb
    );

    void unmarshall78(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB78		cb
    );

    void unmarshall79(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB79		cb
    );

    void unmarshall80(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB80		cb
    );

    void unmarshall81(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB81		cb
    );

    void unmarshall82(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB82		cb
    );

    void unmarshall83(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB83		cb
    );

    void unmarshall84(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB84		cb
    );

    void unmarshall85(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB85		cb
    );

    void unmarshall86(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB86		cb
    );

};

#endif /* __XRL_INTERFACES_PIM_XIF_HH__ */
