//
//  tick.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef TICK_HPP
#define TICK_HPP

#include <stdio.h>
#include <string>
using namespace std;
// Each just 1 byte. Saves 9 bytes for struct tick.
//typedef unsigned char Hour;
//typedef unsigned char Minute;
//typedef unsigned char Second;


struct tick
{
    string timeStamp;

	float price;
	int volume;

	bool bad = false;
    
    void print()
    {
        cout<<"timestamp"<<timeStamp<<endl;
        cout<<"price"<<price<<endl;
        cout<<"volume"<<volume<<endl;
    };
    
    
};

bool comp(tick& a, tick& b)
{
    string date_a, date_b;
    string hour_a, hour_b;
    string minute_a, minute_b;
    string second_a, second_b;
    
    date_a = a.timeStamp.substr(0,8);
    //cout<<stoi(timeStamp.substr(0,8))<<endl;
    hour_a = a.timeStamp.substr(9,2);
    //cout<<(stoi(timeStamp.substr(9,2)))<<endl;
    //strcpy(&(example.hour),timeStamp.substr(9,2));
    //cout<<stoi(timeStamp.substr(9,2))<<endl;
    minute_a = a.timeStamp.substr(12,2);
    second_a = a.timeStamp.substr(15,9);
    //msecond_a = stoi(a.timeStamp.substr(18,6));
    
    date_b = b.timeStamp.substr(0,8);
    hour_b = b.timeStamp.substr(9,2);
    minute_b = b.timeStamp.substr(12,2);
    second_b = b.timeStamp.substr(15,9);
    //cout<<date_a<<endl;
    //cout<<date_b<<endl;
    //msecond_b = stoi(b.timeStamp.substr(18,6));
    string time_a;
    string time_b;
    time_a = date_a + hour_a + minute_a + second_a;
    time_b = date_b + hour_b + minute_b + second_b;
    return (time_a<time_b);
    /*
    if(date_a < date_b)
        return true;
    else if(date_a > date_b)
        return false;
    else if(hour_a < hour_b)
        return true;
    else if(hour_a > hour_b)
        return false;
    else if(minute_a < minute_b)
        return true;
    else if(minute_a > minute_b)
        return false;
    else if(second_a < second_b)
        return true;
    else if(second_a > second_b)
        return false;
    //else if(msecond_a < msecond_b)
        //return true;
    //else if(msecond_a > msecond_b)
        //return false;
    else
        return true;
    */
};

bool equality(tick& a, tick& b)
{
    if(a.timeStamp == b.timeStamp)
        return true;
    else
        return false;
};



#endif
