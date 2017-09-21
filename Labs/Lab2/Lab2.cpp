#include "Lab2.h"

#include <string>
#include <iomanip>

using namespace std;

namespace lab2 {
	void PrintIntegers(std::istream& in, std::ostream& out) {
		int number;
		out << setw(12) << right << "oct"
			<< setw(11) << right << "dec"
			<< setw(10) << right << "hex" << std::endl;
		out << setw(12) << right << "------------"
			<< setw(11) << right << "----------"
			<< setw(10) << right << "---------" << std::endl;
		while (!in.eof()) {
			in >> number;
			if (!in.fail()) {
				out << setw(12) << right << oct << number
					<< setw(11) << right << dec << number
					<< setw(10) << right << hex << uppercase << number << endl;
			}
			else {
				in.clear();
				in.ignore();
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out) {
		float number;
		float max = numeric_limits<float>::min();
		do {
			in >> number;
			if (!in.fail()) {
				if (number > max) {
					max = number;
				}
				out << setw(5) << ""
					<< setw(15) << internal << setprecision(3) << showpos << showpoint << fixed << number << endl;
			}
			else {
				in.clear();
				in.ignore();
			}
		} while (!in.eof());
		out << setw(5) << "max:"
			<< setw(15) << internal << setprecision(3) << showpos << showpoint << fixed << max << endl;
	}
}