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
	Item* clone = new Blizzard(*static_cast<Blizzard*>(blizzard));
	static_cast<Blizzard*>(blizzard)->AddCone();

	icecream->AddCone();

	cart.AddItem(blizzard);
	cart.AddItem(candy);
	cart.AddItem(donut);
	cart.AddItem(icecream);
	cart.AddItem(clone);

	cart.RemoveItem(0);

	cout << cart[0]->GetCost() << endl;
	cout << cart[1]->GetCost() << endl;
	cout << cart[2]->GetCost() << endl;
	cout << cart[3]->GetCost() << endl;
	cout << cart.GetTotal() << endl;
	system("pause");

	return 0;
}
