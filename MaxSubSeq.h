#ifndef ___MAXSUBSEQ__H__
#define __MAXSUBSEQ__H__

#include <vector>
#include <iostream>

class MaxSubSeq
{
      public:
              std::pair<int, int> fuerzaBruta();
              
      private:
              int numPeriodos;
              std::vector<int>valores;
              std::vector<int>derivadas;            
 };
 
 #endif
