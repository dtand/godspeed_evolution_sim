//
//  Window.h
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 3/29/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Engine__Window__
#define __Godspeed_Engine__Window__
#include "GameProcessor.h"

class Window
{
private:
    SDL_Window *window;
    float globalScalar;
    
    SDL_Rect dimmensions;
    
public:
    Window(GameProcessor *gameProcessor);
    
    ~Window();
    void destroy();
    
    void setDimmensions(const int passedX, const int passedY, const int passedWidth, const int passedHeight);
    void setX(const int passedX);
    void setY(const int passedY);
    void setWidth(const int passedWidth);
    void setHeight(const int passedHeight);
    SDL_Rect getDimmensions(){ return dimmensions; }
    
};

#endif /* defined(__Godspeed_Engine__Window__) */
