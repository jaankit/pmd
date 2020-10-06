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

#define WORD_ANY ((unsigned) -1)

uint32_t
netmgr_version_cmd(
    PPMDHANDLE hPMD,
    PNET_CMD_ARGS pCmdArgs
    );

int cli_manager_new(CliManager **ret);
void cli_unrefp(CliManager **m);
uint32_t cli_run_command(const CliManager *m, PPMDHANDLE pHandle, int argc, char *argv[]);


uint32_t
ncmcli_system_link_status(
    PPMDHANDLE hPMD,
    int argc,
    char *argv[]
);

uint32_t
ncmcli_set_system_hostname(
    PPMDHANDLE hPMD,
    int argc,
    char *argv[]
);
