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


#include "includes.h"

void
net_show_help(
    )
{
    printf("usage: pmd-cli [connection options] net <command> [command options]\n");
    printf("\n");

    printf("List of Main Commands\n");
    printf("\n");

    printf("help                      Display a helpful usage message\n");
    printf("dns_servers               set/get dns servers\n");
    printf("set_iaid                  set iaid\n");
    printf("get_iaid                  get iaid\n");
    printf("set_duid                  set duid\n");
    printf("get_duid                  get duid\n");
}

int cli_manager_new(CliManager **ret) {
        _auto_cleanup_ CliManager *m = NULL;
        int i;

        static const Cli cli_commands[] = {
                { "status",                       WORD_ANY, WORD_ANY, true,  ncmcli_system_link_status },
                { "show",                         WORD_ANY, WORD_ANY, false, ncmcli_system_link_status },
#if 0
                { "set-mtu",                      2,        WORD_ANY, false, ncmcli_link_set_mtu },
                { "set-mac",                      2,        WORD_ANY, false, ncmcli_link_set_mac },
                { "set-link-mode",                2,        WORD_ANY, false, ncmcli_link_set_mode },
                { "set-dhcp-mode",                2,        WORD_ANY, false, ncmcli_link_set_dhcp_mode },
                { "set-dhcp4-client-identifier",  2,        WORD_ANY, false, ncmcli_link_set_dhcp4_client_identifier},
                { "set-dhcp-iaid",                2,        WORD_ANY, false, ncmcli_link_set_dhcp_client_iaid},
                { "set-dhcp-duid",                2,        WORD_ANY, false, ncmcli_link_set_dhcp_client_duid},
                { "set-link-state",               2,        WORD_ANY, false, ncmcli_link_update_state },
                { "add-link-address",             2,        WORD_ANY, false, ncmcli_link_add_address },
                { "delete-link-address",          1,        WORD_ANY, false, ncmcli_link_delete_address },
                { "add-default-gateway",          2,        WORD_ANY, false, ncmcli_link_add_default_gateway },
                { "delete-gateway",               1,        WORD_ANY, false, ncmcli_link_delete_gateway_or_route },
                { "add-route",                    2,        WORD_ANY, false, ncmcli_link_add_route },
                { "delete-route",                 1,        WORD_ANY, false, ncmcli_link_delete_gateway_or_route },
#endif
                { "set-hostname",                 1,        WORD_ANY, false, ncmcli_set_system_hostname },
#if 0
                { "show-dns",                     WORD_ANY, WORD_ANY, false, ncmcli_show_dns_server },
                { "add-dns",                      2,        WORD_ANY, false, ncmcli_add_dns_server },
                { "add-domain",                   1,        WORD_ANY, false, ncmcli_add_dns_domains },
                { "show-domains",                 WORD_ANY, WORD_ANY, false, ncmcli_show_dns_server_domains },
                { "revert-resolve-link",          1,        WORD_ANY, false, ncmcli_revert_resolve_link },
                { "set-link-local-address",       2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-ipv4ll-route",             2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-llmnr",                    2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-multicast-dns",            2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-lldp",                     2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-emit-lldp",                2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-ipforward",                2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-ipv6acceptra",             2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-ipmasquerade",             2,        WORD_ANY, false, ncmcli_link_set_network_section_bool },
                { "set-dhcp4-use-dns",            2,        WORD_ANY, false, ncmcli_link_set_dhcp4_section },
                { "set-dhcp4-use-domains",        2,        WORD_ANY, false, ncmcli_link_set_dhcp4_section },
                { "set-dhcp4-use-ntp",            2,        WORD_ANY, false, ncmcli_link_set_dhcp4_section },
                { "set-dhcp4-use-mtu",            2,        WORD_ANY, false, ncmcli_link_set_dhcp4_section },
                { "set-dhcp4-use-timezone",       2,        WORD_ANY, false, ncmcli_link_set_dhcp4_section },
                { "set-dhcp4-use-routes",         2,        WORD_ANY, false, ncmcli_link_set_dhcp4_section },
                { "set-dhcp6-use-dns",            2,        WORD_ANY, false, ncmcli_link_set_dhcp6_section },
                { "set-dhcp6-use-domains",        2,        WORD_ANY, false, ncmcli_link_set_dhcp6_section },
                { "set-dhcp6-use-ntp",            2,        WORD_ANY, false, ncmcli_link_set_dhcp6_section },
                { "set-dhcp6-use-mtu",            2,        WORD_ANY, false, ncmcli_link_set_dhcp6_section },
                { "set-dhcp6-use-timezone",       2,        WORD_ANY, false, ncmcli_link_set_dhcp6_section },
                { "set-dhcp6-use-routes",         2,        WORD_ANY, false, ncmcli_link_set_dhcp6_section },
                { "add-ntp",                      2,        WORD_ANY, false, ncmcli_link_add_ntp },
                { "set-ntp",                      2,        WORD_ANY, false, ncmcli_link_add_ntp },
                { "delete-ntp",                   2,        WORD_ANY, false, ncmcli_link_delete_ntp },
                { "disable-ipv6",                 1,        WORD_ANY, false, ncmcli_link_enable_ipv6 },
                { "enable-ipv6",                  1,        WORD_ANY, false, ncmcli_link_enable_ipv6 },
                { "reload",                       WORD_ANY, WORD_ANY, false, ncmcli_network_reload },
                { "reconfigure",                  WORD_ANY, WORD_ANY, false, ncmcli_link_reconfigure },
                { "generate-config-from-yaml",    1,        WORD_ANY, false, ncmcli_generate_networkd_config_from_yaml },
                { "apply-yaml-config"           , WORD_ANY, WORD_ANY, false, ncmcli_generate_networkd_config_from_yaml },
                { "generate-config-from-cmdline", WORD_ANY, WORD_ANY, false, ncmcli_generate_networkd_config_from_command_line },
#endif
                {}
        };

        m = new0(CliManager, 1);
        if (!m)
                return log_oom();

        *m = (CliManager) {
               .hash = g_hash_table_new(g_str_hash, g_str_equal),
               .commands = (Cli *) cli_commands,
        };

        if (!m->hash)
                return log_oom();

        for (i = 0;; i++) {
                if (cli_commands[i].name) {
                        if (!g_hash_table_insert(m->hash, (gpointer *) cli_commands[i].name, (gpointer *) &cli_commands[i]))
                                continue;
                } else
                        break;
        }

        *ret = steal_pointer(m);

        return 0;
}

