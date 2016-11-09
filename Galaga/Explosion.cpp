#include "Explosion.h"

Explosion::Explosion()
{

}

Explosion::Explosion(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;


    //Frame 0
    spriteClips[ 0 ].x =   0;
    spriteClips[ 0 ].y =   127;
    spriteClips[ 0 ].w = 39.42;
    spriteClips[ 0 ].h = 45;

    //Frame 1
    spriteClips[ 1 ].x = 39.42;
    spriteClips[ 1 ].y =   127;
    spriteClips[ 1 ].w = 39.42;
    spriteClips[ 1 ].h = 45;

    //Frame 2
    spriteClips[ 2 ].x = 78.8;
    spriteClips[ 2 ].y = 127;
    spriteClips[ 2 ].w = 39.42;
    spriteClips[ 2 ].h = 45;

    spriteClips[ 3 ].x = 118.27;
    spriteClips[ 3 ].y = 127;
    spriteClips[ 3 ].w = 39.42;
    spriteClips[ 3 ].h = 45;

    spriteClips[ 4 ].x = 157.69;
    spriteClips[ 4 ].y = 127;
    spriteClips[ 4 ].w = 39.42;
    spriteClips[ 4 ].h = 45;

    spriteClips[ 5 ].x = 197.1;
    spriteClips[ 5 ].y = 127;
    spriteClips[ 5 ].w = 39.42;
    spriteClips[ 5 ].h = 45;

    spriteClips[ 6 ].x = 236.53;
    spriteClips[ 6 ].y = 127;
    spriteClips[ 6 ].w = 39.42;
    spriteClips[ 6 ].h = 45;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;


}


Explosion::~Explosion()
{
    spriteSheetTexture = NULL;
}


void Explosion::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

