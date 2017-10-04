#include "IceCream.h"
#include "Cone.h"

#include <cmath>

namespace assignment1
{
	IceCream::IceCream(const char* name, unsigned int scoops)
		: Item(name)
		, mCone(NULL)
		, mScoops(scoops)
	{
	}

	unsigned int IceCream::GetCost() const
	{
		if (mCone != NULL)
		{
			return (mScoops * mOzPerScoop * mCostPerOz) + mCone->GetCost();
		}
		else
		{
			return mScoops * mOzPerScoop * mCostPerOz;
		}
	}

	void IceCream::AddCone()
	{
		if (mCone == NULL)
		{
			mCone = new Cone();
		}
	}
}