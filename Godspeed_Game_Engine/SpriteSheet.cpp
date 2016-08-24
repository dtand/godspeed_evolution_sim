//
//  SpriteSheet.cpp
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
    Sprite();
    framesX = 0;
    framesY = 0;
    cropper = {0,0,0,0};
}

SpriteSheet::SpriteSheet(GameProcessor *passedGameProcessor) : Sprite()
{
    framesX = 0;
    framesY = 0;
    cropper = {0,0,0,0};
}

SpriteSheet::SpriteSheet(GameProcessor *passedGameProcessor, const std::string filePath) : Sprite(filePath)
{
    framesX = 0;
    framesY = 0;
    cropper = {0,0,0,0};
}

void SpriteSheet::draw()
{
    SDL_RenderCopy(gameProcessor->getRenderer(), image, &cropper, &destinations);
}

void SpriteSheet::setupCrop(const int amountX, const int amountY)
{
    framesX = amountX;
    framesY = amountY;
}

void SpriteSheet::crop(const int firstX, const int lastX, const int firstY, const int lastY)
{
    
    cropper.x = firstX * (imgWidth / framesX);
    cropper.y = firstY * (imgHeight / framesY);
    cropper.w = imgWidth / framesX * (lastX - firstX + 1);
    cropper.h = imgHeight / framesY * (lastY - firstY + 1);
    
    destinations.w = cropper.w;
    destinations.h = cropper.h;
}