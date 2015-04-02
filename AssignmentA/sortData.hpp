//
//  sortData.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef sortData_hpp
#define sortData_hpp

#include <vector>
#include "tick.hpp"
#include <algorithm>

using namespace std;

void sortData(vector<tick> & source)
{
    //cout<<source.size()<<endl;
    sort(source.begin(), source.end(), comp);
    /*
    for(auto itr = source.begin();itr != source.end(); itr++)
    {
        itr->print();
        cout<<endl;
    }
     */
}

#endif
