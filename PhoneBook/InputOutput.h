#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define START 0
#define SCANNEDPROPERLY 1
#define BUFSIZE 10
#include <stdbool.h>

bool getStringTill(char*, char*, int, int);
bool getString(char*, char*, int);
bool getInt(char*, int*);
bool getIntTill(char*, int*, int);



