#include <cmath>
#include <cstdlib>
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;
boost::random::mt19937 rng(1093710);

#include "Lattice.h"

int main(int argc, char** argv)
{
	
	if(argc!=5)
	{
		std::cout<<"Usage:"<<argv[0]<<" <Lattice size> <Reduced Temperature> <Steps count> <rng seed>"<<std::endl;
		exit(-1);
	}		

	int lattice_size=atol(argv[1]);
	int temp=atof(argv[2]);	
	int steps=atol(argv[3]);
	
	rng.seed(atoi(argv[4]));
	
	Lattice lat(lattice_size);
	boost::random::uniform_int_distribution<> real(0,1);
	cerr<<"Created Lattice"<<endl;
	
	for(int mcs=0; mcs<steps;mcs++)
	{	for(int i=0;i<lattice_size;i++)
		{
			for(int j=0;j<lattice_size;j++)
			{   
				if(real(rng)<lat.switch_probability(Point(i,j),temp))
				{
					lat.at(Point(i,j))=!lat.at(Point(i,j));
				}
		
			}
				
		}
	
	}
		
}
