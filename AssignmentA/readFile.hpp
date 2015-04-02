//
//  readFile.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef readFile_hpp
#define readFile_hpp

#include <iostream>
#include <fstream>

using namespace std;

ifstream readFile(char* cname)
{
    
    ifstream myfile(cname);

    if(myfile.is_open())
    {
        //cout<<"Opened"<<endl;
    }
    
    if(!myfile.is_open())
    {
        //cout<<"Not opened"<<endl;
    }
    
    return myfile;
    
};

#endif
