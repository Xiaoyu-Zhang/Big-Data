//
//  testreadData.cpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#include <stdio.h>
#include "readData.hpp"
#include "readFile.hpp"

int main()
{
    ifstream myfile;
    string s = "/Users/xiaoyu/Programming/C++/BDiF/SCRUB/data10k.txt";
    
    char* name;
    name = &s[0];
    
    myfile = readFile(name);
    
    tick sample;
    sample = readData(myfile);
    sample = readData(myfile);
    sample = readData(myfile);
    sample.print();
    
    
    return 0;
    
}