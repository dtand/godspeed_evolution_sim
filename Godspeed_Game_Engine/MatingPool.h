//
//  MatingPool.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__MatingPool__
#define __Godspeed_Game_Engine__MatingPool__

#include <stdio.h>
#include <vector>
#include "Individual.h"
#include "MatingHandler.h"
#include "Game.h"

class MatingPool
{
private:
    Game *game;
    MatingHandler *matingHandler;
    int totalFitness;
    
public:
    MatingPool( Game *pGame );
    ~MatingPool(){ delete matingHandler; }
    void updateTotalFitness( int pFitness ){ totalFitness += pFitness; }
    void makeChildren(int& population, std::vector< Individual* >& individuals, RandomNumberGenerator rand);
    
private:
    std::vector<int> calculatePool( int population, std::vector< Individual* >& individuals);
    
};

#endif /* defined(__Godspeed_Game_Engine__MatingPool__) */
