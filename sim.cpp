#define VISOR_ENABLE

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <vector>
#include <string>
#include <algorithm>

#include <chrono>

#include "Lattice.h"



using namespace std;

int main(int argc, char** argv)
{	if(argc!=5)
	{
		std::cout<<"Usage:"<<argv[0]<<" <Lattice size> <Reduced Temperature> <Steps count> <rng seed>"<<std::endl;
		exit(-1);
	}		

	int lattice_size=atol(argv[1]);
	double temp=atof(argv[2]);	
	int steps=atol(argv[3]);
	boost::random::mt19937 rng(atoi(argv[4]));
	cerr<<"Set parameters"<<endl;

	Lattice lat(lattice_size,temp);
	boost::random::uniform_int_distribution<> boolean(0,1);
	for(int i=0;i<lat.length();i++)
	{	if(boolean(rng))
		{	lat.stor[i]=1;
			
		}else lat.stor[i]=-1;
	}
	cerr<<"Created Lattice"<<endl;
	
	auto latlen=lat.length();
	boost::random::uniform_real_distribution<> real(0,1);
	for(int mcs=0; mcs<steps;mcs++)
	{	
	
	//Simulate one MCS (step)
		auto t0=chrono::system_clock::now();
		
		for(int i=0;i<latlen;i++)
		{	if(real(rng)<lat.switch_probability(i)) //METROPOLIS ALGORITHM
			{	lat.flip(i);
			}				
		}
		
		
		
		auto t1=chrono::system_clock::now();	
		//Draw everything
		lat.Draw();
		auto t2=chrono::system_clock::now();
		cout<<"Simulation time: "<<((chrono::duration_cast<chrono::milliseconds>(t1-t0)).count())<<"ms\n";
		cout<<"Draw Time: "<<((chrono::duration_cast<chrono::milliseconds>(t2-t1)).count())<<"ms\n";
		
	
			
	}
		
}
