//
//  normal.hpp
//  NORMAL
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef normal_hpp
#define normal_hpp

#include "readFile.hpp"
#include "timing.hpp"
#include "JarqueBera.hpp"
#include "logging.hpp"
#include "outputting.hpp"
//static vector<bool> result;
//static vector<string> info;

void testnormal(char* fileName,int no_thread, int total)
{
    bool temp_result;
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
    
    temp_result = JarqueBera(data);
    
    END_TIMER
    
    //result.push_back(temp_result);
    
    //return result;
    
    double time;
    time = ELAPSED_TIME_NS;
    double memory;
    memory = data.capacity()*sizeof(tick);
    
    string temp;
    temp = "Thread" + to_string(no_thread) + "Time is " + to_string(time) + " and memory is " + to_string(memory);
    string output;
    if(temp_result) output =  "Thread " + to_string(no_thread) + " This part is normal distributed"+"\n";
    else output =  "Thread " + to_string(no_thread) + " This part is not normal distributed"+"\n";
    
    //info.push_back(temp);
    //cout<<temp<<endl;
    logging(temp);
    outputting(output);
    //cout<<time<<endl;
    
    
};


#endif
