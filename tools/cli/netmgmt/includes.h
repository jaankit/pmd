/*
 * Copyright © 2016-2017 VMware, Inc.  All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, without
 * warranties or conditions of any kind, EITHER EXPRESS OR IMPLIED.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#pragma once

#include <net/if.h>
#include <arpa/inet.h>
#include "../includes.h"
#include "structs.h"
#include "prototypes.h"
#include "netmgmt_h.h"
#include <netmgmt/netmgr.h>
#include <netmgmt/netmgrcli.h>
#include <network-config-manager.h>
#include "pmd_netmgr.h"
#include "alloc-util.h"
#include "log.h"
#include <glib.h>
#include <stdbool.h>

#define WORD_ANY ((unsigned) -1)

typedef int (*CommandRunFunction)(PPMDHANDLE hPMD, int argc, char **argv);

typedef struct Cli {
        const char *name;
        unsigned min_args, max_args;
        bool default_command;

        CommandRunFunction run;
} Cli;

typedef struct CliManager {
        GHashTable *hash;

        Cli *commands;
} CliManager;
