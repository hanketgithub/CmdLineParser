//
//  CmdLineParser.cpp
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

using callback = std::function<int (string &arg, CONTEXT_T &ctx)>;

/* Return number of arguments processed */
int SetInput(std::string &arg, CONTEXT_T &ctx);


int SetWidth(std::string &arg, CONTEXT_T &ctx);


int SetHeight(std::string &arg, CONTEXT_T &ctx);


static map<string, callback> mp =
{
    { "-i", SetInput },

    { "-w", SetWidth },
    { "-h", SetHeight },

    { "--version", [](string &arg, CONTEXT_T &ctx) {
                        printf("Version: %d:%d\n", MAJOR_VER, MINOR_VER);
                        return 0;
                    }
    },
};


int SetInput(string &arg, CONTEXT_T &ctx)
{
    ctx.input = arg;

    return 1;
}


int SetWidth(string &arg, CONTEXT_T &ctx)
{
    int width = stoi(arg);
    ctx.width = width;

    return 1;
}

int SetHeight(string &arg, CONTEXT_T &ctx)
{
    int height = stoi(arg);
    ctx.height = height;

    return 1;
}

int CmdLineParse(int argc, char *argv[], CONTEXT_T &ctx)
{
    if (argc == 1)
    {
        printf("Print Help menu\n");
        return -1;
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

            int res = mp[cur](next, ctx);
            if (res == -1)
            {
                cout << cur << "error" << endl;
            }
            i += res;
        }
    }

    return 0;
}


void PrintContext(CONTEXT_T &ctx)
{
    cout << "Input file: " << ctx.input << endl;
    cout << "Width: " << ctx.width << endl;
    cout << "Height: " << ctx.height << endl;
}
