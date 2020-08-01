#include"main.h"

int main() {
	std::cout << "\n Create a new Linked List";
	node head = Input();
	Traverser(head);

	std::cout << "\n Add new node to Linked List\n";
	head = AddAt(head, 100, 4);
	Traverser(head);

	std::cout << "\n Delete a node from Linked List\n";
	head = DelPos(head, 6);
	Traverser(head);

	for (int i = 0; i < Length(head); i++)
	{
		std::cout << "\n Node " << i << " has value: " << Get(head, i);
	}
}