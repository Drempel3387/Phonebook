#include "InputOutput.h"
#include "Utility.h"
#include <stdio.h>
#include <stdlib.h>
bool getStringTill(char* message, char* buffer, int size, int times)
{
	int count = 0;
	while (!getString(message, buffer, size) && ++count < times)
	{
		printf("Incorrect input, please try again\n");
	}
	if (count >= times)
		return false;
	removeTrailingNewLine(buffer); 
	return true; 
}
bool getString(char* message, char* buffer, int size)
{
	printf("%s", message);
	if (!fgets(buffer, size, stdin) || buffer[START] == '\n') 
		return false;
	return true; 
}
bool getInt(char* message, int* ret)
{
	char buffer[BUFSIZE]; 
	int num = 0;
	printf("%s", message);    
	if (!fgets(buffer, BUFSIZE, stdin) || sscanf(buffer, "%d", &num) != SCANNEDPROPERLY)    
		return false;
	*ret = num; 
	return true;
}
bool getIntTill(char* message, int* ret, int attempts)
{
	int count = 0; 
	while (!getInt(message, ret) && ++count < attempts)   
	{
		printf("Incorrect input, please try again\n"); 
	}
	if (count >= attempts) 
		return false;
	return true;
}
