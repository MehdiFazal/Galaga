#pragma once
#include"Node.h"

class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();
    void Enqueue(Unit*);
    void Firedodge(int,int);
    void FireClean();
    void CleanBreakout(Node*);
    void Clean();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Move(int);
};
