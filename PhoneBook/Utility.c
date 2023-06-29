#include "Utility.h"
#include <string.h>
void removeTrailingNewLine(char* buffer)
{
	buffer[strcspn(buffer, "\n")] = '\0';  
}