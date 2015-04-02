//
//  readData.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef readData_hpp
#define readData_hpp
#include <string>
#include <iostream>
#include <fstream>
#include "tick.hpp"

using namespace std;

tick readData(ifstream& myfile)
{
    tick example;
    string time_Stamp;
    string price;
    string volume;
    getline(myfile, time_Stamp, ',' );
    example.timeStamp = time_Stamp;
    //cout<<timeStamp<<endl;
    //example.date = stoi(timeStamp.substr(0,8));
    //cout<<stoi(timeStamp.substr(0,8))<<endl;
    //example.hour = stoi(timeStamp.substr(9,2));
    //cout<<(stoi(timeStamp.substr(9,2)))<<endl;
    //strcpy(&(example.hour),timeStamp.substr(9,2));
    //cout<<stoi(timeStamp.substr(9,2))<<endl;
    //example.minute = stoi(timeStamp.substr(12,2));
    //example.second = stoi(timeStamp.substr(15,2));
    //example.m_second = stoi(timeStamp.substr(18,6));
    getline(myfile, price, ',');
    example.price = stof(price);
    getline(myfile, volume, '\n');
    example.volume = stoi(volume);
    //cout<<"hello"<<endl;
    
    return example;
    
}


#endif
