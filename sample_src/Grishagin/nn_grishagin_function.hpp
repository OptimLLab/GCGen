#pragma once

/* Two-dimensional multiextremal test function of Vladimir A. Grishagin

   See:  Grishagin, V.A., Operating Characteristics of Some Global Search Algorithms.
		 in: Problems in Random Search, Riga: Zinatne, 1978, issue 7, pp. 198--206;
   also: Strongin, R.G., and Sergeyev, Ya.D., Global Optimization with Non-Convex
		 Constraints: Sequential and Parallel Algorithms. Dordrecht: Kluwer, 2000.
*/

//#include "IOptProblem.hpp"
#include "grishagin_function.hpp"
#include "GrishaginOption.hpp"

class TNNGrishaginProblem : public TGrishaginProblem
{
protected:
	/// Compute the function number index at the point y
	double Compute(int index, const vector<double>& y) const override
	{
		int i, j;
		double d1, d2, sx1, cx1, sy1, cy1;
		double snx[7], csx[7], sny[7], csy[7];

		d1 = M_PI * y[0];
		d2 = M_PI * y[1];
		sx1 = sin(d1);
		cx1 = cos(d1);
		sy1 = sin(d2);
		cy1 = cos(d2);
		snx[0] = sx1;
		csx[0] = cx1;
		sny[0] = sy1;
		csy[0] = cy1;
		for (i = 0; i < 6; i++) {
			snx[i + 1] = snx[i] * cx1 + csx[i] * sx1;
			csx[i + 1] = csx[i] * cx1 - snx[i] * sx1;
			sny[i + 1] = sny[i] * cy1 + csy[i] * sy1;
			csy[i + 1] = csy[i] * cy1 - sny[i] * sy1;
		}
		d1 = 0;
		d2 = 0;
		for (i = 0; i < 7; i++)
			for (j = 0; j < 7; j++) {
				d1 = d1 + option.af[i][j] * snx[i] * sny[j] + option.bf[i][j] * csx[i] * csy[j];
				d2 = d2 + option.cf[i][j] * snx[i] * sny[j] - option.df[i][j] * csx[i] * csy[j];
			}
		return(-sqrt(d1 * d1 + d2 * d2)) - mOptimumValue;
	}

public:
	/// ProblemIndex is in the range [1,100]
	TNNGrishaginProblem(int problemIndex = 1) : TGrishaginProblem(problemIndex){}
};
