//
//  calculateCVA.hpp
//  calculateCVA
//
//  Created by Xiaoyu Zhang on 3/7/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef calculateCVA_calculateCVA_hpp
#define calculateCVA_calculateCVA_hpp

double calculateCVA(int counterpartyNumber, int step, double T)
{
    double value = 0;
    ostringstream outfilename;
    filename<<"bigdata_";
    filename<<couterpartyNumber;
    filename<<".txt";
    std::ifstream file(outfilename.str());
    double level;
    level = atoi(getline(file,','));
    while(file!=eof())
    {
        getline(file,',')
    }
    
    
    return value;
}

#endif
