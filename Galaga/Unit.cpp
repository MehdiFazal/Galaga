#include "Unit.h"

Unit::Unit()
{

}
void Unit::MoveL(int direction)
{

}

Unit::Unit(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x = 156.5;
    spriteClips[ 0 ].y = 50;
    spriteClips[ 0 ].w = 24.25;
    spriteClips[ 0 ].h = 24.25;

    //Frame 1
    spriteClips[ 1 ].x = 180.75;
    spriteClips[ 1 ].y = 50;
    spriteClips[ 1 ].w = 24.25;
    spriteClips[ 1 ].h = 24.25;
//    //Frame 2
//    spriteClips[ 2 ].x = 256;
//    spriteClips[ 2 ].y = 0;
//    spriteClips[ 2 ].w = 128;
//    spriteClips[ 2 ].h = 96;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
    IfBullet = false;
}


Unit::~Unit()
{
    spriteSheetTexture = NULL;
}

void Unit::SetAlive(bool alive)
{
    this->alive = alive;
}
bool Unit::GetIfBullet()
{
    return IfBullet;
}
bool Unit::GetAlive()
{
    return alive;
}

void Unit::Move(int direction)
{

    if(direction==LEFT)
    {
        speedx = -5;
        x+=speedx;
    }

    if(direction==RIGHT)
    {
        speedx = 5;
        x+=speedx;
    }

    if(direction==UP)
    {
        speedy = -5;
        y+=speedy;
    }

    if(direction==DOWN)
    {
        speedy = 5;
        y+=speedy;
    }

}

float Unit::getX()
{
    return x;
}

float Unit::getY()
{
    return y;
}

void Unit::Move()
{
     speedx = speedx * friction;
     speedy = speedy * friction;

     x = x + speedx;
     y = y + speedy;
}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

