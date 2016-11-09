#include"Enemy.h"


Enemy::Enemy()
{
    spriteTemp = 0;
    EnemyTicks = 1;

}

Enemy::~Enemy()
{
    spriteSheetTexture = NULL;
    cout<<"Enemy Deallocated"<<endl;
}

Enemy::Enemy(LTexture* image, float x, float y):Unit(image, x, y)
{
    friction = 0.85f;
    //Frame 0
    spriteClips[ 0 ].x = 156.5;
    spriteClips[ 0 ].y = 98.5;
    spriteClips[ 0 ].w = 24.25;
    spriteClips[ 0 ].h = 24.25;

    //Frame 1
    spriteClips[ 1 ].x = 180.75;
    spriteClips[ 1 ].y = 98.5;
    spriteClips[ 1 ].w = 24.25;
    spriteClips[ 1 ].h = 24.25;

}


void Enemy::Move(int SCREEN_HEIGHT)
{
    EnemyTicks ++;
    if (y > SCREEN_HEIGHT+96)
    {
        SetAlive(false);
    }
    speedy = 5;
    //y+=speedy;
    //x+= ((2*sin(0.05*EnemyTicks))*2);
    if (EnemyTicks<300)
    {
    x+= (10*cos(EnemyTicks/5));
    y+= (10*sin(EnemyTicks/50));
    }

}

void Enemy::MoveL(int direction)
{

    if(direction==2) //Left
    {
        speedx = -5;
        x+=speedx;
    }

    if(direction==3) //Right
    {
        speedx = 5;
        x+=speedx;
    }

}

void Enemy::Move()
{
    speedx = speedx * friction;
    x = x + speedx;
}


void Enemy::Render(long int& frame, SDL_Renderer* gRenderer)
{


    if (frame%10 == 0)
    {
        if (spriteTemp == 0)
        {
            spriteTemp =1;
        }
        else
        {
            spriteTemp = 0;
        }
    }
    spriteSheetTexture->Render( x - width/2, y - height/2, &spriteClips[ spriteTemp ], 180.0, NULL, SDL_FLIP_NONE, gRenderer );

}

