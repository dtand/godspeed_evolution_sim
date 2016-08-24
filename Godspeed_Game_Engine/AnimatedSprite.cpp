//
//  AnimatedSprite.cpp
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 4/2/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "AnimatedSprite.h"

void AnimatedSprite::_init()
{
    framesX = 0;
    framesY = 0;
    currentFrame = 0;
    animationDelay = 0;
    cropper = {0,0,0,0};
    animationTimer = new GS_Timer();
}


//Default constuctor
AnimatedSprite::AnimatedSprite() : Sprite()
{
    _init();
    
}

//Constructor given GameProcessor and texture pathway
AnimatedSprite::AnimatedSprite(std::string filePath) :
                Sprite(filePath)
{
    _init();
}

//Constructor given GameProcessor, texture pathway and frames
AnimatedSprite::AnimatedSprite(std::string filePath,
                               const int passedFramesX, const int passedFramesY) : Sprite(filePath)
{
    setupAnimation(passedFramesX, passedFramesY);
    _init();
}

//Constructor given GameProcessor, texture pathway, frames and delay
AnimatedSprite::AnimatedSprite(std::string filePath,
                               const int passedFramesX, const int passedFramesY, const int passedDelay) : Sprite(filePath)
{
    setupAnimation(passedFramesX, passedFramesY);
    _init();
    animationDelay = passedDelay;
    animationTimer->setEndTime(animationDelay);
    
}

//Sets number of frames in picture
void AnimatedSprite::setupAnimation(const int amountX, const int amountY)
{
    framesX = amountX;
    framesY = amountY;
}

//Overloaded draw to include cropping
void AnimatedSprite::draw()
{
    SDL_RenderCopy(gameProcessor->getRenderer(), image, &cropper, &destinations);
}

//Public function which uses given direction to access other functions of animator class
void AnimatedSprite::playAnimation(const int firstX, const int lastX, const int section, ANIMATION_DIRECTION direction)
{
    
    //Set the direction so we know when to reset frames
    if (currentDirection != direction)
    {
        currentDirection = direction;
        resetDirection();
    }
    
    //Run the timer for x milliseconds
    if (animationTimer->process(animationDelay))
    {
        
            //Decide which direction to run the animation
        switch (direction)
        {
            case NORTH:
                SpriteAnimator::playAnimationNorth(this, firstX, lastX, section);
                break;
            case EAST:
                SpriteAnimator::playAnimationEast(this, firstX, lastX, section);
                break;
            case SOUTH:
                SpriteAnimator::playAnimationSouth(this, firstX, lastX, section);
                break;
            case WEST:
                SpriteAnimator::playAnimationWest(this, firstX, lastX, section);
                break;
            default:
                break;
        }
        
        animationTimer->reset();
    }
    
}

//Reset current frame based on given direction
void AnimatedSprite::resetDirection()
{
    
    if(currentDirection == EAST || currentDirection == SOUTH)
    {
        currentFrame = 0;
    }
    else if(currentDirection == WEST)
    {
        currentFrame = framesX - 1;
    }
    else if(currentDirection == NORTH)
    {
        currentFrame = framesY - 1;
    }
}

//----------------------------------------//
//                                        //
//         Sprite Animator Class          //
//                                        //
//----------------------------------------//

//Handles animation from Bottom to Top [NORTH]
void AnimatedSprite::SpriteAnimator::playAnimationNorth(AnimatedSprite *spriteToAnimate, const int firstX, const int lastX, const int section)
{
    
}

//Handles animation from Left to Right [EAST]
void AnimatedSprite::SpriteAnimator::playAnimationEast(AnimatedSprite *spriteToAnimate, const int firstX, const int lastX, const int section)
{

    if (lastX <= spriteToAnimate->currentFrame)
        spriteToAnimate->currentFrame = firstX;
    else
        spriteToAnimate->currentFrame++;
    
    spriteToAnimate->cropper.x = spriteToAnimate->currentFrame *
                    (spriteToAnimate->imgWidth / spriteToAnimate->framesX);
    spriteToAnimate->cropper.y = section * (spriteToAnimate->imgHeight / spriteToAnimate->framesY);
    spriteToAnimate->cropper.w = spriteToAnimate->imgWidth / spriteToAnimate->framesX;
    spriteToAnimate->cropper.h = spriteToAnimate->imgHeight / spriteToAnimate->framesY;
    
}

//Handles animation from Top to Bottom [SOUTH]
void AnimatedSprite::SpriteAnimator::playAnimationSouth(AnimatedSprite *spriteToAnimate, const int firstX, const int lastX, const int section)
{
    
}

//Handles animation from Right to Left [WEST]
void AnimatedSprite::SpriteAnimator::playAnimationWest(AnimatedSprite *spriteToAnimate, const int firstX, const int lastX, const int section)
{
    if (lastX >= spriteToAnimate->currentFrame)
        spriteToAnimate->currentFrame = firstX;
    else
        spriteToAnimate->currentFrame++;
    
    spriteToAnimate->cropper.x = spriteToAnimate->currentFrame *
    (spriteToAnimate->imgWidth / spriteToAnimate->framesX);
    spriteToAnimate->cropper.y = section * (spriteToAnimate->imgHeight / spriteToAnimate->framesY);
    spriteToAnimate->cropper.w = spriteToAnimate->imgWidth / spriteToAnimate->framesX;
    spriteToAnimate->cropper.h = spriteToAnimate->imgHeight / spriteToAnimate->framesY;
}
//
//void AnimatedSprite::SpriteAnimator::