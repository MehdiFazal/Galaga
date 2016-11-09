#pragma once
//#include <SDL.h>
//#include <SDL_image.h>
//#include <stdio.h>
//#include <iostream>
//#include"LTexture.h"
#include"Unit.h"

using namespace std;



class Explosion:public Unit
{
    protected:
//        float x;
//        float y;
//        int width;
//        int height;
        enum ANIMATION_FRAMES {FLYING_FRAMES = 7};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
//        LTexture* spriteSheetTexture;

    public:
        Explosion(LTexture* image, float x, float y);
        Explosion();
        virtual ~Explosion();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};



