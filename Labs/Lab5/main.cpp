#include "Lab5.h"
#include <iostream>


int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	int sum = lab5::Sum(v);
	int min = lab5::Min(v);
	int max = lab5::Max(v);
	float average = lab5::Average(v);
	int maxOccurrence = lab5::NumberWithMaxOccurrence(v);

	std::cout << sum << std::endl;
	std::cout << min << std::endl;
	std::cout << max << std::endl;
	std::cout << average << std::endl;
	std::cout << maxOccurrence << std::endl;
	system("pause");
}