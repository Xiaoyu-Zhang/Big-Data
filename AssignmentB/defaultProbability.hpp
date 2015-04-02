//
//  defaultProbability.hpp
//  calculateCVA
//
//  Created by Xiaoyu Zhang on 3/7/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef calculateCVA_defaultProbability_hpp
#define calculateCVA_defaultProbability_hpp

double defaultProb(double hazard,double T)
{
    return hazard*exp(-hazard*T);
    
}

#endif
