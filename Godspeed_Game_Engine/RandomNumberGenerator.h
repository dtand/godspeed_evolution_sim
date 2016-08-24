//
//  RandomNumberGenerator.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__RandomNumberGenerator__
#define __Godspeed_Game_Engine__RandomNumberGenerator__

#include "godspeed1.h"
#include <stdio.h>
#include <stdlib.h>

class RandomNumberGenerator
{
private:
    int randomNum;
    
public:
    RandomNumberGenerator( )
    {
        srand ( time( NULL ) );
    }
    
    int getRandomNum( int min, int max )
    {
        if( max == 0 ) return -1;
        randomNum = rand() % max + min;
        return randomNum;
    }
};

#endif /* defined(__Godspeed_Game_Engine__RandomNumberGenerator__) */
