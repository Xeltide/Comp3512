#include "Donut.h"

#include <cmath>

namespace assignment1
{
	Donut::Donut(const char* name, unsigned int count)
		: Item(name)
		, mCount(count)
	{
	}

	Donut::~Donut() {}

	unsigned int Donut::GetCost() const
	{
		return (unsigned int)(mCount / 12.0 * mCostPerDz);
	}
}