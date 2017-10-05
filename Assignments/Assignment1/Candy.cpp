#include "Candy.h"

#include <cmath>

namespace assignment1
{
	Candy::Candy(const char* name, float weight)
		: Item(name)
		, mWeight(weight)
	{
	}

	unsigned int Candy::GetCost() const
	{
		return (unsigned int)round(mCostPerLb * mWeight);
	}
}