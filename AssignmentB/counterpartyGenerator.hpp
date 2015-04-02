//
//  counterpartyGenerator.hpp
//  dataGenerate
//
//  Created by Xiaoyu Zhang on 2/28/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef dataGenerate_counterpartyGenerator_hpp
#define dataGenerate_counterpartyGenerator_hpp
#include <vector>
#include "swapDeal.hpp"
#include "fxDeal.hpp"

class counterParty
{
public:
    double hazardRate;
    char level;
    
    
public:
    counterParty(int level_) : level(level_)    {
        if(level == 'A')
            hazardRate = 0.02;
        else if(level  == 'B')
            hazardRate = 0.04;
        else if(level == 'C')
            hazardRate = 0.06;
        else if(level == 'D')
            hazardRate = 0.08;
        else if(level == 'E')
            hazardRate = 0.1;
    }
};

counterParty counterPartyGenerator()
{
    int level_rank;
    level_rank=int(uniformGenerator()/0.2)+1;
    char level;
    if(level_rank == 1)
        level = 'A';
    else if(level_rank == 2)
        level = 'B';
    else if(level_rank == 3)
        level = 'C';
    else if(level_rank == 4)
        level = 'D';
    else if(level_rank == 5)
        level = 'E';
    return counterParty(level);
}


#endif
