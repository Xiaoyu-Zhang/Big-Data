//
//  storeData.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef storeData_hpp
#define storeData_hpp

#include <vector>
#include <iostream>
#include <fstream>
#include "readData.hpp"
#include "tick.hpp"
using namespace std;

vector<tick> storeData(ifstream& myfile, int no_thread, int number)
{
    
    tick sample;
    //cout<<myfile.gcount()<<endl;
    vector<tick> storage;
    myfile.seekg((number)*(no_thread+1));
    string temp;
    getline(myfile,temp);
    //getline(myfile,temp,',');
    //cout<<"temp"<<temp<<endl;
    int temp_g;
    temp_g = myfile.tellg();
    //cout<<"temp_g"<<temp_g<<endl;
    myfile.seekg(number*no_thread);
    getline(myfile,temp);
    //getline(myfile,temp,',');
    //cout<<"temp"<<temp<<endl;
    //cout<<myfile.tellg()<<endl;
    while((myfile.tellg()!= temp_g)&&!myfile.eof())
    {
        sample = readData(myfile);
        storage.push_back(sample);
        //cout<<myfile.tellg()<<endl;
        //cout<<1<<endl;
    }
    //cout<<storage.size()<<endl;
    return storage;
}


#endif
