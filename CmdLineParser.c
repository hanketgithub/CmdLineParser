//
//  CmdLineParser.c
//  CmdLineParser
//
//  Created by Hank Lee on 2/15/19.
//  Copyright (c) 2019 Hank Lee. All rights reserved.
//

#include <errno.h>
#include <limits.h>
#include <getopt.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "CmdLineParser.h"

#define MAX_WIDTH   4096
#define MAX_HEIGHT  4096
#define MIN_WIDTH   16
#define MIN_HEIGHT  16

#define GETOPT_CONSTRUCTOR(opt_name, opt_has_arg, opt_flag, opt_val) \
{   \
    .name       = opt_name, \
    .has_arg    = opt_has_arg, \
    .flag       = opt_flag, \
    .val        = opt_val \
}

static uint32_t strtou32(char *nptr, char **endptr, int base)
{
    uint64_t    value;
    char       *minus;

    value = strtoull ( nptr, endptr, base );

    minus = strchr ( nptr, '-' );

    if ( minus != NULL )
    {
        int64_t     signed_value;
        signed_value = ( int64_t ) value;

        if ( ( signed_value < INT_MIN ) || ( INT_MAX < signed_value ) )
        {
            *endptr = nptr;
            errno = ERANGE;
            return UINT_MAX;
        }
    }
    else
    {
        if ( UINT_MAX < value )
        {
            *endptr = nptr;
            errno = ERANGE;
            return UINT_MAX;
        }
    }

    return ( uint32_t ) value;
}

bool parse_command_parameter(int argc, char **argv, APP_COMMAND_PARAMETER_T *cmd_param_p)
{
    static const struct option command_options[] = {
        GETOPT_CONSTRUCTOR(
            "w",
            required_argument,
            NULL,
            APP_COMMAND_OPTION_WIDTH
        ),
        GETOPT_CONSTRUCTOR(
            "h",
            required_argument,
            NULL,
            APP_COMMAND_OPTION_HEIGHT
        ),
    };

    bool is_option_specified[APP_COMMAND_OPTION_MAX];
    bool is_end_of_option_param;
    char *err_p;

    /* Option parameter */
    for (int i = 0; i < APP_COMMAND_OPTION_MAX; i++)
    {
        is_option_specified[i] = false;
    }

    is_end_of_option_param = false;

    while (is_end_of_option_param == false)
    {
        int result;

        result = getopt_long_only(argc, argv, "", command_options, NULL);

        if (result != -1 && result != '?' && result < APP_COMMAND_OPTION_MAX)
        {
            if (is_option_specified[result])
            {
                return false;
            }
            else
            {
                is_option_specified[result] = true;
            }
        }

        switch (result) 
        {
            case APP_COMMAND_OPTION_WIDTH:
            {
                cmd_param_p->width = strtou32(optarg, &err_p, 0);
                if ((*err_p != '\0') || ((cmd_param_p->width) > MAX_WIDTH) || ((cmd_param_p->width) < MIN_WIDTH))
                {
                    fprintf(stderr, "Invalid width:%d\n", cmd_param_p->width);
                    return false;
                }
                break;
            }
            case APP_COMMAND_OPTION_HEIGHT:
            {
                cmd_param_p->height = strtou32(optarg, &err_p, 0);
                if ((*err_p != '\0') || ((cmd_param_p->height) > MAX_HEIGHT) || ((cmd_param_p->height) < MIN_HEIGHT))
                {
                    fprintf(stderr, "Invalid height:%d\n", cmd_param_p->height);
                    return false;
                }

                break;
            }
            case -1:
            {
                is_end_of_option_param = true;
                break;
            }
            case '?':
            {
                /* Invalid option. */
                return false;
            }
            default:
            {
                fprintf(stderr, "ERR: getopt_long_only");
                return false;
            }
        }
    }

    return true;
}
