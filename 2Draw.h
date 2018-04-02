#pragma once

#include <SDL2/SDL.h>
#include <vector>

class Draw2D
{
public:
	Draw2D(int size_x=500, int size_y=500)
	{	SDL_Init(SDL_INIT_VIDEO);
		win= SDL_CreateWindow("Visor",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,size_x,size_y,0);
		ren=SDL_CreateRenderer(win,-1,0);
	}
	void FullDraw(std::vector<char> points,int sidelength)
	{	SDL_SetRenderDrawColor(ren,0,0,0,255);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren,255,255,255,255);
		for(int x=0;x<sidelength;x++)
		{	for(int y=0;y<sidelength;y++)
			{	if(points.at(x*sidelength+y))
				{SDL_RenderDrawPoint(ren,x,y);
				}			
			}
		}
		SDL_RenderPresent(ren);
	}
	~Draw2D(){SDL_Quit();}

private:
	SDL_Window *win;
	SDL_Renderer *ren;	
};
