#include "FixedVector.h"
#include <iostream>

int main()
{
	lab6::FixedVector<int, 10> numbers;
	numbers.Add(1);
	numbers.Add(2);

	std::cout << numbers[0] << std::endl;
	system("pause");

	return 0;
}