//
//  pathGenerate.hpp
//  calculateCVA
//
//  Created by Xiaoyu Zhang on 3/7/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef calculateCVA_pathGenerate_hpp
#define calculateCVA_pathGenerate_hpp

#include "curveGenerate.hpp"
#include "exchangeRateGenerate.hpp"

class path
{
private:
    interestCurve interestRate;
    exchangeCurve exchangeRate;
};

path pathGenerate(double alpha_interest, double x_bar_interest,double sigma_interest, int step, double T, double sigma_exchange)
{
    path temp;
    interestCurve temp_interest = interestCurveGenerate();
    exchangeCurve temp_exchange = exchangeRateGenerare();
    temp.interestRate = temp_interest;
    temp.exchangeRate = temp_exchange;
    return temp;
}
#endif
