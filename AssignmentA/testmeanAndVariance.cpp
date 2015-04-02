//
//  testmeanAndVariance.cpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#include "variance.hpp"
#include "readFile.hpp"
#include "storeData.hpp"
#include <iostream>

using namespace std;

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
    
    cout<<mean(result)<<endl;
    cout<<variance(result)<<endl;
    
}

