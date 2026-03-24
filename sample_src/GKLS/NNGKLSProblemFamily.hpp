#pragma once

#include "NNGKLSProblem.hpp"
#include "IOptProblemFamily.hpp"

class TNNGKLSProblemFamily : public IOptProblemFamily
{
public:
  TNNGKLSProblemFamily(int dim = 2, GKLSClass type = Simple, GKLSFuncionType functionType = TD) : IOptProblemFamily()
  {
    for (int i = 1; i <= 100; i++)
      pOptProblems.push_back(new TNNGKLSProblem(i,dim, type, functionType));
  }
};