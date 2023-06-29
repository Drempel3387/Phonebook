#pragma once
#include "List.h"
typedef struct 
{
	LIST* contacts; 
}PHONEBOOK;
void initPhonebook(PHONEBOOK* Phonebook, LIST* List);
LIST* getList(PHONEBOOK* Phonebook);
void setList(PHONEBOOK* Phonebook, LIST* List);

bool phonebookEmpty(PHONEBOOK*);
void showContacts(PHONEBOOK*);  
bool addContact(PHONEBOOK* Phonebook); 
bool deleteContact(PHONEBOOK* Phonebook);
void saveContactsToFile(PHONEBOOK* Phonebook, FILE* Fileptr);
void loadContactsFromFile(PHONEBOOK* Phonebook, FILE* Fileptr);