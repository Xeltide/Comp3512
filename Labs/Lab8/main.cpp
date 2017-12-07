#include "Storage.h"
#include <utility>

int main()
{
	// using move constructor
	lab8::Storage<int> storage1(10000);
	lab8::Storage<int> storage1Copy(std::move(storage1)); // storage1's memory should be nulled/zeroed

	// using assignment operator
	lab8::Storage<char> storage2(20000);
	lab8::Storage<char> storage2Copy(3);
	storage2Copy = std::move(storage2); // storage2's memory should be nulled/zeroed

	// using regular copy constructor
	lab8::Storage<double> storage3(10000000);
	lab8::Storage<double> storage3Copy(storage3); // storage3 still has it's own data

	return 0;
}