#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct wireArrayStruct getWireArray(char *wire);

// struct wireArrayStruct {
//     int counter;
//     char **tmpArray;
// };

struct wirePoint {
    char direction;
    int distance;
}

struct wireArrayStruct getWireArray(char *wire)
{
    // struct wireArrayStruct tmpStruct;
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

    struct wirePoint points[counter];

    for (int i = 0; i<counter;i++){
        

    }

    tmpStruct.counter = counter;
    tmpStruct.tmpArray = tmpWireArray;

    return tmpStruct;
}
// void *getDirection (char token[]);
