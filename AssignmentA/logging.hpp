//
//  logging.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef logging_hpp
#define logging_hpp

void logging(string& info)
{
    ofstream logFile;
    logFile.open("LogFile.txt",ios::out||ios::app);
    /*
    for(auto itr = info.begin();itr != info.end(); itr++)
    {
        logFile<<*itr;
    }
     */
    logFile<<info<<"\n";
    cout<<info<<endl;
    logFile.close();
};


#endif
