#include "ShoppingCart.h"
#include "Donut.h"
#include "IceCream.h"
#include "Blizzard.h"
#include "Candy.h"

#include <iostream>

using namespace std;
using namespace assignment1;
int main()
{
	ShoppingCart cart;

	Item* blizzard = new Blizzard("Smarties Blizzard", 3);
	Item* candy = new Candy("Gummy Bears", 2.5f);
	Item* donut = new Donut("Canadian Maple", 4);
	IceCream* icecream = new IceCream("Vanilla", 2);

	icecream->AddCone();

	cart.AddItem(blizzard);
	cart.AddItem(candy);
	cart.AddItem(donut);
	cart.AddItem(icecream);

	cout << cart.GetTotal() << endl;
	system("pause");

	return 0;
}