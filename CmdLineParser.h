//
//  CmdLineParser.h
//  CmdLineParser
//
//  Created by Hank Lee on 9/20/24.
//  Copyright (c) 2024 Hank Lee. All rights reserved.
//

#ifndef ___CmdLineParser___
#define ___CmdLineParser___


#define MAJOR_VER   1
#define MINOR_VER   0


typedef struct
{
    std::string input;
    int width;
    int height;
} CONTEXT_T;


int SetInput(int &i, std::string &next, CONTEXT_T &ctx);

int SetWidth(int &i, std::string &next, CONTEXT_T &ctx);

int SetHeight(int &i, std::string &next, CONTEXT_T &ctx);

void PrintContext(CONTEXT_T &ctx);


#endif