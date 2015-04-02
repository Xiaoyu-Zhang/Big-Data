//
//  main.cpp
//  AssignmentC
//
//  Created by Xiaoyu Zhang on 3/22/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#include <iostream>
#include <string>
#include "statistic.hpp"
#include "mpi.h"
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    
    MPI::Init(argc, argv);
    vector<double> originalResult;
    vector<double> generateResult;
    string originalFile = "data_original.csv";
    string generateFile = "data_generate.csv";
    originalResult = statistic(originalFile);
    generateResult = statistic(generateFile);
    MPI_Finalize();
}