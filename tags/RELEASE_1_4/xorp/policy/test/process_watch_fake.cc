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

#ident "$XORP: xorp/policy/test/process_watch_fake.cc,v 1.5 2006/10/12 01:25:09 pavlin Exp $"

#include "libxorp/xorp.h"

#include <iostream>

#include "process_watch_fake.hh"


void
ProcessWatchFake::add_interest(const string& id) {
    cout << "ProcessWatchFake add_interest: " << id << endl;
}