//
//  kurtosis.hpp
//  NORMAL
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef kurtosis_hpp
#define kurtosis_hpp

#include <cmath>
#include <vector>
//#include "mean.hpp"
#include "variance.hpp"

using namespace std;
float kurtosis(vector<tick> & source)
{
    float average = mean(source);
    float var = variance(source);
    float  kurtosis = 0;
    for(auto itr = source.begin();itr != source.end(); itr++)
    {
        kurtosis += pow(itr->price-average,4);
    }
    kurtosis /= source.size();
    kurtosis /= pow(var,2);
    return kurtosis;
}


#endif
