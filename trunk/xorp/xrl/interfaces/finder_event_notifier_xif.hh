/*
 * Copyright (c) 2001-2003 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP$
 */

#ifndef __XRL_INTERFACES_FINDER_EVENT_NOTIFIER_XIF_HH__
#define __XRL_INTERFACES_FINDER_EVENT_NOTIFIER_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFinderEventNotifier"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFinderEventNotifierV0p1Client {
public:
    XrlFinderEventNotifierV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFinderEventNotifierV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterClassEventInterestCB;
    /**
     *  Send Xrl intended to:
     *  
     *  Register interest in events relating to a particular class.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_register_class_event_interest(
	const char*	target_name, 
	const string&	requester_instance, 
	const string&	class_name, 
	const RegisterClassEventInterestCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeregisterClassEventInterestCB;
    /**
     *  Send Xrl intended to:
     *  
     *  Deregister interest in events relating to a particular class.
     *  
     *  @param tgt_name Xrl Target name
     */
    bool send_deregister_class_event_interest(
	const char*	target_name, 
	const string&	requester_instance, 
	const string&	class_name, 
	const DeregisterClassEventInterestCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_register_class_event_interest(
	const XrlError&	e, 
	XrlArgs*	a, 
	RegisterClassEventInterestCB		cb
    );

    void unmarshall_deregister_class_event_interest(
	const XrlError&	e, 
	XrlArgs*	a, 
	DeregisterClassEventInterestCB		cb
    );

};

#endif /* __XRL_INTERFACES_FINDER_EVENT_NOTIFIER_XIF_HH__ */
