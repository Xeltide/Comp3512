#include "ShoppingCart.h"
#include "Item.h"
#include "Donut.h"

#include <iostream>
namespace assignment1
{
	ShoppingCart::ShoppingCart()
	{
		mContents = new const Item*[10];
	}

	ShoppingCart::~ShoppingCart()
	{
		for (unsigned int i = 0; i < mItemCount; i++)
		{
			delete mContents[i];
		}
		delete mContents;
	}

	bool ShoppingCart::AddItem(const Item* item)
	{
		if (mItemCount < mMaxCount && item != NULL)
		{
			mContents[mItemCount] = item;
			mItemCount++;
			return true;
		}
		return false;
	}

	bool ShoppingCart::RemoveItem(unsigned int index)
	{
		if (mItemCount > index)
		{
			delete mContents[index];
			for (unsigned int i = index; i < mItemCount - 1; i++)
			{
				mContents[i] = mContents[i + 1];
			}
			mItemCount--;
			return true;
		}
		return false;
	}

	const Item* ShoppingCart::GetItem(unsigned int index) const
	{
		if (mItemCount > index)
		{
			return mContents[index];
		}
		return NULL;
	}

	const Item* ShoppingCart::operator[](unsigned int index) const
	{
		if (mItemCount > index)
		{
			return mContents[index];
		}
		return NULL;
	}

	float ShoppingCart::GetTotal() const
	{
		float sum = 0;
		for (unsigned int i = 0; i < mItemCount; i++)
		{
			sum += mContents[i]->GetCost();
		}
		return sum / 100;
	}
}