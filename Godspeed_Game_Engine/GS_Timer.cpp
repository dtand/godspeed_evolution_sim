//
//  GS_Timer.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "GS_Timer.h"

//Deafult sets everything to zero and false
GS_Timer::GS_Timer()
{
    currentMilliseconds = 0;
    endTime = 0;
    
    hasStarted = false;
}

//Explicit construcor given a desired end time
GS_Timer::GS_Timer(const int passedEndTime)
{
    currentMilliseconds = 0;
    endTime = passedEndTime;
    
    hasStarted = false;
}

//Internal function, starts timing processes givin
//a desired end time
void GS_Timer::_startTimer(int passedEndTime)
{
    endTime = passedEndTime;
    currentMilliseconds = SDL_GetTicks() + passedEndTime;
    hasStarted = true;
}

//Internal function returns true if time is
//reached false if not
bool GS_Timer::_checkTimer()
{
    if (SDL_GetTicks() >= currentMilliseconds)
    {
        currentMilliseconds = SDL_GetTicks();
        hasStarted = false;
        return true;
    }
    else
    {
        return false;
    }
}

//Assumes timer was constructed with given
//end time
bool GS_Timer::process()
{
    return process(endTime);
}

//Runs all timing processes for the user
//returns true when desired time is reached,
//returns falls if desired time is not reached
//(in milliseconds)
bool GS_Timer::process(const int passedEndTime)
{
    if(!hasStarted)
    {
        _startTimer(passedEndTime);
    }
    else
    {
        return _checkTimer();
    }
    
    return false;
}

//resets the timing, good use
//for animating things
void GS_Timer::reset()
{
    _startTimer(endTime);
}

//If the user wants to change the end time upon
//a given event
void GS_Timer::setEndTime(const int passedEndTime)
{
    endTime = passedEndTime;
}






