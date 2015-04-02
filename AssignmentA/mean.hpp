//
//  stats.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef mean_hpp
#define mean_hpp

#include "storeData.hpp"

float mean(vector<tick> & source)
{
    float mean = 0;
    for(auto itr = source.begin();itr != source.end(); itr++)
    {
        mean += itr->price;
    }
    mean /= source.size();
    return mean;
}


#endif
