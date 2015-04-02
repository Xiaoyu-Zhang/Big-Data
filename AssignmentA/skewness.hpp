//
//  skewness.hpp
//  NORMAL
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef skewness_hpp
#define skewness_hpp

#include <cmath>
#include <vector>
#include "tick.hpp"
#include "variance.hpp"
//#include "mean.hpp"

using namespace std;

float skewness(vector<tick> & source)
{
    float average = mean(source);
    float var = variance(source);
    float skewness = 0;
    for(auto itr = source.begin();itr != source.end(); itr++)
    {
        skewness += (itr->price-average)*(itr->price-average)*(itr->price-average);
    }
    skewness /= source.size();
    skewness /= pow(var,3.0/2);
    return skewness;
}


#endif
