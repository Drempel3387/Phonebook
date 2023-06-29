#include "Person.h"
#include "Utility.h"
#include "InputOutput.h"
#include <stdlib.h>
#include <string.h>
PERSON createPerson(char* First, char* Last, char* Email, char* PhoneNumber)
{
	PERSON p; 
	setFirst(&p, First); 
	setLast(&p, Last); 
	setEmail(&p, Email); 
	setPhoneNumber(&p, PhoneNumber); 
	return p; 
}
bool makePerson(PERSON* Person)
{
	char First[NAMESIZE], Last[NAMESIZE], Email[EMAILSIZE], Number[NUMBERSIZE];
	printf("You have two attempts to enter the information, if you would like to quit, hit enter twice\n");
	if (!getStringTill("Please enter the contact's first name: ", First, NAMESIZE, ATTEMPTS))
		return false;
	if (!getStringTill("Please enter the contact's last name: ", Last, NAMESIZE, ATTEMPTS))
		return false;
	if (!getStringTill("Please enter the contact's email: ", Email, EMAILSIZE, ATTEMPTS))
		return false;
	if (!getStringTill("Please enter the contact's phone number: ", Number, NUMBERSIZE, ATTEMPTS))
		return false;
	*Person = createPerson(First, Last, Email, Number); 
	return true; 
}
void printPerson(PERSON Person) 
{
	printf("First name: %s\n", getFirst(Person)); 
	printf("Last name: %s\n", getLast(Person)); 
	printf("Email: %s\n", getEmail(Person)); 
	printf("Phone Number: %s\n\n", getPhoneNumber(Person));  
}

//getters and setters
char* getFirst(PERSON Person)
{
	return Person.first;
}
char* getLast(PERSON Person)
{
	return Person.last;
}
char* getEmail(PERSON Person)
{
	return Person.email;
}
char* getPhoneNumber(PERSON Person)
{
	return Person.phoneNumber;
}

void setFirst(PERSON* Person, char* First)
{
	strncpy(Person->first, First, NAMESIZE); 
	Person->first[NAMESIZE - 1] = '\0';
}
void setLast(PERSON* Person, char* Last)
{
	strncpy(Person->last, Last, NAMESIZE); 
	Person->last[NAMESIZE - 1] = '\0'; 
}
void setEmail(PERSON* Person, char* Email)
{
	strncpy(Person->email, Email, EMAILSIZE); 
	Person->email[EMAILSIZE - 1] = '\0';  
}
void setPhoneNumber(PERSON* Person, char* PhoneNumber)
{
	strncpy(Person->phoneNumber, PhoneNumber, NUMBERSIZE); 
	Person->phoneNumber[NUMBERSIZE - 1] = '\0';    
}

//file handling
void savePersonToFile(PERSON Person, FILE* fp)  
{
	fprintf(fp,"%s\n", getFirst(Person));   
	fprintf(fp, "%s\n", getLast(Person));  
	fprintf(fp, "%s\n", getEmail(Person));  
	fprintf(fp, "%s\n", getPhoneNumber(Person));    
}
bool readPersonFromFile(FILE* fp, PERSON* person)
{
	PERSON Person;
	char First[NAMESIZE], Last[NAMESIZE], Email[EMAILSIZE], Number[NUMBERSIZE]; 
	
	if (!fgets(First, NAMESIZE, fp) || !fgets(Last, NAMESIZE, fp)|| !fgets(Email, EMAILSIZE, fp) || !fgets(Number, NUMBERSIZE, fp))
		return false; 

	removeTrailingNewLine(First);   
	removeTrailingNewLine(Last);   
	removeTrailingNewLine(Email);  
	removeTrailingNewLine(Number);   

	setFirst(&Person, First); 
	setLast(&Person, Last); 
	setEmail(&Person, Email); 
	setPhoneNumber(&Person, Number); 
	*person = Person;
	return true; 
}
