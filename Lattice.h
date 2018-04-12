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
	 
	inline bool is_upspin(int n) const
	{	
		if(n<0) n+=l2;
		if(n>l2) n-=l2;
		return stor[n]==1;
	};
	inline char spin(int n) const
	{	while(n>l2)
		{n-=l2;}
		return stor[n];
	} 
	

	inline void flip(int n)
	{
		stor[n]=stor[n]<=0?1:-1;
	}
	
	int nn_upspin_count(int n) const
	{	
		int c=is_upspin(n-1)+is_upspin(n+1)+is_upspin(n-l)+is_upspin(n+l);	
		return c;
	}
		
	double switch_probability(int n) const
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
