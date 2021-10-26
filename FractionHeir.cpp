#include "FractionHeir.h"

bool FractionHeir::CheckResult(bool flag)
{
	double result = static_cast<double>(1.0 * GetNum() / GetDen());

	if (!flag)
	{
		if (abs(result) < 10000)
		{
			return false;
		}
		else
		{
			result = 10000;
			return true;
		}
	}
	else
	{
		return true;
	}
}

void FractionHeir::PrintResult(void)
{
	Fraction::PrintResult();
	if (flag)
	{
		std::cout << "*";
	}
}

FractionHeir::FractionHeir(const Fraction& frac) : Fraction(frac)
{
	this->flag = CheckResult(flag);
}

FractionHeir::FractionHeir(const int& num, const int& denom) : Fraction(num, denom)
{
	this->flag = CheckResult(flag);
}

FractionHeir::FractionHeir(double& fraction, bool flag) : Fraction(fraction)
{
	this->flag = CheckResult(flag);
}

FractionHeir::FractionHeir(int num, int denom, bool flag) : Fraction(num, denom)
{

	this->flag = CheckResult(flag);
}

FractionHeir operator + (FractionHeir fraction_1, FractionHeir fraction_2)
{
	bool flag = fraction_1.flag || fraction_2.flag;
	int num = (static_cast<Fraction>(fraction_1) + static_cast<Fraction>(fraction_2)).GetNum();
	int den = (static_cast<Fraction>(fraction_1) + static_cast<Fraction>(fraction_2)).GetDen();
	return FractionHeir(num, den, flag);
}

FractionHeir operator - (FractionHeir fraction_1, FractionHeir fraction_2)
{
	bool flag = fraction_1.flag || fraction_2.flag;
	int num = (static_cast<Fraction>(fraction_1) - static_cast<Fraction>(fraction_2)).GetNum();
	int den = (static_cast<Fraction>(fraction_1) - static_cast<Fraction>(fraction_2)).GetDen();
	return FractionHeir(num, den, flag);
}

FractionHeir operator * (FractionHeir fraction_1, FractionHeir fraction_2)
{
	bool flag = fraction_1.flag || fraction_2.flag;
	int num = (static_cast<Fraction>(fraction_1) * static_cast<Fraction>(fraction_2)).GetNum();
	int den = (static_cast<Fraction>(fraction_1) * static_cast<Fraction>(fraction_2)).GetDen();
	return FractionHeir(num, den, flag);
}

FractionHeir operator / (FractionHeir fraction_1, FractionHeir fraction_2)
{
	bool flag = fraction_1.flag || fraction_2.flag;
	int num = (static_cast<Fraction>(fraction_1) / static_cast<Fraction>(fraction_2)).GetNum();
	int den = (static_cast<Fraction>(fraction_1) / static_cast<Fraction>(fraction_2)).GetDen();
	return FractionHeir(num, den, flag);
}