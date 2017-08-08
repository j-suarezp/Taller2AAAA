#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include "MaxSubSeq.h"
#include <tuple>


int main( int argc, char* argv[] )
{
	int num = std::atoi(argv[1]);
	MaxSubSeq seq;

	seq.inicializar(num);

	long start_fb = std::chrono::duration_cast< std::chrono::milliseconds >(
	std::chrono::system_clock::now( ).time_since_epoch( ) ).count( );
	std::tuple<int, int, int> fb = seq.fuerzaBruta();
	long end_fb = std::chrono::duration_cast< std::chrono::milliseconds >(
    std::chrono::system_clock::now( ).time_since_epoch( )).count( );
  	long time_fb = end_fb - start_fb;
	
	long start_dv = std::chrono::duration_cast< std::chrono::milliseconds >(
	std::chrono::system_clock::now( ).time_since_epoch( ) ).count( );
	std::tuple<int, int, int> dv = seq.findMaxSubArray(0, num-1);
	std::get<0>(dv)--;
	long end_dv = std::chrono::duration_cast< std::chrono::milliseconds >(
    std::chrono::system_clock::now( ).time_since_epoch( )).count( );
  	long time_dv = end_dv - start_dv;
	
	std::cout<<num<<" "<<std::get<2>(fb)<<" "<<std::get<2>(dv)<<" "<<time_fb<<" "<<time_dv;

    return (0);
}

