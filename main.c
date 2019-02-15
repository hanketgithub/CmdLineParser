//
//  main.c
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

int main(int argc, char *argv[]) {
    APP_COMMAND_PARAMETER_T cmd_param = { 0 };
    
    parse_command_parameter(argc, argv, &cmd_param);
    
    printf("w=%d h=%d\n", cmd_param.width, cmd_param.height);
    
    return 0;
}
