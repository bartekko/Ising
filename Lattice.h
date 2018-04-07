#pragma once
#include <vector>
#include "2Draw.h"

#include <iostream>
class Lattice
{
public:
	Lattice(int L, double T):visor()
	{	l=L;
		l2=L*L;
		stor.resize(L*L,0); 		
		Temp=T;
		initialize_switch_probability();
	};
	 
	char spin(int x,int y) 
	{	
		return stor[to_pos(x,y)];
	};
	bool is_upspin(int n) 
	{	
		if(n<0) n+=l2;
		if(n>l2) n-=l2;
		return stor[n]==1;
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
	
	int nn_upspin_count(int n)
	{	
		int c=is_upspin(n-1)+is_upspin(n+1)+is_upspin(n-l)+is_upspin(n+l);
		
		return c;
	}
		
	double switch_probability(int n)
	{	return prob[is_upspin(n)][nn_upspin_count(n)];
	}
	
	
	
	void initialize_switch_probability()
	{	
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<5;j++)
			{
				auto dE=-2*(-1+2*i)*(-4+2*j);
				auto ans=exp(dE/Temp);
				prob[i][j]=ans>1?1:ans;
			}
		}
	}



	void Draw()
	{
		visor.FullDraw(stor,l);
	}
	
	int length() const {return stor.size();}
	int sideLength(){return l;}
//private:
	Draw2D visor;
	std::vector<char> stor;
	int l;
	int l2;
	double Temp;
	double prob[2][5];
};
