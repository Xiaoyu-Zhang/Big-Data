//
//  curveGenerate.hpp
//  calculateCVA
//
//  Created by Xiaoyu Zhang on 3/7/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef calculateCVA_curveGenerate_hpp
#define calculateCVA_curveGenerate_hpp

#include "normalGenerator.hpp"
#include <vector>

class interestCurve()
{
private:
    double alpha;
    double x_bar;
    double sigma;
    vector<double> rate;
public:
    interestCurve(double alpha_,double x_bar_,double sigma_):alpha(alpha_),x_bar(x_bar_),sigma(sigma_){};
    
}
interestCurve interestCurveGenerate(double alpha, double x_bar, int step, double T,double sigma)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(x_bar,1.0);
    interestCurve temp(alpha,x_bar,sigma);
    double deltaT = T/step;
    double tempRate;
    temp.rate[0] = x_bar;
    for(int i = 1; i < step; i++)
    {
        tempRate = alpha*(x_bar-temp.rate[i])+sigma*sqrt(deltaT)*distribution(generator);
        temp.rate[i] = tempRate;
    }
    return temp;
}
#endif
