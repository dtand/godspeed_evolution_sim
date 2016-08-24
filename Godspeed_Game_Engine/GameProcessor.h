//
//  GameProcessor.h
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 3/29/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//
/*
 
 This class is the core rapper for the graphics 
 library SDL 2.0.3 used for rendering and
 handling graphics.  Credits for this library
 go to developer Sam Lantinga aka Slouken
 
 -------------------------------------
 Godspeed Gaming Engine is a subset of
 classes and templates used for creating
 2D games.  The goal of this engine is to 
 simplify the game creation process by 
 providing an interface that is intuitive 
 and easy to use for those with a good
 background in OOP design.  This is an
 open source engine and may be used for
 personal production and release given
 credit be contributed to Daniel Anderson.
 Godspeed.
 
 */

#ifndef __Godspeed_Engine__GameProcessor__
#define __Godspeed_Engine__GameProcessor__
#include "godspeed1.h"
#include "GameObject.h"


class GameProcessor
{
    
private:
    
    //Main processor components
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *mainEvent;
    
    void initSDL();
    void initWindow();
    void initRenderer();
    
public:
    
    //Creators
    GameProcessor();
    void create();
    
    //Destroyers
    ~GameProcessor();
    void destroy();
    
    //Processor functions
    void begin();
    void present(std::vector<GameObject*> gameObjects, unsigned int numObjects);
    void end();
    
    //Getters for important game components
    SDL_Window* getWindow() {return window;}
    SDL_Renderer* getRenderer(){return renderer;}
    SDL_Event* getMainEvent(){return mainEvent;}
};



#endif /* defined(__Godspeed_Engine__GameProcessor__) */
