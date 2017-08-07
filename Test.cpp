#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include "MaxSubSeq.h"


int main( int argc, char* argv[] )
{

	MaxSubSeq seq;

	seq.inicializar(std::atoi(argv[1]));

	std::vector<int> v = seq.getValores();
	std::vector<int> d = seq.getDerivadas();

	for(int i = 0; i < std::atoi(argv[1]) ; i++)
		std::cout<<v[i]<<" ";

	std::cout<<std::endl<<std::endl;

	for(int i = 0; i < std::atoi(argv[1]) ; i++)
		std::cout<<d[i]<<" ";

    return 0;
}

