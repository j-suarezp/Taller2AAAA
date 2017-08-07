#include "MaxSubSeq.h"

void MaxSubSeq::inicializar(int n)
{

	this->numPeriodos = n;	

	std::vector<int> v(n, 0);
	this->valores = this->derivadas = v;

	for(int i = 0; i < n; i++)
		this->valores[i] = (rand() % 999 + 1);

	for(int i = 1; i < n; i++)
		this->derivadas[i] = this->valores[i] - this->valores[i - 1]; 
	
	
}

std::vector<int> MaxSubSeq::getValores()
{
	return (this->valores);
}


std::vector<int> MaxSubSeq::getDerivadas()
{
	return (this->derivadas);
}


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
