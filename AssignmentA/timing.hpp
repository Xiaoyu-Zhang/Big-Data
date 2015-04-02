//
//  timing.hpp
//  SCRUB
//
//  Created by Xiaoyu Zhang on 2/13/15.
//  Copyright (c) 2015 Xiaoyu Zhang. All rights reserved.
//

#ifndef timing_hpp
#define timing_hpp

#include <chrono>
#include <random>

// Needed to time things.
#define START_TIMER  std::chrono::system_clock::time_point t0 = \
std::chrono::system_clock::now();
#define END_TIMER    std::chrono::system_clock::time_point t1 = \
std::chrono::system_clock::now();
#define ELAPSED_TIME_MS \
std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
#define ELAPSED_TIME_NS \
std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()


#endif
