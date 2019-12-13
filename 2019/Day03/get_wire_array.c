#include "get_wire_array.h"

struct wireArrayStruct getWireArray(char *wire)
{
    struct wireArrayStruct tmpStruct;
    char *token;
    char **tmpWireArray;
    int counter = 0;

    token = strtok(wire, ",");

    tmpWireArray = malloc(1 * sizeof(char *));

    while (token != NULL)
    {
        tmpWireArray[counter] = malloc((4 + 1) * sizeof(char));
        tmpWireArray[counter] = token;
        token = strtok(NULL, ",");

        counter++;
    }

    tmpStruct.counter = counter;
    tmpStruct.tmpArray = tmpWireArray;

    return tmpStruct;
}
// void *getDirection (char token[]);
