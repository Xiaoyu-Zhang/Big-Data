//
//  exchangeRateGenerate.hpp
//  calculateCVA
//
//  Created by Xiaoyu Zhang on 3/7/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef calculateCVA_exchangeRateGenerate_hpp
#define calculateCVA_exchangeRateGenerate_hpp

class exchangeCurve()
{
private:
    double drift;
    double sigma;
    double x0;
    vector<double> exchange;
public:
    interestCurve(double drift_,double x0_,double sigma_):alpha(alpha_),x0(x0_),sigma(sigma_){};
    
}

exchangeCurve exchangeRateGenerate(double drift,double x0,double sigma,int step, double T)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(x_bar,1.0);
    double deltaT = T/step;
    exchangeCurve temp(drift,x0,sigma);
    temp.exchange[0] = x0;
    for(int i = 0; i < step; i++)
    {
        temp.exchange[i] = temp.exchange[i-1]+sqrt(deltaT)*sigma*distribution(generator);
    }
    return temp;
}


#endif
