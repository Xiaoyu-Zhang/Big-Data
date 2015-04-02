//
//  testNormalGenerator.cpp
//  dataGenerate
//
//  Created by Xiaoyu Zhang on 2/28/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#include <stdio.h>
#include "normalGenerator.hpp"

int main()
{
    for(int i = 0; i < 100; i ++)
        cout<<normalGenerator()<<endl;
    cout<<endl<<endl<<endl;
    for(int i = 0; i < 100; i ++)
        cout<<normalGenerator()<<endl;
    return 0;

    
}