//
//  markData.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef markData_hpp
#define markData_hpp
#include "mean.hpp"
#include "variance.hpp"
#include <cmath>

void markData(vector<tick> & source)
{
    float average = mean(source);
    float deviation = sqrt(variance(source));
    for(auto itr = source.begin(); itr != source.end(); itr++)
    {
        
        if(itr->timeStamp == (itr-1)->timeStamp)
            itr->bad = true;
        else if(itr->price<0)
        {
            itr->bad = true;
        }
        else if(abs(itr->price-average)> 3*deviation)
        {
            itr->bad = true;
        }
    }
}


#endif
