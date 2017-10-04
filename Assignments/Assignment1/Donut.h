#pragma once

#include "Item.h"

namespace assignment1
{
	class Donut : public Item
	{
	public:
		Donut(const char* name, unsigned int count);
		Donut(const Donut& other);
		~Donut();

		unsigned int GetCost() const;

	private:
		unsigned int mCount;
		const unsigned int mCostPerDz = 899;
	};
}