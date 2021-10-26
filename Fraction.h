#ifndef FRACTION
#define FRACTION

#include <iostream>
#include<cmath>

class Fraction
{
private:

	int m_numerator, m_denominator;
	int GCD(long long int fraction, long long int divisor);

	void Reduction();

public:

	int GetNum();
	int GetDen();
	
	void PrintResult();	

	Fraction(int num, int den);
	Fraction(double fraction);
	
	friend Fraction operator + (Fraction, Fraction);
	friend Fraction operator - (Fraction, Fraction);
	friend Fraction operator * (Fraction, Fraction);
	friend Fraction operator / (Fraction, Fraction);
};

#endif FRACTION