//
//  main.cpp
//  CmdLineParser
//
//  Created by Hank Lee on 9/20/24.
//  Copyright (c) 2024 Hank Lee. All rights reserved.
//


#include <iostream>
#include <string>


#include "CmdLineParser.h"


int main(int argc, char *argv[])
{
    CONTEXT_T ctx{};

    if (CmdLineParse(argc, argv, ctx))
    {
        printf("Some error!\n");
        return -1;
    }

    PrintContext(ctx);
    
    return 0;
}
