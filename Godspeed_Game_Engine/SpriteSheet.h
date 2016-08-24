//
//  SpriteSheet.h
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Engine__SpriteSheet__
#define __Godspeed_Engine__SpriteSheet__

#include <stdio.h>
#include "Sprite.h"

class SpriteSheet : public Sprite
{
private:
    int framesX;
    int framesY;
    
    SDL_Rect cropper;
    
public:
    SpriteSheet();
    SpriteSheet(GameProcessor *passedGameProcessor);
    SpriteSheet(GameProcessor *passedGameProcessor, const std::string filePath);
    
    void draw();
    void setupCrop(const int amountX, const int amountY);
    void crop(const int firstX, const int firstY, const int lastX, const int lastY);
};

#endif /* defined(__Godspeed_Engine__SpriteSheet__) */
