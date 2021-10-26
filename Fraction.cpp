#include"Fraction.h"

int Fraction::GCD(long long int fraction, long long int divisor)
	{
		return divisor == 0 ? fraction : GCD(divisor, fraction % divisor);
	}

int Fraction::GetNum()
{
	return m_numerator;
}

int Fraction::GetDen()
{
	return m_denominator;
}

void Fraction::Reduction()
{
	if (m_numerator != 0)
	{
		int den = m_denominator,
			num = m_numerator,
			remainder = den % num;
		while (remainder != 0)
		{
			den = num;
			num = remainder;
			remainder = den % num;
		}
		double gcd = num;
		if (gcd != 1)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}
}

void Fraction::PrintResult()
{
	std::cout << m_numerator << "/" << m_denominator << " = " << static_cast<double>(1.0 * m_numerator / m_denominator);
}

Fraction::Fraction(int num, int den)
{
	m_numerator = num;
	m_denominator = den;
	Reduction();
}

Fraction::Fraction(double fraction)
{
	long int divisor = 1;
	int accuracy = fraction * 10000;
	while (accuracy / 10 != 0)
	{
		accuracy /= 10;
		fraction *= 10;
		divisor *= 10;
	}
	int gcd = GCD((long long int)fraction, divisor);
	m_numerator = fraction / gcd;
	m_denominator = divisor / gcd;
}

Fraction operator + (Fraction fraction_1, Fraction fraction_2)
{

	int n1d2 = fraction_1.m_numerator * fraction_2.m_denominator;
	int n2d1 = fraction_2.m_numerator * fraction_1.m_denominator;
	int d1d2 = fraction_1.m_denominator * fraction_2.m_denominator;
	return Fraction(n1d2 + n2d1, d1d2);
}

Fraction operator - (Fraction fraction_1, Fraction fraction_2)
{
	int n1d2 = fraction_1.m_numerator * fraction_2.m_denominator;
	int n2d1 = fraction_2.m_numerator * fraction_1.m_denominator;
	int d1d2 = fraction_1.m_denominator * fraction_2.m_denominator;
	return Fraction(n1d2 - n2d1, d1d2);
}

Fraction operator * (Fraction fraction_1, Fraction fraction_2)
{
	int n1n2 = fraction_1.m_numerator * fraction_2.m_numerator;
	int d1d2 = fraction_1.m_denominator * fraction_2.m_denominator;
	return Fraction(n1n2, d1d2);
}

Fraction operator / (Fraction fraction_1, Fraction fraction_2)
{
	int n1d2 = fraction_1.m_numerator * fraction_2.m_denominator;
	int n2d1 = fraction_2.m_numerator * fraction_1.m_denominator;
	return Fraction(n1d2, n2d1);
}