#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputparser.h"

struct opcodes parse()
{
    char str[] = "3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0";
    opcodes parsedString;
    char *token = strtok(str, ",");
    int counter = 0;
    int pos = 0;

    int *intCodes = malloc(1 * sizeof(int));
    while (token != NULL)
    {
        intCodes[counter] = atoi(token);
        intCodes = realloc(intCodes, (counter + 2) * sizeof(int));

        token = strtok(NULL, ",");
        counter++;
    }

    parsedString.intcodes = intCodes;
    parsedString.size = counter;

    return parsedString;

}
