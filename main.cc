#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <set>
#include <math.h>
#include <time.h>       /* time */




#define APP_NAME "Tetris"

const int SCREEN_WIDTH=600;
const int SCREEN_HEIGHT=800;
const int BRICK_SIZE=60;



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
	wnd=SDL_CreateWindow(APP_NAME, SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
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
			
			
			while( !quit )
			{
				SDL_SetRenderDrawColor( rndr, 0, 0, 0, 0);
				SDL_RenderClear( rndr );

				


				
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
				 		quit = true; 
				 	}
				}
				
				SDL_RenderPresent( rndr );
				SDL_Delay( 10 );
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
