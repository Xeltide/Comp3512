#include "Donut.h"

#include <cmath>

namespace assignment1
{
	Donut::Donut(const char* name, unsigned int count)
		: Item(name)
		, mCount(count)
	{
	}

	unsigned int Donut::GetCost() const
	{
		return (unsigned int)round(mCount / 12.0 * mCostPerDz);
	}
}