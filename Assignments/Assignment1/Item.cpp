#include "Item.h"

namespace assignment1
{
	Item::Item(const char* name)
		: mName(name)
	{
	}

	Item::~Item()
	{
	}

	const std::string& Item::GetName() const
	{
		return mName;
	}
}