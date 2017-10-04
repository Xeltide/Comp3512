#pragma once

#include <string>

namespace assignment1
{
	class Item
	{
	public:
		Item(const char* name);

		virtual unsigned int GetCost() const = 0;
		const std::string& GetName() const;

	protected:
		virtual ~Item();

	private:
		std::string mName;

		friend class ShoppingCart;
	};
}