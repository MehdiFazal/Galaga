#pragma once
#include<math.h>
#include"Unit.h"

class Enemy:public Unit
{
private:
    int spriteTemp;
    long int EnemyTicks;
public:
    Enemy(LTexture* image, float x, float y);
    Enemy();
    virtual ~Enemy();
    virtual void Move(int SCREEN_HEIGHT);
    virtual void Move();
    void MoveL(int direction);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
};
