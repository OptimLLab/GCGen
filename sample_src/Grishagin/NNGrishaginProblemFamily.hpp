#pragma once

#include "nn_grishagin_function.hpp"
#include "IOptProblemFamily.hpp"

class TNNGrishaginProblemFamily : public IOptProblemFamily
{
public:
  TNNGrishaginProblemFamily() : IOptProblemFamily()
  {
    for (int i = 1; i <= 100; i++)
      pOptProblems.push_back(new TNNGrishaginProblem(i));
  }
};