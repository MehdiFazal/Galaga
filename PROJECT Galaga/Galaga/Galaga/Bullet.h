#pragma once

#include"Unit.h"

class Bullet : public Unit
{
public:
    Bullet(LTexture* image, float x, float y);
    Bullet();
    virtual ~Bullet();
    virtual void Move(int);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
