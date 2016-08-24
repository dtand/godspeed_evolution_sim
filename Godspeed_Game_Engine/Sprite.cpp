//
//  Sprite.cpp
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite()
{
    _init();
}

Sprite::Sprite(const std::string filePath)
{
    createTextureFromFilepath(filePath);
}

void Sprite::_init()
{
    //gameProcessor = Game::getInstance().getGameProcessor();
    image = nullptr;
    
    destinations = {0,0,0,0};
}

void Sprite::createTextureFromFilepath(const std::string filePath)
{
    //Check for previous creation
    if (image != nullptr)
    {
        SDL_DestroyTexture(image);
    }
    
    //Create texture
    image = IMG_LoadTexture(gameProcessor->getRenderer(), filePath.c_str());
    
    //Check for bad filepath
    if(image == nullptr)
    {
        throw "ERR: Failed loaded image in sprite of filepath: " + filePath;
    }
    else
    {
        SDL_QueryTexture(image, nullptr, nullptr, &imgWidth, &imgHeight);
        destinations.w = imgWidth;
        destinations.h = imgHeight;
    }
}

void Sprite::setDestination(const int destX, const int destY)
{
    destinations.x = destX;
    destinations.y = destY;
}

void Sprite::draw()
{

    SDL_RenderCopy(gameProcessor->getRenderer(), image, nullptr, &destinations);
    
}

