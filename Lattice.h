#pragma once
#include <vector>
#include "2Draw.h"

#include <iostream>
class Lattice
{
public:
	Lattice(int L, double T):visor()
	{	l=L;
		stor.resize(L*L,0); 		
		Temp=T;
	};
	 
	char spin(int x,int y) 
	{	
		return stor[to_pos(x,y)];
	};
	char spin(int n)
	{
		return stor[n];
	} 
	
	void flip(int x,int y)  
	{	int n=to_pos(x,y);
		stor[n]=stor[n]<=0?1:-1;
	};
	void flip(int n)
	{
		stor[n]=stor[n]<=0?1:-1;
	}
	
	int to_pos(int x,int y)
	{	while(x<0) x+=l;
		while(x>=l) x-=l;
		while(y<0) y+=l;
		while(y>=l) y-=l;
		return x*l+y;
	}
	
	int sum_of_nn_spins(int x,int y)
	{	
		int c=spin(x+1,y)+spin(x-1,y)+spin(x,y+1)+spin(x,y-1);
		
		return c;
	}
		
	double switch_probability(int x, int y)
	{	auto m=-2*(double(spin(x,y)*(sum_of_nn_spins(x,y)))/Temp);
		//std::cerr<<m<<'\n';
		double ans=exp(m);
		
		return ans>1?1:ans;
	}
	void Draw()
	{
		visor.FullDraw(stor,l);
	}
	
	int length1D(){return l*l;}
	int sideLength(){return l;}
//private:
	Draw2D visor;
	std::vector<char> stor;
	int l;
	double Temp;
};
