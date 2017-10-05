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

		unsigned int GetCost() const;
		void AddCone();

	protected:
		virtual ~IceCream();

	private:
		Cone* mCone;

		unsigned int mScoops;
		const unsigned int mOzPerScoop = 2;
		const unsigned int mCostPerOz = 120;
	};
}