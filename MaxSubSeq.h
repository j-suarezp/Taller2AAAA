#ifndef ___MAXSUBSEQ__H__
#define __MAXSUBSEQ__H__

#include <vector>
#include <iostream>

class MaxSubSeq
{
      public:
				std::tuple<int, int, int> fuerzaBruta();
				std::tuple<int, int, int> findMaxCrossSub(int l, int m, int h);
				std::tuple<int, int, int> findMaxSubArray(int l, int h);
				void inicializar(int n);
				std::vector<int> getValores();
				std::vector<int> getDerivadas();

      private:
              int numPeriodos;
              std::vector<int>valores;
              std::vector<int>derivadas;            
 };
 
 #endif
