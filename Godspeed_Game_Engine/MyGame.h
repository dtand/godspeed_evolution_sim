//
//  MyGame.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__MyGame__
#define __Godspeed_Game_Engine__MyGame__

#include <stdio.h>
#include "Game.h"
#include "World.h"

class MyGame : public Game 
{
private:
    World* world;
    
public:
    MyGame() : Game()
    {
        setup();
    }
    
    MyGame(const int width, const int height): Game(width, height)
    {
        MyGame();
    }
    
    ~MyGame(){ delete world; }
    
    //Overridden functions
    void play();
    void setup();
    
};

#endif /* defined(__Godspeed_Game_Engine__MyGame__) */