#include <iostream>
#include "Manipulations.h"

int main()
{
	Complex one(1,0),
		two(2,0),
		unit(1,1),
		sample(4,-5),
		i = Complex::GetI();

	std::cout << (one.Real() == 1) << std::endl; // true;
	std::cout << (i.Imaginary() == 0) << std::endl; // false;

	std::cout << one + two; // 3
	std::cout << two - one; // 1
	std::cout << sample + i; // 4 - 4i
	std::cout << one * i; // 0 + i
	std::cout << one / i; // 0 - i;

	std::cout << two.Modulus() << std::endl;
	std::cout << one.IsReal() << std::endl;
	std::cout << unit.Argument() << std::endl;
	std::cout << sample.Conjugate();

	std::cout << one.Root(2, 0); // 1
	std::cout << one.Root(2, 1); // -1
	std::cout << one.Root(4, 1); // 0 + i
	std::cout << i.Power(2); // -1
	std::cout << (i ^ 2); // -1

	std::cout << (i == Complex(0, 1)) << std::endl; // true
	std::cout << (unit == one + i) << std::endl; // true
	std::cout << (sample != i) << std::endl; // true

	system ("pause");
	return 0;
}