//
//  outputting.hpp
//  NORMAL
//
//  Created by Xiaoyu Zhang on 2/15/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef outputting_hpp
#define outputting_hpp

void outputting(string& info)
{
    ofstream logFile;
    logFile.open("output.txt",ios::out||ios::app);
    /*
     for(auto itr = info.begin();itr != info.end(); itr++)
     {
     logFile<<*itr;
     }
     */
    logFile<<info<<"\n";
    //cout<<info<<endl;
    logFile.close();
};

#endif
