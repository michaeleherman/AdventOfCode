#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct wireArrayStruct getWireArray(char *wire);
struct wireArrayStruct {
    int counter;
    char **tmpArray;
};

struct wireArrayStruct getWireArray(char *wire)
{
    struct wireArrayStruct tmpStruct;
    char *token;
    static char **tmpWireArray;
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

    printf("size of wirearray %lu\n", sizeof(tmpWireArray[0]));

    for (int i = 0; i < counter; i++)
    {
        printf("%d, %s\n", i, tmpWireArray[i]);
    }

    tmpStruct.counter = counter;
    tmpStruct.tmpArray = tmpWireArray;

    return tmpStruct;
}
// void *getDirection (char token[]);
