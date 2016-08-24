//
//  GS_StopWatch.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 4/4/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "GS_StopWatch.h"
GS_StopWatch::GS_StopWatch()
{
    currentMilliseconds = 0;
    millisecondsPassed = 0;
    isRunning = false;
}

void GS_StopWatch::_calculateMilliPassed()
{
    millisecondsPassed = SDL_GetTicks() - currentMilliseconds;
}

//Starts the stop watch
void GS_StopWatch::start()
{
    currentMilliseconds = SDL_GetTicks() - currentMilliseconds;
    isRunning = true;
}


void GS_StopWatch::stop()
{
    _calculateMilliPassed();
    isRunning = false;
}

void GS_StopWatch::reset()
{
    millisecondsPassed = 0;
    currentMilliseconds = 0;
    isRunning = false;
}

int GS_StopWatch::getSecondsPassed()
{
    if (isRunning)
    {
        _calculateMilliPassed();
    }
    
    return floor(millisecondsPassed / 1000);
    
}

int GS_StopWatch::getMilliPassed()
{
    if (isRunning)
    {
        _calculateMilliPassed();
    }
    
    return millisecondsPassed;
}


