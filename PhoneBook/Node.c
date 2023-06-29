#include "Node.h"
#include <stdlib.h> 
#include <string.h>
NODE* createNode(PERSON Person) 
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (!newNode)
		return NULL; 
	newNode->Person = Person;  
	newNode->next = NULL;  
	return newNode;  
}//user will check if node is null

PERSON getPerson(NODE* Node)
{
	return Node->Person;
}
void setPerson(NODE* Node, PERSON Person)
{
	Node->Person = Person; 
}
NODE* getNext(NODE* Node)
{
	return Node->next;
}
void setNext(NODE* Node, NODE* Next)
{
	Node->next = Next; 
}

void disposeNode(NODE* Node)
{
	free(Node); 
}
