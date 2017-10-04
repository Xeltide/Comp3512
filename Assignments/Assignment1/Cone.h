#pragma once

#include "Item.h"

namespace assignment1
{
	class Cone
	{
	public:
		Cone();

		unsigned int GetCost() const;
	private:
		const unsigned int mCost = 10;
	};
}