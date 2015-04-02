//
//  normalGenerator.hpp
//  dataGenerate
//
//  Created by Xiaoyu Zhang on 2/28/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef dataGenerate_normalGenerator_hpp
#define dataGenerate_normalGenerator_hpp

#include <iostream>
#include <chrono>
#include <random>

using namespace std;

double normalGenerator()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    
    std::normal_distribution<double> distribution (0.0,1.0);
    
    return distribution(generator);
}

#endif
