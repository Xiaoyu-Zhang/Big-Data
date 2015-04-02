//
//  swapDealValue.hpp
//  calculateCVA
//
//  Created by Xiaoyu Zhang on 3/7/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef calculateCVA_swapDealValue_hpp
#define calculateCVA_swapDealValue_hpp
#include "swapDeal.hpp"
#include "pathGenerate.hpp"

double swapDealValue(path& source_path, swap& source_swap, int step, double T,double hazard)
{
    double value = 0;
    double deltaT = T/step;
    for(int i = 0; i < step; i++)
    {
        value += exp(-source_path.interestRate.rate[i])*source_swap.notional*(source_swap.rate-source_path.interestRate.rate[i])*defaultProb(hazard,i*deltaT);
    }
    if(source_swap.LongorShort)
        return value;
    else
        return -value;
}


#endif
