//
//  generateData.hpp
//  dataGenerate
//
//  Created by Xiaoyu Zhang on 2/28/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef dataGenerate_generateData_hpp
#define dataGenerate_generateData_hpp

#include "counterpartyGenerator.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void dataGenerate(int couterpartyNumber, int swapDealNumber, int fxDealNumber) {
    
//int counterpartyNumber = 10;
    
    for(int i = 1; i <= couterpartyNumber; i++)
    {
        ostringstream outfilename;
        outfilename<<"bigdata_";
        outfilename<<i;
        outfilename<<".txt";
        std::ofstream outfile(outfilename.str());
        //outfile.open(outfilename.str().c_str(), std::ios::out | std::ios::app);
        if(outfile.is_open())
            cout<<"Yes"<<endl;
        counterParty tempCP=counterPartyGenerator();
        outfile<<tempCP.level<<endl;
        
        int n;
        if(tempCP.level == 'A')
            n = uniformGenerator()*swapDealNumber*1;
        else if(tempCP.level == 'B')
            n = uniformGenerator()*swapDealNumber*2;
        else if(tempCP.level == 'C')
            n = uniformGenerator()*swapDealNumber*4;
        else if(tempCP.level == 'D')
            n = uniformGenerator()*swapDealNumber*8;
        else if(tempCP.level == 'E')
            n = uniformGenerator()*swapDealNumber*16;

        for(int j = 0; j<n; j++)
        {
        if(uniformGenerator()<0.5)
        {
            swapDeal tempSwapDeal = swapDealGenerator();
            outfile<<"SwapDeal,"<<tempSwapDeal.Notional<<","<<tempSwapDeal.T<<","<<tempSwapDeal.Currency<<","<<tempSwapDeal.LongorShort<<","<<tempSwapDeal.rate<<endl;
   
        }
        else
        {
            fxDeal tempFXDeal = fxDealGenerator();
            outfile<<"FXDeal,"<<tempFXDeal.notional<<","<<tempFXDeal.longOrShort<<","<<endl;
        }
        
        }
        //cout<<i<<endl;
        outfile.close();
    }
    
}

#endif
