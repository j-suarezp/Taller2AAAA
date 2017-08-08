#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include "MaxSubSeq.h"
#include <tuple>


int main( int argc, char* argv[] )
{

	MaxSubSeq seq;

	seq.inicializar(std::atoi(argv[1]));



/*	std::vector<int> v = seq.getValores();
	std::vector<int> d = seq.getDerivadas();

	for(int i = 0; i < std::atoi(argv[1]) ; i++)
		std::cout<<v[i]<<" ";

	std::cout<<std::endl<<std::endl;

	for(int i = 0; i < std::atoi(argv[1]) ; i++)
		std::cout<<d[i]<<" ";

	std::cout<<std::endl<<std::endl<<std::endl;
*/
	std::tuple<int, int, int> fb = seq.fuerzaBruta();
	std::tuple<int, int, int> dv = seq.findMaxSubArray(0, std::atoi(argv[1])-1);
	std::get<0>(dv)--;

	std::cout<<"Fuerza bruta Inicio: "<<std::get<0>(fb)<<"   Fin: "<<std::get<1>(fb)<<"   Resultado: "<<std::get<2>(fb)<<std::endl;
	std::cout<<"Div y vencer Inicio: "<<std::get<0>(dv)<<"   Fin: "<<std::get<1>(dv)<<"   Resultado: "<<std::get<2>(dv)<<std::endl;

    return (0);
}

