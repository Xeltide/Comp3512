#pragma once

#include "IceCream.h"

namespace assignment1
{
	class Blizzard : public IceCream
	{
	public:
		Blizzard(const char* name, unsigned int numScoops);
		Blizzard(const Blizzard& other);

		unsigned int GetCost() const;
		virtual bool HasCone();

	protected:
		virtual ~Blizzard();

	private:
		const unsigned int mToppingCost = 120;
	};
}