#include"Queue.h"
#include<iostream>
#include"Explosion.h"
using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        cout<<"Deallocating value: "<<temp->unit<<endl;
        delete temp;
    }
}

void Queue::Enqueue(Unit* unit)
{
    if(head == NULL)
    {
        head = new Node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
        printf("head allocated");
    }
    else
    {
        tail->next = new Node;
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
        printf("enemy allocated");
    }

}
void Queue::Firedodge(int planeX, int planeY)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if (temp->unit->GetIfBullet() == true)
        {
            Node* tempPlane = head;
            while (tempPlane != NULL)
            {
                if (tempPlane->unit->GetIfBullet() == false)
                {
                    if (temp->unit->getX() < tempPlane->unit->getX()+64 )
                    {
                        if (temp->unit->getX() > tempPlane->unit->getX()-64)
                        {
                            if (tempPlane->unit->getY()<planeY)
                            {
                                if (temp->unit->getX() > tempPlane->unit->getX())
                                {
                                    if (temp->unit->getY() < tempPlane->unit->getY()+ 48 )
                                    {
                                        if (temp->unit->getY() > tempPlane->unit->getY()- 48 )
                                        {
                                            temp->unit->SetAlive(false);
                                            tempPlane->unit->SetAlive(false);
                                            //Explosion* expo = new Explosion(gSpriteSheetTexture, tempPlane->unit->getX(), tempPlane->unit->getY());
                                            //Enqueue(expo);
                                        }
                                    }
                                    tempPlane->unit->MoveL(2);
                                }
                                if (temp->unit->getX() < tempPlane->unit->getX())
                                {
                                    tempPlane->unit->MoveL(3);
                                }
                            }
                        }
                    }
                }
                tempPlane = tempPlane->next;
            }
            tempPlane = NULL;

        }
        temp = temp->next;
    }
    temp = NULL;

}
void Queue::FireClean()
{
    Node* tempCheck = head;
    Node* tempCheck2 = head->next;
    while(tempCheck2 != NULL)
    {
        while(tempCheck != NULL)
        {
            if (tempCheck->unit->GetIfBullet() == true && tempCheck2->unit->GetIfBullet() == false)
            {
                printf("bullet found\n");
                if (tempCheck->unit->getX() < tempCheck2->unit->getX() && tempCheck->unit->getX() >=tempCheck2->unit->getX()-64 )//&& ((tempCheck2->unit->getY())+48)>tempCheck->unit->getY() && ((tempCheck2->unit->getY())-48)<tempCheck->unit->getY() )
                {
                    if (tempCheck->unit->getY() <=tempCheck2->unit->getY() && tempCheck->unit->getY() >=tempCheck2->unit->getY()-48 )
                    {
                        printf("----------------bullet found\n");
                        tempCheck->unit->SetAlive(false);
                        tempCheck2->unit->SetAlive(false);
                    }
                }
            }

            tempCheck = tempCheck->next;
        }
        tempCheck2 = tempCheck2->next;
    }
}

//void Queue::CleanBreakout(Node* temp)
//{
//    Node* temp2 = temp;
//    temp = temp->next;
//    if (temp2->prev != NULL)
//    {
//        temp2->prev->next = temp2->next;
//    }
//    else
//    {
//        head = temp;
//    }
//    if (temp2->next != NULL)
//    {
//        temp2->next->prev = temp2->prev;
//    }
//    else
//    {
//        tail = temp2->prev;
//    }
//    delete temp2;
//    temp2 = NULL;
//}



void Queue::Clean()
{

    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->unit->GetAlive() == false)
        {
//            CleanBreakout(temp);
            Node* temp2 = temp;
            temp = temp->next;
            if (temp2->prev != NULL)
            {
                temp2->prev->next = temp2->next;
            }
            else
            {
                head = temp;
            }
            if (temp2->next != NULL)
            {
                temp2->next->prev = temp2->prev;
            }
            else
            {
                tail = temp2->prev;
            }
            delete temp2;
            temp2 = NULL;
        }
        else
        {
            temp=temp->next;
        }



    }
}



void Queue::Render(long int& frame, SDL_Renderer* gRenderer)
{
    Node* temp = head;
    while(temp != NULL)
    {
        temp->unit->Render(frame, gRenderer);
        temp = temp->next;
    }
    temp = NULL;

}

void Queue::Move(int SCREEN_HEIGHT)
{
    Node* temp = head;
    while(temp != NULL)
    {
        if (temp->unit->GetIfBullet() == false)
        {
            temp->unit->Move();
        }
        temp->unit->Move(SCREEN_HEIGHT);
        temp = temp->next;
    }
    temp = NULL;
}

