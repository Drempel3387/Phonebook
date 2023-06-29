#define _CRT_SECURE_NO_WARNINGS 
#define MAXINCORRECT 10
#define EXIT 4
#include <stdio.h>
#include <stdlib.h>
#include "InputOutput.h"
#include "Phonebook.h"
#include "List.h"
#include "Person.h"
#include "Node.h"
int main(void)
{
	//initialize phonebook and list structures
	LIST List; 
	initList(&List);
	PHONEBOOK Phonebook; 
	initPhonebook(&Phonebook, &List); 

	//load existing contacts from  the file
	FILE* fp;
	if ((fp = fopen("File.txt", "r")) == NULL)
	{
		fprintf(stderr, "Error opening file\n");
		exit(EXIT_FAILURE); 
	}
	loadContactsFromFile(&Phonebook, fp); 
	fclose(fp); 

	int action;
	printf("Welcome your phonebook contact management system!\n");
	printf("1: View all contacts\n2: Add a contact\n3: Delete a contact\n4: Exit the phonebook\n");
	getIntTill("Please enter the number of the action you would like to perform:", &action, MAXINCORRECT);
	while (action != EXIT)
	{
		switch (action)
		{
		case 1:
			showContacts(&Phonebook);
			break;
		case 2:
			addContact(&Phonebook); 
				break;
		case 3:
			deleteContact(&Phonebook);
			break;
		case 4:
			break;
		} 
		printf("\n1: View all contacts\n2: Add a contact\n3: Delete a contact\n4: Exit the phonebook\n"); 
		getIntTill("Please enter the number of the action you would like to perform:", &action, MAXINCORRECT); 
	}
	//save contacts to the file.
	if ((fp = fopen("File.txt", "w")) == NULL) 
	{
		fprintf(stderr, "Error opening file\n"); 
		exit(EXIT_FAILURE); 
	}
	saveContactsToFile(&Phonebook, fp); 
	fclose(fp); 
	return 0; 
}