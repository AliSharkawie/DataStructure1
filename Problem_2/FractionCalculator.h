#ifndef FRACTIONCALCULATOR_H
#define FRACTIONCALCULATOR_H
#include "Fraction.h"
#include <vector>

class FractionCalculator
{
	Fraction f1,f2 ;
	vector<Fraction> saved ;
	public:
		FractionCalculator();
		void viewResults() ;
		~FractionCalculator();
	protected:
};

#endif
