//
//  normal.cpp
//  NORMAL
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//



#include <string>
#include <thread>
#include <iostream>
#include "normal.hpp"
using namespace std;

static const int numThreads = 10;
//static vector<string> info;

int main(int argc, char* argv[])		//data.txt; # of threads
{
    string s = "/Users/xiaoyu/Programming/C++/BDiF/SCRUB/data10k.txt";
    
    
    char* name;
    name = &s[0];
    //ifstream inFile = readFile(name);
    //string* info = new string[numThreads];
    thread thread[numThreads];
    // Launch threads.
    for (int i = 0; i < numThreads; ++i)
    {
        thread[i] = std::thread(testnormal,name,i,numThreads);
    }
    cout << numThreads << " threads launched." << endl;
    // Join threads to the main thread of execution.
    for (int i = 0; i < numThreads; ++i)
    {
        thread[i].join();
    }
    
    
    /*
    ofstream logFile("/Users/xiaoyu/Programming/C++/BDiF/SCRUB/Log File.txt");
    for(auto itr = info->begin();itr != info->end(); itr++)
    {
        logFile<<*itr;
    }
    logFile.close();
    
    for(auto itr = info->begin(); itr != info->end();itr++)
    {
        cout<<*itr<<endl;
    }
    */
    //cout<<"Stop"<<endl;
    return 0;
    
    
}
