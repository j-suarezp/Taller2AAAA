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
    llenarVector(int numPeriodos);
    
    return 0;
}
    
std::vector<int> llenarVector(int numPeriodos)
{
    int num;
    std::vector<int> vect;
    for(int i = 1; i <= n; i++)
    {
        num = (rand() % 999 + 1);
        vect.push(num);
    }
}
