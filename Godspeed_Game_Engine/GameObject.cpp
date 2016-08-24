//
//  GameObject.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 7/3/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "GameObject.h"

GameObject::GameObject()
{
    init();
}

GameObject::GameObject( const GameObject& gameObject )
{
    index     = gameObject.index;
    isVisible = gameObject.isVisible;
    sprite    = gameObject.sprite;
    rect      = gameObject.rect;
    color     = gameObject.color;
    position  = gameObject.position;
}

void GameObject::init()
{
    index = -1;
    isVisible = false;
    sprite = nullptr;
    position.x = 0;
    position.y = 0;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = DEF_WIDTH;
    rect.h = DEF_HEIGHT;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 255;
}

void GameObject::setColor(int pRed, int pGreen, int pBlue)
{
    color.r = pRed;
    color.g = pGreen;
    color.b = pBlue;
}

void GameObject::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void GameObject::draw(SDL_Renderer *renderer)
{
    rect.x = position.x;
    rect.y = position.y;
 
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a );
    SDL_RenderDrawRect(renderer, &rect);
    
}

