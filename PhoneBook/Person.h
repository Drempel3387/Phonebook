#pragma once 
#define _CRT_SECURE_NO_WARNINGS
#define ATTEMPTS 2
#define NAMESIZE 20
#define EMAILSIZE 30
#define NUMBERSIZE 15
#include <stdio.h> 
#include <stdbool.h>  

typedef struct 
{
	char first[NAMESIZE];
	char last[NAMESIZE];
	char email[EMAILSIZE];
	char phoneNumber[NUMBERSIZE];  
}PERSON; 

PERSON createPerson(char*, char*, char*, char*); 
bool makePerson(PERSON*);
void printPerson(PERSON); 

//getters
char* getFirst(PERSON);
char* getLast(PERSON);
char* getEmail(PERSON);
char* getPhoneNumber(PERSON); 

//setters
void setFirst(PERSON*, char*); 
void setLast(PERSON*, char*);
void setEmail(PERSON*, char*);
void setPhoneNumber(PERSON*, char*);

//file handling
void savePersonToFile(PERSON, FILE*); 
bool readPersonFromFile(FILE*, PERSON*); 