#include "Candy.h"

#include <cmath>

namespace assignment1
{
	Candy::Candy(const char* name, float weight)
		: Item(name)
		, mWeight(weight)
	{
	}

	Candy::Candy(const Candy& other)
		: Item(other)
	{
	}

	unsigned int Candy::GetCost() const
	{
		return (unsigned int)(mCostPerLb * mWeight);
	}
}