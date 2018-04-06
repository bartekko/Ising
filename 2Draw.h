#pragma once

#include <SDL2/SDL.h>
#include <vector>

#ifdef VISOR_ENABLE


//typedef std::vector<std::pair<int,int>> pointList;

class Draw2D
{
public:
	Draw2D(int windowSize=500)
	{	SDL_Init(SDL_INIT_VIDEO);
		win= SDL_CreateWindow("Visor",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,windowSize,windowSize,0);
		ren=SDL_CreateRenderer(win,-1,0);	
	}
	void FullDraw(std::vector<char> points,int sidelength)
	{	SDL_SetRenderDrawColor(ren,0,0,0,255);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren,255,255,255,255);
		for(int x=0;x<sidelength;x++)
		{	for(int y=0;y<sidelength;y++)
			{	if(points.at(x*sidelength+y)<0)
				{SDL_RenderDrawPoint(ren,x,y);
				}			
			}
		}
		SDL_RenderPresent(ren);
	
	SDL_Event e;
	while(SDL_PollEvent(&e)!=0)
    {	if( e.type == SDL_QUIT )
		{	exit(0);
        }
        }
	}
	~Draw2D(){SDL_Quit();}

private:
	SDL_Window *win;
	SDL_Renderer *ren;	
};


#endif

#ifndef VISOR_ENABLE
class Draw2D
{
public:
	Draw2D(int windowSize=500){}
	void FullDraw(std::vector<char> points,int sidelength){}
	~Draw2D(){}
};



#endif
