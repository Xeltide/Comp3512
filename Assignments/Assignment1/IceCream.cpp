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

	IceCream::IceCream(const IceCream& other)
		: IceCream(other.GetName().c_str(), other.mScoops)
	{
		if (other.mCone != NULL)
		{
			AddCone();
		}
	}

	IceCream::~IceCream()
	{
		if (mCone != NULL)
		{
			delete mCone;
		}
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