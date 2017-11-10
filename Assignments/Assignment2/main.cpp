#include "Assignment2.h"

int main()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(1);

	std::vector<char> v2;
	v2.push_back('a');
	v2.push_back('b');
	v2.push_back('c');

	std::vector<int> v3;
	v3.push_back(4);
	v3.push_back(5);
	v3.push_back(6);

	std::map<char, int> m1;
	m1['a'] = 1;
	m1['b'] = 2;
	m1['c'] = 3;

	std::map<char, int> m2;
	m2['d'] = 4;
	m2['e'] = 5;
	m2['f'] = 6;

	std::map<int, char> m = assignment2::ConvertVectorsToMap(v1, v2);
	std::vector<char> keys = assignment2::GetKeys(m1);
	std::vector<int> values = assignment2::GetValues(m1);
	std::vector<int> reversedV1 = assignment2::Reverse(v1);
	std::vector<int> combinedVector = v1 + v3;
	std::map<char, int> combinedMap = m1 + m2;

	std::cout << combinedVector << std::endl;
	std::cout << m1 << std::endl;
	system("pause");

	return 0;
}