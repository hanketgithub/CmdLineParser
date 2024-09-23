//
//  CmdLineParser.c
//  CmdLineParser
//
//  Created by Hank Lee on 9/20/24.
//  Copyright (c) 2024 Hank Lee. All rights reserved.
//

#include <iostream>
#include <string>

#include "CmdLineParser.h"

using namespace std;



int SetInput(int i, string &next, CONTEXT_T &ctx)
{
    ctx.input = next;
    i++;

    return 1;
}


int SetWidth(int i, string &next, CONTEXT_T &ctx)
{
    int width = stoi(next);
    ctx.width = width;

    i++;

    return 1;
}

int SetHeight(int i, string &next, CONTEXT_T &ctx)
{
    int height = stoi(next);
    ctx.height = height;

    return 1;
}


void PrintContext(CONTEXT_T &ctx)
{
    cout << "Input file: " << ctx.input << endl;
    cout << "Width: " << ctx.width << endl;
    cout << "Height: " << ctx.height << endl;
}
