//
//  Sprite.h
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Engine__Sprite__
#define __Godspeed_Engine__Sprite__
#include "Game.h"

class Sprite
{
    
private:
    void _init();
    
protected:
    
    GameProcessor *gameProcessor;
    SDL_Rect destinations;
    
    SDL_Texture *image;
    
    int imgHeight;
    int imgWidth;
    
public:
    Sprite();
    Sprite(const std::string filePath);
    void createTextureFromFilepath(const std::string filePath);
    
    void setGameProcessor(GameProcessor *passedGameProcessor){gameProcessor = passedGameProcessor;}
    void setDestination(const int destX, const int destY);
    void setDestinationX(const int destX){destinations.x = destX;}
    void setDestinationY(const int destY){destinations.y = destY;}
    void setDestinationWidth(const int destWidth){destinations.w = destWidth;}
    void setDestinationHeight(const int destHeight){destinations.h = destHeight;}
    
    //General getters
    int getX(){return destinations.x;}
    int getY(){return destinations.y;}
    int getWidth(){return destinations.w;}
    int getHeight(){return destinations.h;}
    
    void draw();
    
};

#endif /* defined(__Godspeed_Engine__Sprite__) */
