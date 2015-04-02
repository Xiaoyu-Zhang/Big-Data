//
//  uniformGenerator.hpp
//  dataGenerate
//
//  Created by Xiaoyu Zhang on 2/28/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef dataGenerate_uniformGenerator_hpp
#define dataGenerate_uniformGenerator_hpp

#include <iostream>
#include <random>
#include <chrono>
using namespace std;

double uniformGenerator()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution (0.0,1.0);
    return distribution(generator);
};

#endif
