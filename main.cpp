#include <iostream>
#include "Fraction.h"
#include "FractionHeir.h"

int main()
{
	FractionHeir frac_1(3000.15);
	frac_1.PrintResult();

	std::cout << "\n";

	FractionHeir frac_2(12000);
	frac_2.PrintResult();

	std::cout << "\n";

	FractionHeir frac_3 = (frac_2 - frac_1);
	frac_3.PrintResult();

	std::cout << "\n";

	(frac_3 - frac_1).PrintResult();

	return 0;
}