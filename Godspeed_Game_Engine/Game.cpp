//
//  Game.cpp
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 3/29/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "Game.h"

Game::Game()
{
    quit = false;
    numObjects = 0;
    maxObjects = 36;
    gameProcessor = new GameProcessor();
    window = new Window(gameProcessor);
}

Game::~Game()
{
    destroy();
}

Game::Game(int passedScreenWidth, int passedScreenHeight)
{
    gameProcessor = new GameProcessor();
    window = new Window(gameProcessor);
    window->setDimmensions(0, 0, passedScreenWidth, passedScreenHeight);
}

void Game::destroy()
{
    delete window;
    delete gameProcessor;
}

//Do not override start
void Game::start()
{
    while( !quit )
    {
        gameProcessor->begin( );
        play();
        gameProcessor->present(gameObjects, numObjects);
        gameProcessor->end();
    }
}

void Game::registerGameObject( GameObject* gameObject, bool makeVisible )
{
    gameObject->setVisable( makeVisible );
    gameObjects.push_back( gameObject );
    numObjects++;
}

