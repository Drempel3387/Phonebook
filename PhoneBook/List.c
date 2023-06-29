#include "List.h"
//initialize a list to be empty
void initList(LIST* List)
{
	List->listHead = NULL;  
	setNumberNodes(List, 0); 
}

//getters and setters
NODE* getHead(LIST* List)
{
	return List->listHead;
}
void setHead(LIST* List, NODE* head)
{
	List->listHead = head;
}
int getNumberNodes(LIST* List)
{
	return List->numberNodes;
}
void setNumberNodes(LIST* List, int number)
{
	List->numberNodes = number; 
}

void printList(LIST* List)
{
	NODE* current = getHead(List);
	int count = 1;
	while (current != NULL) 
	{
		printf("Contact %d:\n", count++); 
		printPerson(getPerson(current));  
		current = getNext(current);   
	} 
}

bool printAt(LIST* List, int position)
{
	if (position < MIN)//position not within the list
		return false;
	if (getHead(List) == NULL) 
		return false; //check if the list is empty

	NODE* current = getHead(List); 
	int count = 0;//current node position

	while (current != NULL && count++ < position)
	{
		current = getNext(current); 
	}
	if (current == NULL)
		return false;
	printPerson(getPerson(current)); 

	return true;
}
bool insertAt(LIST* List, NODE* newNode, int position) 
{
	if (position < MIN)
		return false;
	if (position == MIN)
	{
		setNext(newNode, getHead(List)); 
		setHead(List, newNode);
		setNumberNodes(List, getNumberNodes(List) + 1);
		return true;
	}//if insertion position is the head

	NODE* prev = getHead(List); //find the node before the insertion index  
	int count = 0;

	while (prev != NULL && ++count < position)
	{
		prev = getNext(prev); 
	}
	if (prev == NULL)
		return false;

	setNext(newNode, getNext(prev)); 
	setNext(prev, newNode); 
	setNumberNodes(List, getNumberNodes(List) + 1); 
	return true;
}
bool deleteAt(LIST* List, int position)
{
	NODE* current = getHead(List), * prev = NULL; 
	int count = 0;

	if (position < MIN)
		return false;
	if (position == MIN && getHead(List) != NULL) 
	{
		setHead(List, getNext(current)); 
		disposeNode(current);
		setNumberNodes(List, getNumberNodes(List) -1);
		return true;
	}
	if (position == MIN && getHead(List) == NULL) 
		return false;

	while (current != NULL && count++ < position)
	{
		prev = current;
		current = getNext(current); 
	}
	if (current == NULL)
		return false;

	setNext(prev, getNext(current)); 
	disposeNode(current);
	setNumberNodes(List, getNumberNodes(List) + -1);  
	return true;
}
void deleteList(LIST* List)
{
	NODE* current = getHead(List), * next;
	while (current->next != NULL)
	{
		next = current->next;
		disposeNode(current);
		current = next; 
	}
	disposeNode(current);
}
