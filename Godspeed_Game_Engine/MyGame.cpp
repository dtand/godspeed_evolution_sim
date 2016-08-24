//
//  MyGame.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "MyGame.h"

void MyGame::setup()
{
    world = new World( this );
}

void MyGame::play()
{
    world->update();
}