//#define VISOR_ENABLE
//#define RANDOMIZED_LATTICE_FLIPPING
//#define PERF_STATS
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
#include "Analysis.h"


using namespace std;

int main(int argc, char** argv)
{	if(argc != 6)
	{
		cerr<<"Usage:"<<argv[0]<<" <Lattice size> <Reduced Temperature> <Steps count> <rng seed> <Analysis interval>"<<std::endl;
		exit(-1);
	}		

	int lattice_size=atol(argv[1]);
	double temp=atof(argv[2]);	
	int steps=atol(argv[3]);
	boost::random::mt19937 rng(atoi(argv[4]));
	auto interval=atoi(argv[5]);
	cerr<<"Set parameters"<<endl;
	
	

	Lattice lat(lattice_size,temp);
	boost::random::uniform_int_distribution<> boolean(0,1);
	boost::random::uniform_int_distribution<> rlat(0,lat.length());
	
	for(int i=0;i<lat.length();i++)
	{	if(boolean(rng))
		{	lat.stor[i]=1;
			
		}else lat.stor[i]=-1;
	}
	cerr<<"Created Lattice "<<endl;
	
	auto latlen=lat.length();
	boost::random::uniform_real_distribution<> real(0,1);
	for(int mcs=0; mcs<steps;mcs++)
	{	//Simulate one MCS (step)
		auto t0=chrono::system_clock::now();		
		for(int i=0;i<latlen;i++)
		{	auto p=i;
		
#ifdef  RANDOMIZED_LATTICE_FLIPPING
			p=rlat(rng);
#endif
			if(real(rng)<lat.switch_probability(p)) //METROPOLIS ALGORITHM
			{	lat.flip(p);
			}				
		}
		
		
		
		auto t1=chrono::system_clock::now();	
		//Draw everything
		lat.Draw();
		auto t2=chrono::system_clock::now();
		if(mcs%interval==0)cout<<hamiltonian(lat)<<' '<<magnetization(lat)<<'\n';			
		auto t3=chrono::system_clock::now();
#ifdef PERF_STATS
		cerr<<"Simulation time: "<<((chrono::duration_cast<chrono::milliseconds>(t1-t0)).count())<<"ms\n";
		cerr<<"Draw Time: "<<((chrono::duration_cast<chrono::milliseconds>(t2-t1)).count())<<"ms\n";		
		cerr<<"Analysis Time: "<<((chrono::duration_cast<chrono::milliseconds>(t3-t2)).count())<<"ms\n";
#endif
	}		
}
