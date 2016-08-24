//
//  GS_StopWatch.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 4/4/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__GS_StopWatch__
#define __Godspeed_Game_Engine__GS_StopWatch__

#include "godspeed1.h"

class GS_StopWatch
{
private:
    int currentMilliseconds;
    int millisecondsPassed;
    bool isRunning;
    
    void _calculateMilliPassed();
    
public:
    GS_StopWatch();
    
    void start();
    void stop();
    void reset();
    
    int getSecondsPassed();
    int getMilliPassed();
    
};

#endif /* defined(__Godspeed_Game_Engine__GS_StopWatch__) */
