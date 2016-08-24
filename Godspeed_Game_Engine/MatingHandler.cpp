//
//  MatingHandler.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#include "MatingHandler.h"

MatingHandler::MatingHandler( Game* pGame )
{
    game = pGame;
    
    int end = MUTATION_PROBABILITY * 100;
    for (int i = 0; i < 100; i++)
    {
        if( i < end ) mutationTable[ i ] = true;
        else mutationTable[ i ]          = false;
    }
    
}

Individual MatingHandler::breed( Individual* lParent, Individual* rParent, int index )
{
    Individual child( crossover(lParent, rParent, index ) );
    mutation( &child );
    return child;
}

Individual MatingHandler::crossover( Individual* lParent, Individual* rParent, int index )
{
    int avgFitness = ( lParent->getFitness()   + rParent->getFitness() ) / 2;
    int avgRed     = ( lParent->getColor().r   + rParent->getColor().r ) / 2;
    int avgBlue    = ( lParent->getColor().b   + rParent->getColor().b ) / 2;
    int avgGreen   = ( lParent->getColor().g   + rParent->getColor().g ) / 2;
    Individual individual( index, avgFitness, game );
    individual.setColor(avgRed, avgBlue, avgGreen);
    return individual;
}

void MatingHandler::mutation( Individual* child )
{
    RandomNumberGenerator rand;
    if ( mutationTable[ rand.getRandomNum(0, 99)] )
    {
        child->setFitness( rand.getRandomNum( Individual::MIN_FITNESS, Individual::MAX_FITNESS ) );
    }
}