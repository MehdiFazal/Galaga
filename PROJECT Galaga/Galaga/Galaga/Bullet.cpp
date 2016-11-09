#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
    cout<<"Bullet Deallocated"<<endl;
}

Bullet::Bullet(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;

    spriteClips[ 0 ].x = 360;
    spriteClips[ 0 ].y = 192;
    spriteClips[ 0 ].w = 12;
    spriteClips[ 0 ].h = 16;


    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    alive  = true;
    IfBullet = true;
    speedy = 0;

}

void Bullet::Move(int SCREEN_HEIGHT)
{
    if (y <0)
    {
        SetAlive(false);
    }
    speedy = 50;
    y-=speedy;
}

void Bullet::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}
