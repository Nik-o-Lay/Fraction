#ifndef FRACTION_HEIR
#define FRACTION_HEIR

#include "Fraction.h"

class FractionHeir : public Fraction
{
private:

	bool flag{ 0 };
	bool CheckResult(bool flag);

public:

	void PrintResult(void);

	FractionHeir(const Fraction& frac);
	FractionHeir(const int& num, const int& denom);
	FractionHeir(double& fraction, bool flag);
	FractionHeir(int num, int denom, bool flag);
	
	friend FractionHeir operator + (FractionHeir, FractionHeir);
	friend FractionHeir operator - (FractionHeir, FractionHeir);
	friend FractionHeir operator * (FractionHeir, FractionHeir);
	friend FractionHeir operator / (FractionHeir, FractionHeir);
};

#endif FRACTION_HEIR