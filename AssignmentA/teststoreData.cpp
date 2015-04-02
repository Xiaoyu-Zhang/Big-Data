//
//  teststoreData.cpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#include "storeData.hpp"
#include "readFile.hpp"
int main()
{
    vector<tick> result;
    
    ifstream myfile;
    string s = "/Users/xiaoyu/Programming/C++/BDiF/SCRUB/data10k.txt";
    
    char* name;
    name = &s[0];
    
    myfile = readFile(name);
    result = storeData(myfile);
    result[99].print();
};