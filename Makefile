all: sim.cpp
	g++ sim.cpp -o sim -O2 -Wall -lSDL2 -g

