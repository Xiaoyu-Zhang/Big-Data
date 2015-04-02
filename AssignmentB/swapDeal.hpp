//
//  swapDeal.hpp
//  dataGenerate
//
//  Created by Xiaoyu Zhang on 2/28/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef dataGenerate_swapDeal_hpp
#define dataGenerate_swapDeal_hpp
#include "uniformGenerator.hpp"
#include "normalGenerator.hpp"

class swapDeal
{
public:
    double Notional;
    double T;
    string Currency;
    bool LongorShort;
    float rate;
    double t=0;
    
public:
    swapDeal(double Notional_,double T_, string Currency_,bool LongorShort_,float rate_) : Notional(Notional_), T(T_), Currency (Currency_) , LongorShort(LongorShort_),rate(rate_) {};
};

swapDeal swapDealGenerator()
{
    double Notional;
    double T;
    string Currency;
    bool LongorShort;
    float rate;
    
    if (uniformGenerator()<0.5) Currency="USD";
    else Currency="EUR";
    
    if (uniformGenerator()<0.55) LongorShort=false;
    else LongorShort=true;
    T=2.0+int(uniformGenerator()*48.0);
    
    Notional=800000.0+400000.0*uniformGenerator();
    
    rate =0.2+uniformGenerator()*0.6;
    
    return swapDeal(Notional,T, Currency, LongorShort,rate);
    
    
}

#endif
