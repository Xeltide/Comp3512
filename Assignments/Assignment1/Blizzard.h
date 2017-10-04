#pragma once

#include "IceCream.h"

namespace assignment1
{
	class Blizzard : public IceCream
	{
	public:
		Blizzard(const char* name, unsigned int numScoops);
		Blizzard(const Blizzard& other);
		virtual ~Blizzard();

		unsigned int GetCost() const;

	private:
		const unsigned int mToppingCost = 120;
	};
}