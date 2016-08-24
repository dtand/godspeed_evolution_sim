//
//  MatingPool.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 8/22/16.
//  Copyright (c) 2016 Daniel Anderson. All rights reserved.
//

#include "MatingPool.h"

MatingPool::MatingPool( Game *pGame )
{
    game = pGame;
    matingHandler = new MatingHandler( game );
    totalFitness = 0;
}

void MatingPool::makeChildren(int& population, std::vector<Individual*>& individuals, RandomNumberGenerator rand)
{
    std::cout << "===== INITIATE MATING POOL =====" << std::endl;
    std::vector<int> pool = calculatePool(population, individuals);
    unsigned max = static_cast<int>( pool.size() - 1 );
    int end = population;

    for (int i = 0; i < end; i++)
    {
        population++;
        int firstParent  = pool.at( rand.getRandomNum(0, max) );
        int secondParent = pool.at( rand.getRandomNum(0, max) );
        Individual child = matingHandler->breed( individuals.at( firstParent ),
                                                 individuals.at( secondParent ),
                                                 population );
        int x = rand.getRandomNum( 0, game->getWindow()->getDimmensions().w );
        int y = rand.getRandomNum( 0, game->getWindow()->getDimmensions().h );
        
        child.setPosition( x, y );
        std::cout << "PARENT 1: " << individuals.at( firstParent ) << std::endl;
        std::cout << "PARENT 2: " << individuals.at( secondParent ) << std::endl;
        std::cout << "\tCHILD: " << child << std::endl;
        individuals.push_back( new Individual( child ) );
        game->registerGameObject( individuals.at(population-1), true );
    }
    
    
}

std::vector<int> MatingPool::calculatePool( int population, std::vector< Individual* >& individuals )
{
    float f_totalFitness = static_cast<float>(totalFitness);
    std::vector<int> pool;
    
    for ( int i = 0; i < population; i++ )
    {
        //Get the fitness of the individual as a float
        float f_fitness = static_cast<float>( individuals[ i ]->getFitness() );
        
        //Calculate the normalizes fitness and push it back
        float normalizedFitness = f_fitness / f_totalFitness;
        int intPercentage = static_cast<int>(normalizedFitness * 100);
        
        for (int j = 0; j < intPercentage; j++)
        {
            pool.push_back( i );
        }
    }
    
    return pool;
}