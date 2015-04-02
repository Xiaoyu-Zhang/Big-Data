//
//  testUniformGenerator.cpp
//  dataGenerate
//
//  Created by Xiaoyu Zhang on 2/28/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#include <stdio.h>
#include "uniformGenerator.hpp"

using namespace std;

int main()
{
    for(int i = 0; i < 100; i ++)
        cout<<uniformGenerator()<<endl;
    cout<<endl<<endl<<endl;
    for(int i = 0; i < 100; i ++)
        cout<<uniformGenerator()<<endl;
    return 0;
}