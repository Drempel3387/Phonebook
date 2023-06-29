#pragma once
#define MIN 0//smallest index possible for insertion or deletion
#include "Node.h"
typedef struct
{
	int numberNodes;
	NODE* listHead; 
}LIST;
//initialize a list
void initList(LIST*);

//getters and setters
NODE* getHead(LIST*); 
void setHead(LIST*, NODE*); 
int getNumberNodes(LIST*);
void setNumberNodes(LIST*, int);

//list operations
void printList(LIST*);
bool printAt(LIST*, int);
bool insertAt(LIST*, NODE*, int);
bool deleteAt(LIST*, int);
void deleteList(LIST*);
