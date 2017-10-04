#pragma once

#include "Item.h"

namespace assignment1
{
	class Cone;

	class IceCream : public Item
	{
	public:
		IceCream(const char* name, unsigned int numScoops);
		IceCream(const IceCream& other);
		virtual ~IceCream();

		unsigned int GetCost() const;
		void AddCone();

	private:
		Cone* mCone;

		unsigned int mScoops;
		const unsigned int mOzPerScoop = 2;
		const unsigned int mCostPerOz = 120;
	};
}