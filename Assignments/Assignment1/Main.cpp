#include "ShoppingCart.h"
#include "Donut.h"
#include "IceCream.h"

#include <iostream>

using namespace std;
using namespace assignment1;
int main()
{
	ShoppingCart* pCart = new ShoppingCart();
	
	Donut* pDonut = new Donut("Old Fashioned", 1);
	IceCream* pCream = new IceCream("Vanilla", 2);
	pCream->AddCone();

	pCart->AddItem(pDonut);
	pCart->AddItem(pCream);

	cout << pCart->GetTotal() << endl;
	pCart->RemoveItem(0);
	cout << pCart->GetItem(0)->GetName() << endl;
	cout << (*pCart)[0]->GetName() << endl;
	cout << pCart->GetTotal() << endl;
	pCart->RemoveItem(0);
	system("pause");

	return 0;
}
