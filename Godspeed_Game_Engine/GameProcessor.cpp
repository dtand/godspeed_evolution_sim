//
//  GameProcessor.cpp
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 3/29/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "GameProcessor.h"

//Calls creation function
GameProcessor::GameProcessor()
{
    try
    {
        create();
    }
    catch(std::exception e)
    {
        SDL_Log(e.what());
    }
}

//Creates all necessary graphic components
void GameProcessor::create()
{
    
    //Initialize components
    initSDL();
    initWindow();
    initRenderer();
    
    //Create our main event for rendering loop, key detection, etc
    mainEvent = new SDL_Event();
}

void GameProcessor::initSDL()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        throw "ERROR: could not initialize everything";
    }
}

void GameProcessor::initWindow()
{
    //Create window with passed in width and height
    window = nullptr;
    window = SDL_CreateWindow("Godspeed Game Engine", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    //Check window
    if (window == nullptr)	//Error checking for window
    {
        throw "ERROR: could not create window properly";
    }
}

void GameProcessor::initRenderer()
{
    //Create main renderer for program
    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if(renderer == nullptr)
    {
        throw "ERROR: issues initializing renderer";
    }
}

//Runs the event and clears the screen and draws all objects that are visible
void GameProcessor::begin( )
{
    SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer);
}

void GameProcessor::present(std::vector<GameObject *> gameObjects, unsigned int numObjects)
{
    
    for( int i = 0; i < numObjects; i++ )
    {
        GameObject* gameObject = gameObjects[ i ];
        if( gameObject->getVisibility( ) ) gameObject->draw(renderer);
    }
}

//presents all updates
void GameProcessor::end()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

//Clean up -> calls destroy
GameProcessor::~GameProcessor()
{
    destroy();
}

//Deallocates all allocated variables
void GameProcessor::destroy()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete mainEvent;
}


