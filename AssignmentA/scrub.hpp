//
//  scrub.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef scrub_hpp
#define scrub_hpp

#include <utility>
#include "timing.hpp"
#include "readFile.hpp"
#include "readData.hpp"
#include "storeData.hpp"
#include "sortData.hpp"
#include "markData.hpp"
#include "writeData.hpp"
#include "logging.hpp"
//static vector<string> info;

void scrub(char* fileName,int no_thread, int total)
{
    
    START_TIMER
    ifstream inFile = readFile(fileName);
    inFile.seekg(0,inFile.end);
    int number = inFile.tellg()/total;
    //cout<<number<<endl;
    vector<tick> data = storeData(inFile,no_thread,number);
    /*
    for(auto itr = data.begin(); itr!=data.end();itr++)
    {
        itr->print();
    }*/
    sortData(data);
    markData(data);
    writeData(data,no_thread);
    END_TIMER
    
    double time;
    time = ELAPSED_TIME_NS;
    double memory;
    memory = data.capacity()*sizeof(tick);
    
    string temp;
    temp = "Thread " + to_string(no_thread) + ": Time is " + to_string(time) + " and memory is " + to_string(memory);
    //info.push_back(temp);
    //cout<<temp<<endl;
    logging(temp);
    //cout<<time<<endl; 
    
};

#endif
