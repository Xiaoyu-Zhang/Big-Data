//
//  statistic.hpp
//  AssignmentC
//
//  Created by Xiaoyu Zhang on 3/22/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef AssignmentC_statistic_hpp
#define AssignmentC_statistic_hpp

#include <math.h>
#include "mpi.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//using namespace std;

std::vector<double> statistic(std::string fileName) {
    MPI_Status mpiStatus;
    int mpiRank, mpiSize;
    mpiSize = MPI::COMM_WORLD.Get_size();
    mpiRank = MPI::COMM_WORLD.Get_rank();
    

    std::ifstream inputFile(fileName);
    inputFile.seekg(0, inputFile.end);
    long fileLength = inputFile.tellg();
    long seperateLength = fileLength / mpiSize;
    long position = seperateLength * mpiRank;
    //inputFile.close();
    
    std::ifstream readFile;
    readFile.open(fileName);
    readFile.seekg(position);
    
    double average = 0;
    double square = 0;
    std::string tempTime;
    std::string tempString;
    double value;
    int index = 0;
    long endPosition = seperateLength * (mpiRank + 1) - 2;
    while (readFile.tellg() <= endPosition) {
        getline(readFile, tempTime, ',');
        readFile >> value;
        getline(readFile, tempString);
        average = (index * average + value) / (index + 1);
        square = (index * square + value * value) / (index + 1);
        index++;
    }
    
    std::vector<double> result(2);
    std::vector<double> tempResult(2);
    tempResult[0] = average;
    tempResult[1] = square;
    
    if (mpiRank == 0) {
        for (int i = 1; i < mpiSize; i++) {
            MPI_Recv(&tempResult, 2, MPI_DOUBLE, i, 0, MPI_COMM_WORLD,
                     &mpiStatus);
            average += tempResult[0];
            square += tempResult[1];
        }
        average = average / mpiSize;
        square = square / mpiSize;
        readFile.close();
    } else {
        MPI_Send(&tempResult, 2, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    
    double variance = sqrt(square - average * average);
    result[0] = average;
    result[1] = variance;
    
    return result; 
    
}


#endif
