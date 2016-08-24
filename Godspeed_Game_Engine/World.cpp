//
//  World.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#include "World.h"
#include "GlobalFunctions.h"

World::World( Game* pGame )
{
    game = pGame;
    matingPool = new MatingPool( game );
    day = 1;
    dayTimer.setEndTime( SECS_PER_DAY * 100 );
    populateWorld( );
}

World::~World()
{
    delete matingPool;
    while( !individuals.empty() )
    {
        Individual* ind = individuals.at( individuals.size()-1 );
        delete ind;
        individuals.pop_back();
    }
}

/* Step 1: populate world with random individuals */
void World::populateWorld( )
{
    //Get a random number for the starting population
    population = randNum.getRandomNum( INIT_POP_MIN, INIT_POP_MAX );
    
    //Instantiate the first individual
    Individual* firstIndividual = new Individual( 1, randNum, game );
    individuals.push_back( firstIndividual );
    showBirthMessage( firstIndividual );
    matingPool->updateTotalFitness( firstIndividual->getFitness( ) );
    game->registerGameObject( firstIndividual, game );
    
    //Run a timer to instantiate individuals eon the
    //designated interval
    GS_Timer timer( TIME_PER_IND );
    int i = 1; while( i < population )
    {
        
        if( timer.process( ) )
        {
            Individual* individual = new Individual( i+1, randNum, game );
            individuals.push_back( individual );
            showBirthMessage( individual );
            matingPool->updateTotalFitness( individual->getFitness( ) );
            game->registerGameObject( individual, game );
            i++;
        }

    }
    
    std::cout << "DAY: 1" << std::endl;
    
}

/* Show all born individuals in console called each instantate step */
void World::showBirthMessage( Individual* individual )
{
    std::cout << "Entity " << individual->getIndex() << " has entered your world." << std::endl;
}

/* Performs all maintenance on our world */
void World::update()
{
    //Check if day has passed
    if( dayTimer.process( ) )
    {
        day++;
        std::cout << "DAY: " << day << std::endl;
        
        //Create new generation
        if( day % 3 == 0 )
        {
            matingPool->makeChildren( population, individuals, randNum );
        }
    }
}








