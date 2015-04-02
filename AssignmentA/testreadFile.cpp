//
//  testreadFile.cpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#include <fstream>
#include <string>
#include <stdio.h>
#include "readFile.hpp"

using namespace std;

int main()
{
    ifstream myfile;
    string s = "/Users/xiaoyu/Programming/C++/BDiF/SCRUB/data10k.txt";
    
    char* name;
    name = &s[0];
    
    myfile = readFile(name);
    return 0;
    
}
