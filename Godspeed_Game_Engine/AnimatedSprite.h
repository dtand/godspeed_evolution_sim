//
//  AnimatedSprite.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__AnimatedSprite__
#define __Godspeed_Game_Engine__AnimatedSprite__

#include "Sprite.h"
#include "GS_Timer.h"
#include <stdio.h>

class AnimatedSprite: public Sprite
{
    
public:
    //Animation direction, used to determine how to animate
    //a given sprite sheet
    enum ANIMATION_DIRECTION{NORTH, EAST, SOUTH, WEST};
    
private:
    
    //----- Internal Structure which holds specific animation instructions -----//
    struct SpriteAnimator
    {
        
        //Independant functions for specific animation instructions, based of directions
        static void playAnimationNorth(AnimatedSprite* spriteToAnimate, const int firstX, const int lastX, const int row);
        static void playAnimationEast(AnimatedSprite* spriteToAnimate, int firstX, const int lastX, const int row);
        static void playAnimationSouth(AnimatedSprite* spriteToAnimate, int firstX, const int lastX, const int row);
        static void playAnimationWest(AnimatedSprite* spriteToAnimate, const int firstX, const int lastX, const int row);
        
    };
    
    //Timing and frame based members
    int framesX;
    int framesY;
    int currentFrame;
    int animationDelay;
    
    //Timer for animation fluency
    GS_Timer *animationTimer;
    SDL_Rect cropper;
    
    //Keeps track of current direction for resets
    ANIMATION_DIRECTION currentDirection;
    void resetDirection();
    
    void _init();
    
public:
    
    AnimatedSprite();
    AnimatedSprite(std::string filePath);
    AnimatedSprite(std::string filePath, const int framesX, const int framesY);
    AnimatedSprite(std::string filePath, const int framesX, const int framesY, const int passedDelay);
    
    //To display the animated sprite
    void draw();
    
    //Animate the sprite
    void playAnimation(const int firstX, const int lastX, const int section, const ANIMATION_DIRECTION direction);
    
    //General setters
    void setupAnimation(const int amountX, const int amountY);
    void setAnimationDelay(const int passedDelay){animationDelay = passedDelay;}
    
    
};

#endif /* defined(__Godspeed_Game_Engine__AnimatedSprite__) */
