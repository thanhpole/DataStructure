#include "LinkedList.h"

node CreateNode(int value) {		//Function create first node
	node temp;						//this node temp has 2 value: data and pointer point to NULL
	temp = (node)malloc(sizeof(struct LinkedList));		//initialize the size of node in memory 
	temp->next = NULL;
	temp->data = value;
	return temp;					//return new node
}

node AddHead(node head, int value) {//Insert the new node to the first position of the list
	node temp = CreateNode(value);
	if (head==NULL)					//if there's no node, create a new list and add this node is the first node
	{
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
	return head;
}

node Append(node head, int value) {
	node temp, p;
	temp = CreateNode(value);
	if (head == NULL) {
		head = temp;
	}
	else
	{
		p = head;
		while (p->next!=NULL)		//search for the end of the lists
		{
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}

node AddAt(node head, int value, int position) {
	if (position==0 || head==NULL)	//check if there's no node
	{
		head = AddHead(head, value);
	}
	else
	{
		int k = 1;
		node p = head;
		while (p!=NULL&&k!=position)//searching for the pointer to insert
		{
			p = p->next;
			++k;					//counter by k
		}
		
		if (k!=position)			//check if position is available
		{
			head = Append(head, value);//insert at the end if there's no correct position
			printf_s("The position inputed is greater than the length of the list!");
		}
		else
		{
			node temp = CreateNode(value);
			temp->next = p->next;
			p->next = temp;
		}
	}
	return head;
}

node DelHead(node head) {			//Delete the first node
	if (head==NULL)
	{
		printf_s("No list to delete!");
	}
	else
	{
		head = head->next;
	}
	return head;
}

node DelTail(node head) {			//Delete the last node
	if (head==NULL || head->next==NULL)
	{
		return DelHead(head);
	}

	node p = head;
	while (p->next->next==NULL)
	{
		p = p->next;
	}
	p->next = NULL;
	return head;
}

node DelPos(node head, int position) {//Delete the pos's node
	if (position==0 || head==NULL || head->next==NULL)
	{
		head = DelHead(head);
	}
	else
	{
		int k = 1;
		node p = head;
		while (p->next->next!=NULL && k!=position)
		{
			p = p->next;
			++k;
		}

		if (k!=position)
		{
			head = DelTail(head);
		}
		else
		{
			p->next = p->next->next;
		}
	}
	return head;
}


int Get(node head, int index) {			//Get data in the node of the list
	int k = 0;
	node p = head;
	while (p->next != NULL && k != index)
	{
		++k;
		p = p->next;
	}
	return p->data;
}


int Search(node head, int value) {		//Searching the value in the list O(n)
	int pos = 0;
	for (node p = head; p != NULL; p=p->next)
	{
		if (p->data==value)
		{
			return pos;
		}
		++pos;
	}
	return -1;
}

node DelByVal(node head, int value) {	//Delete the node which have matched value
	int pos = Search(head, value);
	while (pos!=-1)
	{
		DelPos(head, pos);
		pos = Search(head, value);
	}
	return head;
}

void Traverser(node head) {				//Show all data in the list
	printf_s("\n");
	for (node p = head; p != NULL; p = p->next) {
		printf_s("%5d", p->data);
	}
}

node InitHead() {
	node head;
	head = NULL;
	return head;
}

int Length(node head) {					//print the length of the list
	int length = 0;
	for (node p = head; p != NULL; p = p->next) {
		++length;
	}
	return length;
}


node Input() {
	node head = InitHead();
	int n, value;
	do
	{
		printf_s("Enter the number of node: ");
		scanf_s("%d", &n);
	} while (n<=0);

	for (int i = 0; i < n; i++)
	{
		printf_s("Add new value: ");
		scanf_s("%d", &value);
		head = Append(head, value);
	}
	return head;
}