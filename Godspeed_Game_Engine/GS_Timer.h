//
//  GS_Timer.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__GS_Timer__
#define __Godspeed_Game_Engine__GS_Timer__

#include <stdio.h>
#include "godspeed1.h"

class GS_Timer
{
private:
    //Integer values to keep track of timer
    int endTime;
    int currentMilliseconds;
    
    //Keeps track of timing status
    bool hasStarted;
    
    //Internal functions for timer processing
    void _startTimer(const int endTime);
    bool _checkTimer();
    
public:
    //User constructors
    GS_Timer();
    GS_Timer(const int endTime);
    
    //Main processing functions
    bool process();
    bool process(const int endTime);
    void reset();
    void setEndTime(const int endTime);
    
};

#endif /* defined(__Godspeed_Game_Engine__GS_Timer__) */
