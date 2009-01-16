// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2008 XORP, Inc.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, Version 2, June
// 1991 as published by the Free Software Foundation. Redistribution
// and/or modification of this program under the terms of any other
// version of the GNU General Public License is not permitted.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. For more details,
// see the GNU General Public License, Version 2, a copy of which can be
// found in the XORP LICENSE.gpl file.
// 
// XORP Inc, 2953 Bunker Hill Lane, Suite 204, Santa Clara, CA 95054, USA;
// http://xorp.net

// $XORP: xorp/cli/cli_private.hh,v 1.11 2008/07/23 05:09:47 pavlin Exp $


#ifndef __CLI_CLI_PRIVATE_HH__
#define __CLI_CLI_PRIVATE_HH__


//
// CLI implementation-specific definitions.
//


//
// Constants definitions
//
#define CLI_MAX_CONNECTIONS	129	// XXX: intentionally not 2^n number

#define XORP_CLI_WELCOME "Welcome to XORP on "
#define XORP_CLI_PROMPT  "Xorp> "
#define XORP_CLI_PROMPT_ENABLE  "XORP# "

#ifndef CHAR_TO_CTRL
#define CHAR_TO_CTRL(c) ((c) & 0x1f)
#endif
#ifndef CHAR_TO_META
#define CHAR_TO_META(c) ((c) | 0x080)
#endif
    

//
// Structures/classes, typedefs and macros
//

//
// Global variables
//

//
// Global functions prototypes
//

#endif // __CLI_CLI_PRIVATE_HH__