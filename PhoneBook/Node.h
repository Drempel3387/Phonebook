#pragma once
#define SAME 0
#include "Person.h"
typedef struct node
{
	PERSON Person; 
	struct node* next;
}NODE;

NODE* createNode(PERSON); 

PERSON getPerson(NODE*); 
void setPerson(NODE*, PERSON); 
NODE* getNext(NODE*);
void setNext(NODE*, NODE*); 
 

void disposeNode(NODE*);