void cli_unrefp(CliManager **m) {
        if (m && *m) {
                g_hash_table_unref((*m)->hash);
                free(*m);
        }
}

static Cli *cli_get_command(const CliManager *m, const char *name) {
        assert(m);
        assert(name);

        return g_hash_table_lookup(m->hash, name);
}

uint32_t cli_run_command(const CliManager *m, PPMDHANDLE pHandle, int argc, char *argv[]) {
        Cli *command = NULL;
        int remaining_argc;
        char *name;

        assert(m);

        optind = 1;
        remaining_argc = argc - optind - 1;

        argv += (optind + 1);
        optind = 0;
        name = argv[0];

        /* run default if no command specified */
        if (!name) {
                int i;

                for (i = 0;; i++) {
                        if (m->commands[i].default_command)
                                command = m->commands;
                        remaining_argc = 1;
                        return command->run(pHandle, remaining_argc, argv);
                }
        }

        command = cli_get_command(m, name);
        if (!command) {
                log_warning("Unknown cli command %s.", name);
                return -EINVAL;
        }

        if (command->min_args != WORD_ANY && (unsigned) remaining_argc <= command->min_args) {
                log_warning("Too few arguments.");
                return -EINVAL;
        }

        if (command->max_args != WORD_ANY && (unsigned) remaining_argc > command->max_args) {
                log_warning("Too many arguments.");
                return -EINVAL;
        }
        return command->run(pHandle, remaining_argc, argv);
}
