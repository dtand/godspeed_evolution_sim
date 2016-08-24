//
//  Window.cpp
//  Godspeed_Engine
//
//  Created by Daniel Anderson on 3/29/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#include "Window.h"

Window::Window(GameProcessor *gameProcessor)
{
    globalScalar = 1.0;
    window = gameProcessor->getWindow();
    SDL_GetWindowSize(window, &dimmensions.w, &dimmensions.h );
    SDL_GetWindowPosition(window, &dimmensions.x, &dimmensions.y);
}

//Sets corresponding dimmmensions for the window
void Window::setDimmensions(const int passedX, const int passedY, const int passedWidth, const int passedHeight)
{
    //Sets window dimmensions
    SDL_SetWindowSize(window, passedWidth, passedHeight);
    SDL_SetWindowPosition(window, passedX, passedY);
    
    //Contains dimmensions within rect
    dimmensions.x = passedX;
    dimmensions.y = passedY;
    dimmensions.w = passedWidth;
    dimmensions.h = passedHeight;
}

void Window::setX(const int passedX)
{
    setDimmensions(passedX, dimmensions.y, dimmensions.w, dimmensions.h);
}

void Window::setY(const int passedY)
{
    setDimmensions(dimmensions.x, passedY, dimmensions.w, dimmensions.h);
}

void Window::setWidth(const int passedWidth)
{
    setDimmensions(dimmensions.x, dimmensions.y, passedWidth, dimmensions.h);
}

void Window::setHeight(const int passedHeight)
{
    setDimmensions(dimmensions.x, dimmensions.y, dimmensions.w, passedHeight);
}

Window::~Window()
{
    destroy();
}

void Window::destroy()
{
    SDL_DestroyWindow(window);
}