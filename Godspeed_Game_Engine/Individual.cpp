//
//  Individual.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#include "Individual.h"
#include "GlobalFunctions.h"

Individual::Individual(Individual const &individual) : GameObject( individual )
{
    fitness = individual.fitness;
}

Individual::Individual( int pIndex, RandomNumberGenerator rand, Game* game )
{
    Individual();
    index = pIndex;
    decideFitnessRand( rand );
    decideColorRand( rand );
    decidePositionRandom( rand, game );
}

Individual::Individual( int pIndex, int pFitness, Game* game )
{
    Individual();
    index   = pIndex;
    fitness = pFitness;
}

void Individual::decideFitnessRand( RandomNumberGenerator rand )
{
    fitness = rand.getRandomNum( INIT_MIN_FITNESS, INIT_MAX_FITNESS );
}

void Individual::decideColorRand( RandomNumberGenerator rand )
{
    color.r   = static_cast<Uint8>( rand.getRandomNum( ColorConstants::MIN_VALUE, ColorConstants::MAX_VALUE ) );
    color.g   = static_cast<Uint8>( rand.getRandomNum( ColorConstants::MIN_VALUE, ColorConstants::MAX_VALUE ) );
    color.b   = static_cast<Uint8>( rand.getRandomNum( ColorConstants::MIN_VALUE, ColorConstants::MAX_VALUE ) );
}

void Individual::decidePositionRandom( RandomNumberGenerator rand, Game* game )
{
    SDL_Rect rect = game->getWindow()->getDimmensions();
    position.x    = rand.getRandomNum(0, rect.w);
    position.y    = rand.getRandomNum(0, rect.h);
}

std::ostream& operator<<(std::ostream& os, const Individual& individual)
{
    os << "ID: " << individual.index << ", FITNESS: " << individual.fitness;
    return os;
}
