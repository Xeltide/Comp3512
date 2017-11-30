#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"

using namespace lab7;

int main()
{
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));

	list.Delete(3);
	list.Insert(std::make_unique<int>(1), 2);
	list.Delete(4);
	list.Delete(1);
	list.Insert(std::make_unique<int>(1), 0);

	bool bExists = list.Search(1);
	unsigned int size = list.GetLength();
	std::shared_ptr<Node<int>> node = list[0];
	std::cout << list.GetLength() << std::endl;
	system("pause");

	return 0;
}
