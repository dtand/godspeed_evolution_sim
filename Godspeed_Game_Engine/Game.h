//
//  Game.h
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 3/29/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Engine__Game__
#define __Godspeed_Engine__Game__
#include "GameObject.h"
#include "GameProcessor.h"
#include "Window.h"


//Main point of access
class Game
{
    
protected:
    
    //Knows when to stop main game loop
    bool quit;
    
    unsigned int numObjects;
    unsigned int maxObjects;
    std::vector<GameObject*> gameObjects;
    
    //Main game processor
    GameProcessor *gameProcessor;
    
    //Main game window
    Window *window;
    
    //Override play before running start
    virtual void play() = 0;
    
    //Override to setup initial conditions
    virtual void setup() = 0;
    
public:
    Game();
    Game(const int passedScreenWidth, const int passedScreenHeight);
    
    //Gives easy access to game processor, needed for all game objects
    virtual GameProcessor* getGameProcessor() final {return gameProcessor;}
    
    ~Game();
    void destroy();
    
    //Do not override start
    virtual void start() final;
    
    //Do not override this function or call it, use the register function
    virtual void registerGameObject( GameObject* gameObject, bool makeVisible ) final;
    
    //Getters for glabal methods
    std::vector<GameObject*> getGameObjects(){ return gameObjects; }
    unsigned int getNumObjects(){ return numObjects; }
    Window* getWindow(){ return window; }
};



#endif /* defined(__Godspeed_Engine__Game__) */
