#include "Vector.h"

#include <iostream>

int main()
{
	lab4::Vector a(4, -5, 6);
	lab4::Vector b(7, 2, -6);

	lab4::Vector sum = a + b;
	lab4::Vector difference = a - b;
	float dotProduct = a * b;
	lab4::Vector scalarProduct = a * 2;
	lab4::Vector scalarProduct2 = 2 * a;

	std::cout << difference[2] << std::endl;

	system("pause");
	return 0;
}