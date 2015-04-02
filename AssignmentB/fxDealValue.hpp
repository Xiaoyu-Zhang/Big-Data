//
//  fxDealValue.hpp
//  calculateCVA
//
//  Created by Xiaoyu Zhang on 3/7/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef calculateCVA_fxDealValue_hpp
#define calculateCVA_fxDealValue_hpp
#include "fxDealValue.hpp"

double fxDealValue(path& source_path, fxDeal& source_fxDeal, int step, double T)
{
    double x0 = source_path.exchangeRate.exchange[0];
    double deltaT = T/step;
    double value = 0;
    for(int i = 1; i < step; i++)
    {
        value += (source_path.exchangeRate.exchange[i] - x0)*source_fxDeal.notional*exp(-source_path.interestRate.rate[i])*defaultProb(hazard,i*deltaT)
    }
    return value;
}


#endif
