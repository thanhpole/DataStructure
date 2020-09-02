#ifndef LinkedList_H
#define LinkedList_H

#include"main.h"

struct LinkedList
{
	int data;
	struct LinkedList* next;
};

typedef struct LinkedList* node;	//define node for reducing syntax

node CreateNode(int value);
node AddHead(node head, int value);
node Append(node head, int value);
node AddAt(node head, int value, int position);
node DelHead(node head);
node DelTail(node head);
node DelPos(node head, int position);
int Get(node head, int index);
int Search(node head, int value);
node DelByVal(node head, int value);
void Traverser(node head);
node InitHead();
int Length(node head);
node Input();

#endif