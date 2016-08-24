//
//  GameObject.h
//  Godspeed_Game_Engine
//
//  Created by Daniel Anderson on 7/3/15.
//  Copyright (c) 2015 Daniel Anderson. All rights reserved.
//

#ifndef __Godspeed_Game_Engine__GameObject__
#define __Godspeed_Game_Engine__GameObject__
#include "godspeed1.h"
#include "RandomNumberGenerator.h"

class Sprite;

struct Vector2
{
    int x;
    int y;
};

//Main entity used to input graphics and other dynami`cs
//into the world, should create a gameobject first and
//add components to it after
class GameObject
{
protected:
    
    //Defaults
    static const int DEF_WIDTH  = 10;
    static const int DEF_HEIGHT = 10;
    
    int index;
    bool isVisible;
    
    //Default components
    Sprite *sprite;
    Vector2 position;
    SDL_Rect rect;
    SDL_Color color;
    
    void init();
    
    
public:
    GameObject();
    GameObject( const GameObject& gameObject );
    void setVisable( bool pVisability ){ isVisible = pVisability; }
    void setIndex( unsigned int pIndex){ index = pIndex; }
    void setColor( int pRed, int pGreen, int pBlue );
    void setPosition( int x, int y );
    bool getVisibility(){ return isVisible; }
    SDL_Color getColor(){ return color; }
    int getIndex(){ return index; }
    void draw( SDL_Renderer* renderer );
    
    
    
};


#endif /* defined(__Godspeed_Game_Engine__GameObject__) */
