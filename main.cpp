//
//  main.c
//  CmdLineParser
//
//  Created by Hank Lee on 9/20/24.
//  Copyright (c) 2024 Hank Lee. All rights reserved.
//

#include <functional>
#include <iostream>
#include <string>

#include <map>

#include "CmdLineParser.h"

using namespace std;
//using callback = int (*)(int &i, string &arg);

using callback = std::function<int (int &, string &arg, CONTEXT_T &ctx)>;


CONTEXT_T ctx;


map<string, callback> mp =
{
    { "-i", SetInput },

    { "-w", SetWidth },
    { "-h", SetHeight },

    { "--version", [](int &i, string &, CONTEXT_T &ctx) {
                        printf("Version: %d:%d\n", MAJOR_VER, MINOR_VER);
                        return 0;
                    }
    },
};

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Print Help menu\n");
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        string cur = argv[i];
        
        //cout << i << " : " << cur << endl;

        if (mp.find(cur) == mp.end())
        {
            cout << "Does not support option: " << cur << endl;
            return -1;
        }
        else
        {
            string next = i+1 < argc ? argv[i+1] : "";
            mp[cur](i, next, ctx);
        }
    }

    PrintContext(ctx);
    
    return 0;
}