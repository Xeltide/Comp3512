#include "Blizzard.h"

#include <cmath>

namespace assignment1
{
	Blizzard::Blizzard(const char* name, unsigned int scoops)
		: IceCream(name, scoops)
	{
	}

	Blizzard::Blizzard(const Blizzard& other)
		: IceCream(other)
	{
	}

	Blizzard::~Blizzard()
	{
	}

	unsigned int Blizzard::GetCost() const
	{
		return IceCream::GetCost() + mToppingCost;
	}

	bool Blizzard::HasCone()
	{
		return IceCream::HasCone();
	}
}