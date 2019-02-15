//
//  CmdLineParser.h
//  CmdLineParser
//
//  Created by Hank Lee on 2/15/19.
//  Copyright (c) 2019 Hank Lee. All rights reserved.
//

#ifndef ___CmdLineParser___
#define ___CmdLineParser___

typedef enum
{
    APP_COMMAND_OPTION_WIDTH = 0,
    APP_COMMAND_OPTION_HEIGHT,
    APP_COMMAND_OPTION_MAX
} APP_COMMAND_OPTION_E;

typedef struct {
    uint32_t width;
    uint32_t height;
} APP_COMMAND_PARAMETER_T;


bool parse_command_parameter(int argc, char **argv, APP_COMMAND_PARAMETER_T *cmd_param_p);
#endif