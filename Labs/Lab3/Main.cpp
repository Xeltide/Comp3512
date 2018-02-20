#include <iostream>

#include "TimeSheet.h"

using namespace lab3;

int main()
{
	TimeSheet* sheet = new TimeSheet("Bob", 3);
	sheet->AddTime(3);
	TimeSheet* copy = new TimeSheet(*sheet);
	sheet->AddTime(1);

	std::cout << sheet->GetTotalTime() << std::endl;
	std::cout << copy->GetTotalTime() << std::endl;

	return 0;
};
