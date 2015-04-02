//
//  fxDeal.hpp
//  dataGenerate
//
//  Created by Xiaoyu Zhang on 2/28/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef dataGenerate_fxDeal_hpp
#define dataGenerate_fxDeal_hpp

#include "uniformGenerator.hpp"
#include "normalGenerator.hpp"

class fxDeal
{
public:
    double notional;
    bool longOrShort;
    double t=0;
public:
    fxDeal(double notional_, bool longorShort_): notional(notional_) , longOrShort(longorShort_){};

};

fxDeal fxDealGenerator()
{
    bool LongorShort;
    double Notional;
    
    Notional=800000.0+400000.0*uniformGenerator();
    
    if (uniformGenerator()<0.4)
        LongorShort=false;
    else
        LongorShort=true;
    
  
    
    return fxDeal(Notional,LongorShort);
    
}



#endif
