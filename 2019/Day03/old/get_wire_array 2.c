#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_wire_array.h"
#include "split_value.h"

struct wireArrayStruct getWireArray(char wire[])
{
    struct wireArrayStruct tmpStruct;
    char *token;
    int counter = 0;
    int **matrix = (int **)malloc(1 * sizeof(int *));
    int xCoordinate = 0;
    int yCoordinate = 0;
    int pointsCounter = 0;

    token = strtok(wire, ",");

    // printf("x, y: %d, %d\n", xCoordinate, yCoordinate);

    while (token != NULL)
    {

        // printf("Token is %s\n", token);
        struct DirDist tmpDisDist = splitDirDist(token);
        char direction = tmpDisDist.direction;
        int distance = tmpDisDist.distance;
        // printf("Distance: %d\n", distance);

        for (int i = 0; i < distance; i++)
        {
            int **tmp = realloc(matrix, (pointsCounter + 1) * sizeof(tmp));
            matrix = tmp;
            matrix[pointsCounter] = (int *)malloc(3 * sizeof(int));
            // printf("Allocated more memory for matrix %d\n",pointsCounter);
            matrix[pointsCounter][0] = xCoordinate;
            matrix[pointsCounter][1] = yCoordinate;
            matrix[pointsCounter][2] = pointsCounter;
            // printf("%s matrix values just inserted: %d, %d\n",token, matrix[pointsCounter][0],matrix[pointsCounter][1]);
            switch (direction)
            {
            case 'R':
                xCoordinate++;
                break;
            case 'D':
                yCoordinate--;
                break;
            case 'U':
                yCoordinate++;
                break;
            case 'L':
                xCoordinate--;
                break;
            }

            // printf("Coordinates x,y: %d, %d\n", xCoordinate, yCoordinate);
            pointsCounter++;
        }

        token = strtok(NULL, ",");
        counter++;
    }

    tmpStruct.tmpArray = matrix;
    tmpStruct.counter = counter;

    return tmpStruct;
}
// void *getDirection (char token[]);
