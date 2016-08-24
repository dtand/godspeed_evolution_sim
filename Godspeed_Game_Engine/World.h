//
//  World.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__World__
#define __Godspeed_Game_Engine__World__

#include <stdio.h>
#include <vector>
#include "Individual.h"
#include "GS_Timer.h"
#include "MatingPool.h"

class World
{
private:
    
    //Constant parameters
    static const int INIT_POP_MIN = 1;
    static const int INIT_POP_MAX = 5;
    static const int TIME_PER_IND = 500;
    static const int SECS_PER_DAY = 60;
    static const int MATING_DAY   = 3;
    
    Game* game;
    
    //World time
    int day;
    GS_Timer dayTimer;
    RandomNumberGenerator randNum;
    
    
    //Population factors
    int population;
    std::vector<Individual*> individuals;
    MatingPool* matingPool;
    
public:
    World( Game* pGame );
    ~World();
    void update();
    
private:
    void populateWorld();
    void showBirthMessage( Individual* individual );
    
};

#endif /* defined(__Godspeed_Game_Engine__World__) */
