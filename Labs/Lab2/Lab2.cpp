#include "Lab2.h"

#include <string>
#include <iomanip>

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int number;
		out << setw(12) << right << "oct"
			<< setw(11) << "dec"
			<< setw(9) << "hex" << std::endl;
		out << setw(12) << "------------"
			<< setw(11) << "----------"
			<< setw(9) << "--------" << std::endl;
		while (!in.eof())
		{
			in >> number;
			if (!in.fail())
			{
				out << setw(12) << oct << number
					<< setw(11) << dec << number
					<< setw(9) << hex << uppercase << number << endl;
			}
			else
			{
				in.clear();
				in.ignore();
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float number;
		float max = numeric_limits<float>::min();
		do
		{
			in >> number;
			if (!in.fail())
			{
				if (number > max)
				{
					max = number;
				}
				out << setw(5) << ""
					<< setw(15) << internal << setprecision(3) << showpos << showpoint << fixed << number << endl;
			}
			else
			{
				in.clear();
				in.ignore();
			}
		}
		while (!in.eof());
		out << setw(5) << left << "max:"
			<< setw(15) << internal << setprecision(3) << showpos << showpoint << fixed << max << endl;
	}
}