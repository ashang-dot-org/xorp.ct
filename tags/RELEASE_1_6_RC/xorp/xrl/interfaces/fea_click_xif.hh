/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See the XORP LICENSE.lgpl file for licensing, conditions, and warranties
 * on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/fea_click_xif.hh,v 1.14 2008/07/23 11:55:14 bms Exp $
 */

#ifndef __XRL_INTERFACES_FEA_CLICK_XIF_HH__
#define __XRL_INTERFACES_FEA_CLICK_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaClick"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFeaClickV0p1Client {
public:
    XrlFeaClickV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFeaClickV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr LoadClickCB;
    /**
     *  Send Xrl intended to:
     *
     *  Load Click FEA support.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_load_click(
	const char*	dst_xrl_target_name,
	const LoadClickCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnloadClickCB;
    /**
     *  Send Xrl intended to:
     *
     *  Unload Click FEA support.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_unload_click(
	const char*	dst_xrl_target_name,
	const UnloadClickCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableClickCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable Click FEA support.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable the Click FEA support, otherwise
     *  disable it.
     */
    bool send_enable_click(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableClickCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartClickCB;
    /**
     *  Send Xrl intended to:
     *
     *  Start Click FEA support.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_start_click(
	const char*	dst_xrl_target_name,
	const StartClickCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopClickCB;
    /**
     *  Send Xrl intended to:
     *
     *  Stop Click FEA support.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_stop_click(
	const char*	dst_xrl_target_name,
	const StopClickCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableDuplicateRoutesToKernelCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable duplicating the Click routes to the system kernel.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable duplicating the Click routes to the
     *  system kernel, otherwise disable it.
     */
    bool send_enable_duplicate_routes_to_kernel(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableDuplicateRoutesToKernelCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableKernelClickCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable kernel-level Click FEA support.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable the kernel-level Click FEA support,
     *  otherwise disable it.
     */
    bool send_enable_kernel_click(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableKernelClickCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableKernelClickInstallOnStartupCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable installing kernel-level Click on startup.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then install kernel-level Click on startup.
     */
    bool send_enable_kernel_click_install_on_startup(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableKernelClickInstallOnStartupCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetKernelClickModulesCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the list of kernel Click modules to load on startup if
     *  installing kernel-level Click on startup is enabled. The file names of
     *  the kernel modules are separated by colon.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param modules the list of kernel Click modules (separated by colon) to
     *  load.
     */
    bool send_set_kernel_click_modules(
	const char*	dst_xrl_target_name,
	const string&	modules,
	const SetKernelClickModulesCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetKernelClickMountDirectoryCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the kernel-level Click mount directory.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param directory the kernel-level Click mount directory.
     */
    bool send_set_kernel_click_mount_directory(
	const char*	dst_xrl_target_name,
	const string&	directory,
	const SetKernelClickMountDirectoryCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetKernelClickConfigGeneratorFileCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the external program to generate the kernel-level Click
     *  configuration.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param kernel_click_config_generator_file the name of the external
     *  program to generate the kernel-level Click configuration.
     */
    bool send_set_kernel_click_config_generator_file(
	const char*	dst_xrl_target_name,
	const string&	kernel_click_config_generator_file,
	const SetKernelClickConfigGeneratorFileCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableUserClickCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable user-level Click FEA support.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param enable if true, then enable the user-level Click FEA support,
     *  otherwise disable it.
     */
    bool send_enable_user_click(
	const char*	dst_xrl_target_name,
	const bool&	enable,
	const EnableUserClickCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUserClickCommandFileCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the user-level Click command file.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param user_click_command_file the name of the user-level Click command
     *  file.
     */
    bool send_set_user_click_command_file(
	const char*	dst_xrl_target_name,
	const string&	user_click_command_file,
	const SetUserClickCommandFileCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUserClickCommandExtraArgumentsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the extra arguments to the user-level Click command.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param user_click_command_extra_arguments the extra arguments to the
     *  user-level Click command.
     */
    bool send_set_user_click_command_extra_arguments(
	const char*	dst_xrl_target_name,
	const string&	user_click_command_extra_arguments,
	const SetUserClickCommandExtraArgumentsCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUserClickCommandExecuteOnStartupCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify whether to execute on startup the user-level Click command.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param user_click_command_execute_on_startup if true, then execute the
     *  user-level Click command on startup.
     */
    bool send_set_user_click_command_execute_on_startup(
	const char*	dst_xrl_target_name,
	const bool&	user_click_command_execute_on_startup,
	const SetUserClickCommandExecuteOnStartupCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUserClickControlAddressCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the address to use for control access to the user-level Click.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param user_click_control_address the address to use for control access
     *  to the user-level Click.
     */
    bool send_set_user_click_control_address(
	const char*	dst_xrl_target_name,
	const IPv4&	user_click_control_address,
	const SetUserClickControlAddressCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUserClickControlSocketPortCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the socket port to use for control access to the user-level
     *  Click.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param user_click_control_socket_port the socket port to use for
     *  control access to the user-level Click.
     */
    bool send_set_user_click_control_socket_port(
	const char*	dst_xrl_target_name,
	const uint32_t&	user_click_control_socket_port,
	const SetUserClickControlSocketPortCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUserClickStartupConfigFileCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the configuration file to be used by user-level Click on
     *  startup.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param user_click_startup_config_file the name of the configuration
     *  file to be used by user-level Click on startup.
     */
    bool send_set_user_click_startup_config_file(
	const char*	dst_xrl_target_name,
	const string&	user_click_startup_config_file,
	const SetUserClickStartupConfigFileCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetUserClickConfigGeneratorFileCB;
    /**
     *  Send Xrl intended to:
     *
     *  Specify the external program to generate the user-level Click
     *  configuration.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param user_click_config_generator_file the name of the external
     *  program to generate the user-level Click configuration.
     */
    bool send_set_user_click_config_generator_file(
	const char*	dst_xrl_target_name,
	const string&	user_click_config_generator_file,
	const SetUserClickConfigGeneratorFileCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_load_click(
	const XrlError&	e,
	XrlArgs*	a,
	LoadClickCB		cb
    );

    void unmarshall_unload_click(
	const XrlError&	e,
	XrlArgs*	a,
	UnloadClickCB		cb
    );

    void unmarshall_enable_click(
	const XrlError&	e,
	XrlArgs*	a,
	EnableClickCB		cb
    );

    void unmarshall_start_click(
	const XrlError&	e,
	XrlArgs*	a,
	StartClickCB		cb
    );

    void unmarshall_stop_click(
	const XrlError&	e,
	XrlArgs*	a,
	StopClickCB		cb
    );

    void unmarshall_enable_duplicate_routes_to_kernel(
	const XrlError&	e,
	XrlArgs*	a,
	EnableDuplicateRoutesToKernelCB		cb
    );

    void unmarshall_enable_kernel_click(
	const XrlError&	e,
	XrlArgs*	a,
	EnableKernelClickCB		cb
    );

    void unmarshall_enable_kernel_click_install_on_startup(
	const XrlError&	e,
	XrlArgs*	a,
	EnableKernelClickInstallOnStartupCB		cb
    );

    void unmarshall_set_kernel_click_modules(
	const XrlError&	e,
	XrlArgs*	a,
	SetKernelClickModulesCB		cb
    );

    void unmarshall_set_kernel_click_mount_directory(
	const XrlError&	e,
	XrlArgs*	a,
	SetKernelClickMountDirectoryCB		cb
    );

    void unmarshall_set_kernel_click_config_generator_file(
	const XrlError&	e,
	XrlArgs*	a,
	SetKernelClickConfigGeneratorFileCB		cb
    );

    void unmarshall_enable_user_click(
	const XrlError&	e,
	XrlArgs*	a,
	EnableUserClickCB		cb
    );

    void unmarshall_set_user_click_command_file(
	const XrlError&	e,
	XrlArgs*	a,
	SetUserClickCommandFileCB		cb
    );

    void unmarshall_set_user_click_command_extra_arguments(
	const XrlError&	e,
	XrlArgs*	a,
	SetUserClickCommandExtraArgumentsCB		cb
    );

    void unmarshall_set_user_click_command_execute_on_startup(
	const XrlError&	e,
	XrlArgs*	a,
	SetUserClickCommandExecuteOnStartupCB		cb
    );

    void unmarshall_set_user_click_control_address(
	const XrlError&	e,
	XrlArgs*	a,
	SetUserClickControlAddressCB		cb
    );

    void unmarshall_set_user_click_control_socket_port(
	const XrlError&	e,
	XrlArgs*	a,
	SetUserClickControlSocketPortCB		cb
    );

    void unmarshall_set_user_click_startup_config_file(
	const XrlError&	e,
	XrlArgs*	a,
	SetUserClickStartupConfigFileCB		cb
    );

    void unmarshall_set_user_click_config_generator_file(
	const XrlError&	e,
	XrlArgs*	a,
	SetUserClickConfigGeneratorFileCB		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_CLICK_XIF_HH__ */