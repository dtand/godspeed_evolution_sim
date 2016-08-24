//
//  MatingHandler.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__MatingHandler__
#define __Godspeed_Game_Engine__MatingHandler__

#include <stdio.h>
#include "Individual.h"
#include "RandomNumberGenerator.h"

class MatingHandler
{
    
private:
    constexpr const static float MUTATION_PROBABILITY = .02;
    Game* game;
    bool mutationTable[100];
    
public:
    MatingHandler( Game* pGame );
    
    Individual breed( Individual* lParent, Individual* rParent, int index );
    
private:
    Individual crossover( Individual* lParent, Individual* rParent, int index );
    void mutation( Individual* child);
    
};

#endif /* defined(__Godspeed_Game_Engine__MatingHandler__) */
