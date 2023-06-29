#include "PhoneBook.h"
#include "InputOutput.h" 
void showContacts(PHONEBOOK* Phonebook)
{
	if (phonebookEmpty(Phonebook))
	{
		printf("No contacts in the system\n\n");
		return;
	}
	LIST* List = getList(Phonebook); 
	printList(List); 
}
void initPhonebook(PHONEBOOK* Phonebook, LIST* List)
{
	setList(Phonebook, List);
}
LIST* getList(PHONEBOOK* Phonebook)
{
	return Phonebook->contacts;
}
void setList(PHONEBOOK* Phonebook, LIST* List)
{
	Phonebook->contacts = List;
}

bool phonebookEmpty(PHONEBOOK* Phonebook)
{
	return (getNumberNodes(getList(Phonebook)) == 0);
}
bool addContact(PHONEBOOK* Phonebook)
{
	PERSON P;
	if (!makePerson(&P))
		return false; 

	NODE* contact = createNode(P); 
	if (!insertAt(getList(Phonebook), contact, getNumberNodes(getList(Phonebook))))
	{
		return false;
	}
	printf("Contact Added\n\n");
	return true;
}
bool deleteContact(PHONEBOOK* Phonebook)
{
	if (phonebookEmpty(Phonebook))
	{
		printf("No contacts to delete\n\n");
		return false; 
	}
	int count = 0, index;  
	printList(getList(Phonebook));
	if (!getIntTill("Please enter the contact number you would like to delete, or hit enter twice to cancel:", &index, ATTEMPTS)) 
		return false; 
	if (!deleteAt(getList(Phonebook), index -1))
		return false;
	
	printf("Contact deleted\n\n"); 
	return true; 
}

void saveContactsToFile(PHONEBOOK* Phonebook, FILE* Fileptr)
{
	NODE* current = getHead(getList(Phonebook));  
	while (current != NULL)
	{
		savePersonToFile(getPerson(current), Fileptr);
		current = getNext(current); 
	}
}
void loadContactsFromFile(PHONEBOOK* Phonebook, FILE* Fileptr)
{
	NODE* current = NULL; 
	PERSON P;
	 
	while (readPersonFromFile(Fileptr, &P))
	{
		current = createNode(P);  
		if (!insertAt(getList(Phonebook), current, getNumberNodes(getList(Phonebook))))
			return;
	}
}