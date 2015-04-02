//
//  generateData.hpp
//  AssignmentC
//
//  Created by Xiaoyu Zhang on 3/22/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef AssignmentC_generateData_hpp
#define AssignmentC_generateData_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;

void generateData(string fileName1, string fileName2)
{
    
    ifstream inputFile(fileName1);
    ofstream outputFile(fileName2);
    
    if(inputFile)
        cout<<"Successfully Open the File"<<endl;
    else
        cout<<"Failed"<<endl;
    string tempTime;
    string tempString;
    double value;
    string tempTime2;
    
    default_random_engine generator;
    normal_distribution<double> distribution(0,0.1);

    
    
    while (!inputFile.eof()) {
        getline(inputFile, tempTime, ',');
        inputFile >> value;
        getline(inputFile, tempString);
        outputFile << tempTime;
        outputFile << ",";
        outputFile << value;
        outputFile << endl;
        for(int i = 0; i < 24; i++)
        {
            
            tempTime2 = tempTime.substr(0,11);
            tempTime2 += to_string(i);
            tempTime2 += tempTime.substr(12);
            outputFile << tempTime2;
            outputFile << ",";
            value = value + distribution(generator);
            outputFile << fixed << setprecision(2)<< value;
            outputFile << endl;
            
        }
    }
    inputFile.close();
    outputFile.close();
}

#endif
