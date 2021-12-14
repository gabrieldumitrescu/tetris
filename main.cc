#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <set>
#include <math.h>
#include <time.h>       /* time */

#include "Game.h"


#define APP_NAME "Tetris"

const int SCREEN_WIDTH=400;
const int SCREEN_HEIGHT=800;
const int BRICK_SIZE=40;
const float FRAME_RATE=10.0;


void printSDL2Error(const char* msg)
{
	puts(msg);
	printf("SDL_Error: %s\n",SDL_GetError());
}

bool initWindow(SDL_Window* &wnd)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printSDL2Error("SDL could not initialize!");
		return false;
	}
	wnd=SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_OPENGL);
	if(wnd==NULL)
	{
		printSDL2Error("SDL could not create window!");
		return false;
	}
	return true;
}



int main()//int argc, char* argv[])
{
	
	/* initialize random seed: */
	srand (time(NULL));

	SDL_Window* wnd=NULL;
	SDL_Renderer* rndr = NULL;
	SDL_Event e;


	if(initWindow(wnd))
	{
		rndr = SDL_CreateRenderer(wnd,-1,SDL_RENDERER_ACCELERATED);

		if(rndr == NULL)
		{
			printSDL2Error("Renderer could not be created");
		}
		else
		{
			bool quit=false;
			Game tetrisGame(SCREEN_WIDTH,SCREEN_HEIGHT,BRICK_SIZE);
			Uint32 previousFrameTime=SDL_GetTicks();
			Uint32 frameTime=(Uint32)(1000.0/FRAME_RATE);
			while( !quit )
			{
				SDL_SetRenderDrawColor( rndr, 0, 0, 0, 0);
				SDL_RenderClear( rndr );
				tetrisGame.show( rndr );
				if((SDL_GetTicks()-previousFrameTime)>=frameTime)
				{
					tetrisGame.step();
					previousFrameTime=SDL_GetTicks();
				}

				
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
				 		quit = true; 
				 	}
					else if(e.type == SDL_KEYDOWN)
					{
						switch (e.key.keysym.sym)
						{
							case SDLK_LEFT:
								tetrisGame.movePieceLeft(true);
								break;
							case SDLK_RIGHT:
								tetrisGame.movePieceRight(true);
								break;
							case SDLK_DOWN:
								tetrisGame.rotatePiece();
								break;
						}
					}
					else if(e.type == SDL_KEYUP)
					{
						switch (e.key.keysym.sym)
						{
							case SDLK_LEFT:
								tetrisGame.movePieceLeft(false);
								break;
							case SDLK_RIGHT:
								tetrisGame.movePieceRight(false);
								break;
						}
					}
				}
				
				SDL_RenderPresent( rndr );
//				SDL_Delay( 100 );
			}
			SDL_DestroyRenderer( rndr );
		}
		SDL_DestroyWindow( wnd );
		wnd= NULL ;
		rndr = NULL;
		SDL_Quit();
	}
	return 0;
}
