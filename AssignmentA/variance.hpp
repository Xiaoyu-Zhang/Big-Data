//
//  variance.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef variance_hpp
#define variance_hpp

#include "storeData.hpp"
#include "mean.hpp"

float variance(vector<tick> & source)
{
    float average = mean(source);
    float variance = 0;
    
    for(auto itr = source.begin();itr != source.end(); itr++)
    {
        variance += (itr->price-average)*(itr->price-average);
    }
    variance /= source.size();
    return variance;
}



#endif
