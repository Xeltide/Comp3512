#pragma once

namespace assignment1
{
	class Item;

	class ShoppingCart
	{
	public:
		ShoppingCart();
		ShoppingCart(const ShoppingCart& other) {}
		virtual ~ShoppingCart();

		bool AddItem(const Item* item);
		bool RemoveItem(unsigned int index);

		const Item* GetItem(unsigned int index) const;
		const Item* operator[](unsigned int index) const;

		float GetTotal() const;

	private:
		unsigned int mItemCount = 0;
		const Item** mContents;
		const unsigned int mMaxCount = 10;
	};
}