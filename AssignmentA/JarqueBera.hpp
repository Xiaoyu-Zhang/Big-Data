//
//  JarqueBera.hpp
//  NORMAL
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef JarqueBera_hpp
#define JarqueBera_hpp

#include "skewness.hpp"
#include "kurtosis.hpp"

#include <cmath>

using namespace std;
bool JarqueBera(vector<tick> & source)
{
    float skew = skewness(source);
    float  kurt = kurtosis(source);
    int n = source.size();
    float JB = (pow(skew,2)+pow(kurt-3,2)/4)*n/6;
    
    if(JB<0.1)
        return true;
    else
        return false;
}

#endif
