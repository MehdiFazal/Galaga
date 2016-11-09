#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"

using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class Unit
{
    protected:
        bool alive;
        float x;
        float y;
        float speedx;
        float speedy;
        int width;
        int height;
        float friction; //lower speed means more friction
        bool IfBullet;
        enum ANIMATION_FRAMES {FLYING_FRAMES = 2};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;

    public:
        Unit(LTexture* image, float x, float y);
        Unit();
        virtual ~Unit();
        void SetAlive(bool);
        bool GetAlive();
        bool GetIfBullet();
        float getX();
        float getY();
        virtual void MoveL(int direction);
        virtual void Move(int direction);
        virtual void Move();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};



