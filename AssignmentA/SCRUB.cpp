//
//  SCRUB.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#include "scrub.hpp"
#include <thread>
#include "logging.hpp"
#include <cstdio>

using namespace std;

static const int numThreads = 10;
//static vector<string> info;

int main(int argc, char* argv[])		//data.txt; # of threads
{
	//int numThreads = 10;
	
	//step 1: Parse cmd line args
    /*
	switch (argc) {
		case 2:
			// argv[1] is the data filename
			break;
		case 3:
			// argv[1] is the data filename
			// Parse for num threads
			break;
		default:
			cout << "Invoke like this: scrub data.txt [-N NumThreads]" << endl;
			exit(1);
	}
	*/
   // string s = "/Users/xiaoyu/Programming/C++/BDiF/SCRUB/data10k.txt";
    
    
    char* name;
    name = argv[1];
    cout<<name<<endl;
    //ifstream inFile = readFile(name);
    string* info = new string[numThreads];
    thread thread[numThreads];
    // Launch threads.
    for (int i = 0; i < numThreads; ++i)
    {
        thread[i] = std::thread(scrub,name,i,numThreads);
    }
    cout << numThreads << " threads launched." << endl;
    // Join threads to the main thread of execution.
    for (int i = 0; i < numThreads; ++i)
    {
        thread[i].join();
    }
    /*
    ofstream logFile("LogFile.txt");
    for(auto itr = info->begin();itr != info->end(); itr++)
    {
        logFile<<*itr<<endl;
    }
    logFile.close();
     */
    /*
    for(auto itr = info->begin(); itr != info->end();itr++)
    {
        cout<<*itr<<endl;
    }
    */
    ofstream noise("noise.txt");
    ofstream signal("signal.txt");
    
    for(int i = 0; i < numThreads; i++)
    {
        string signalFile = "signal"+to_string(i)+".txt";
        ifstream signal_part(signalFile);
        string noiseFile = "noise"+to_string(i)+".txt";
        ifstream noise_part(noiseFile);
        noise<<noise_part.rdbuf();
        signal<<signal_part.rdbuf();
        signal_part.close();
        noise_part.close();
        remove(&signalFile[0]);
        remove(&noiseFile[0]);
        
    }
    

    
    //logging(info);
    // Even though threads ran independently and asynchronously,
    // output the results as though they had run in serial fashion.
    /*
    for (int i = 0; i<numThreads; i++)
        cout << output[i];
    */
    //scrub(inFile,2,10);
    
    
	//step 2: Start reading the data
	//step 3: Rules
	//step 4: Write
	//ifstream myfile;
    //myfile = readFile(argv[0]);
    
    //cout<<"hello"<<endl;
	
	//example.msecond = stoi(timeStamp.substr(24,6));
	//istringstream (timeStamp); 
	//char temp;
	//timeStamp >> example.year >> temp >> example.month >> temp >> example.day >> temp >> example.hour >> temp >> temp >> example.minute >>temp >>  example.second>> temp >>  example.msecond;

	//getline ( myfile, price, ',' );
	//example.price = stof(price);
	//getline ( myfile, volume, ',' );
	//example.volume = stoi(volume);

	
	//myfile.close();
	return 0;


}
