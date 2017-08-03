#include "MaxSubSeq.h"

std::pair<int, int> MaxSubSeq::fuerzaBruta()
{
  int inicioMax, finMax, valorMax;
  valorMax = -2147483647;
  std::pair<int, int> ret;
  
  for(int i = 0; i < this->numPeriodos; i++ )
  {
    for(int j = i; j < this->numPeriodos; j++)
    {
      if( (this->valores[i] - this->valores[j]) >= valorMax)
      {
        inicioMax = i;
        finMax = j;
        valorMax = (this->valores[i] - this->valores[j]);
      }
    }
  }
  
  ret = std::make_pair(inicioMax, finMax);
  
  return( ret );
}
