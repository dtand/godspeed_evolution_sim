//
//  Individual.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__Individual__
#define __Godspeed_Game_Engine__Individual__

#include <stdio.h>
#include <iostream>
#include "RandomNumberGenerator.h"
#include "Game.h"

struct ColorConstants
{
    const static int MAX_VALUE = 230;
    const static int MIN_VALUE = 20;
};

class Individual : public GameObject
{
    friend std::ostream& operator<<(std::ostream& os, const Individual& individual);
    
private:
    const static int INIT_MIN_FITNESS = 5;
    const static int INIT_MAX_FITNESS = 20;
    
    //DNA
    int fitness;
public:
    const static int MAX_FITNESS = 100;
    const static int MIN_FITNESS = 5;
    
    Individual() : GameObject() {}
    Individual(const Individual& individual);
    Individual( int pIndex, RandomNumberGenerator rand, Game* game );
    Individual( int pIndex, int pFitness, Game* game );
    void updateFitness( int pFitnes ){ fitness += pFitnes; }
    void setFitness( int pFitness ){ fitness = pFitness; }
    int getFitness(){ return fitness; }
    
    
private:
    void decideFitnessRand( RandomNumberGenerator rand );
    void decideColorRand( RandomNumberGenerator rand );
    void decidePositionRandom( RandomNumberGenerator rand, Game* game );
    
};

#endif /* defined(__Godspeed_Game_Engine__Individual__) */
