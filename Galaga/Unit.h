#pragma once
#include<iostream>
#include"Point.h"
#include"LTexture.h"

class Unit
{
private:
    bool Alive;
    Point Position;
    Point Speed;
    int Width;
    int Height
    float Friction;
    LTexture* Texture;
    int ObjectType;
    enum Frames;
    SDL_Rect SpriteClips;

public:
    Unit();
    Unit(Point,Point,int,LTexture*);
    ~Unit;
    void SetAlive(bool)
    bool GetAlive();
    void SetPosition(Point);
    Point GetPosition;
    void SetSpeed(Point);
    void Move();
    void Render();
    void SetObjectType(int);
    int GetObjectType()
    Point PositionEquation();



};
