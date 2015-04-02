//
//  writeData.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef writeData_hpp
#define writeData_hpp

#include <fstream>
#include <string>
using namespace std;

void writeData(vector<tick>& source,int i)
{
    string signalFile = "signal"+to_string(i)+".txt";
    ofstream signal(signalFile);
    string noiseFile = "noise"+to_string(i)+".txt";
    ofstream noise(noiseFile);
    
    for(auto itr = source.begin();itr != source.end(); itr++)
    {
        if(itr->bad)
            noise<<itr->timeStamp<<","<<itr->price<<","<<itr->volume<<"\n";
        else
            signal<<itr->timeStamp<<","<<itr->price<<","<<itr->volume<<"\n";
    }
}

#endif
