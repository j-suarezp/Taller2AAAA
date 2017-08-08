#include <tuple>
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


std::tuple<int, int, int> MaxSubSeq::fuerzaBruta()
{
  int inicioMax, finMax, valorMax;
  valorMax = -2147483647;
  
  for(int i = 0; i < this->numPeriodos; i++ )
  {
    for(int j = i; j < this->numPeriodos; j++)
    {
      if( (this->valores[j] - this->valores[i]) >= valorMax)
      {
        inicioMax = i;
        finMax = j;
        valorMax = (this->valores[j] - this->valores[i]);
      }
    }
  }
  
  
  
  return std::make_tuple(inicioMax, finMax, valorMax);
}

std::tuple<int, int, int> MaxSubSeq::findMaxCrossSub(int l, int m, int h)
{
	int vl, vr;
	vl = vr = -2147483647;
	int s = 0;
	int ml, mr;

	for(int i = m; i >= l; i--)
	{
		s = s + this->derivadas[i];
		if(s >= vl)
		{
			vl = s;
			ml = i;
		}
	}

	s = 0;

	for(int i = m + 1; i <= h; i++)
	{
		s = s + this->derivadas[i];
		if(s >= vr)
		{
			vr = s;
			mr = i;
		}
	}
	
	return( std::make_tuple(ml, mr, vl + vr) );
}

std::tuple<int, int, int> MaxSubSeq::findMaxSubArray(int l, int h)
{
	if(h <= l)
		return(std::make_tuple(l, h, this->derivadas[l]));
	else
	{
		int m = ((l + h)/2);
		std::tuple<int, int, int> tl = findMaxSubArray(l, m);
		std::tuple<int, int, int> tr = findMaxSubArray(m + 1, h);
		std::tuple<int, int, int> tc = findMaxCrossSub(l, m, h);
		if( (std::get<2>(tl) >= std::get<2>(tr)) && (std::get<2>(tl) >= std::get<2>(tc)) )
		{
			return(tl);
		}else if((std::get<2>(tr) >= std::get<2>(tl)) && (std::get<2>(tr) >= std::get<2>(tc)))
			{
				return(tr);
			}
			else
			{
				return(tc);
			}
	}
	
}
