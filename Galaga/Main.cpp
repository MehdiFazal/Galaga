#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "Queue.h"
#include "Unit.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Explosion.h"


//Pre defined screen width and height
const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 768;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gSpriteSheetTexture;

bool init();
bool loadMedia();
void close();

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

			bool quit = false;                      //Main loop flag

			SDL_Event e;                            //Event handler

			long int frame = 0;                     //Current animation frame
			/* initialize random seed: */
            srand (time(NULL));

            /* generate secret number between 1 and 10: */
            //int random = 0;
            //Queue EnemyPlanes;
            //bool BulletCreated = false;
            //Queue Bullets;
			//Unit* plane = new Unit(&gSpriteSheetTexture, (float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT/2);
			//Explosion* expo = new Explosion(&gSpriteSheetTexture, 300, 300);

			//Enemy* EnemyPlane  = new Enemy(&gSpriteSheetTexture, 100, 0);


			while( !quit )                          //While application is running
			{
			    if(frame%30 == 0)
                {
                    //random = rand() % SCREEN_WIDTH;
                    //Enemy* SingleEnemy = new Enemy(&gSpriteSheetTexture, random, -96);
                    //Explosion* expo = new Explosion(&gSpriteSheetTexture, random, 300);


                    //EnemyPlanes.Enqueue(SingleEnemy);
                    //EnemyPlanes.Enqueue(expo);

                }
                //EnemyPlane = new Enemy(&gSpriteSheetTexture, random, 0);


				while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
				{


					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
                    {
                        //plane->Move(RIGHT);
                    }

                    if(currentKeyStates[ SDL_SCANCODE_LEFT ])
                    {
                        //plane->Move(LEFT);
                    }

                    if(currentKeyStates[ SDL_SCANCODE_UP ])
                    {
                        //plane->Move(UP);
                    }

                    if(currentKeyStates[ SDL_SCANCODE_DOWN ])
                    {
                        //plane->Move(DOWN);
                    }
                    if(currentKeyStates[ SDL_SCANCODE_SPACE ])
                    {
//                        if (BulletCreated == false)
//                        {
//                            Bullet* bullet = new Bullet(&gSpriteSheetTexture, plane->getX()-2, plane->getY()-49);
//                            EnemyPlanes.Enqueue(bullet);
//                            BulletCreated = true;
//                            //EnemyPlanes.FireClean();
//                        }
                    }

				}

				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
				SDL_RenderClear( gRenderer );

                //EnemyPlane->Render(frame, gRenderer);
                //EnemyPlane->Move();
                //EnemyPlanes.Render(frame, gRenderer);
                //EnemyPlanes.Firedodge(plane->getX(),plane->getY());
                //EnemyPlanes.Move(SCREEN_HEIGHT);

//                EnemyPlanes.Render(frame, gRenderer);
//                EnemyPlanes.Move(SCREEN_HEIGHT);
                //expo->Render(frame, gRenderer);

                //plane->Render(frame, gRenderer);
                //plane->Move();
                //EnemyPlanes.Clean();

                //EnemyPlanes.FireClean();

                //EnemyPlanes.Clean();
				SDL_RenderPresent( gRenderer );     //Update screen



				//if (EnemyPlane[0]->y > SCREEN_HEIGHT + 96 && frame%2 == 0)                           //Go to next frame
                //{
                 //   delete EnemyPlane[0];
                //}
                //BulletCreated = false;
                ++frame;
			}
			//delete plane;
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTexture.LoadFromFile( "Images/1948.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTexture.Free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
