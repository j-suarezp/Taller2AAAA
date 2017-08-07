#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include "MaxSubSeq.h"

std::vector<int> llenarVector(int numPeriodos);

int main( int argc, char* argv[] )
{
    int numPeriodos;
    std::cin>>numPeriodos;
    std::vector<int> vect = llenarVector(numPeriodos);
    
    for(int i = 0; i < numPeriodos; i++)
	std::cout<<vect[i]<<" ";
    
    return 0;
}

std::vector<int> llenarVector(int numPeriodos)
{
    int num;
    std::vector<int> vect;
    for(int i = 0; i < numPeriodos; i++)
    {
        num = (rand() % 999 + 1);
        vect.push_back(num);
    }
    
    return vect;
}
