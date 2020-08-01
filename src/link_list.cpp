#include "main.h"

struct LinkedList
{
	int data;
	struct LinkedList* next;
};

typedef struct LinkedList* node;	//define node for reducing syntax

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

node DelHead(node head) {
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

node DelTail(node head) {
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

node DelPos(node head, int position) {

}