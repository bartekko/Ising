#pragma once
#include <vector>
#include "2Draw.h"
class Lattice
{
public:
	Lattice(int L):visor()
	{	l=L;
		stor.resize(L*L,0); 		
	};
	 
	bool test(int x,int y) 
	{	
		return stor[to_pos(x,y)];
	};
	bool test(int n)
	{
		return stor[n];
	} 
	
	void flip(int x,int y)  
	{	int n=to_pos(x,y);
		stor[n]=!stor[n];
	};
	void flip(int n)
	{
		stor[n]=!stor[n];
	}
	
	int to_pos(int x,int y)
	{	while(x<0) x+=l;
		while(x>=l) x-=l;
		while(y<0) y+=l;
		while(y>=l) y-=l;
		return x*l+y;
	}
	
	int sum_of_nn_spins(int x,int y)
	{	int c=test(x+1,y)+test(x-1,y)+test(x,y+1)+test(x,y-1);
		c*=2;
		return c-4;
	}
		
	double switch_probability(int x, int y,double Temp)
	{	auto ans=exp(-2*test(x,y)*(sum_of_nn_spins(x,y))/Temp);
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
};



