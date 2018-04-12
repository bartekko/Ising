#pragma once

#include "Lattice.h"

double magnetization(const Lattice& lat)
{
	int count=0;
	for(int i=0;i<lat.l2;i++)
	{
		count+=lat.is_upspin(i)?1:-1;
	}
	return double(count)/lat.l2;
}

double hamiltonian(const Lattice& lat)
{	auto acc=0;
	for(int i=0;i<lat.l2;i++)
	{	acc+=lat.spin(i)*lat.spin(i+1);
		acc+=lat.spin(i)*lat.spin(i+lat.l);		
	}
	return acc;
}

