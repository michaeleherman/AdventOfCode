#include <stdlib.h>
#include <stdio.h>
#include "get_wire_array.h"
#include "fill_matrix.h"
#include "split_value.h"



void fillmatrix(int xAxis, int yAxis, struct wireArrayStruct tmpStruct)
{
    int matrix[xAxis][yAxis];

    int xPos = 0;
    int yPos = 0;

    int xLength = 0;
    int yLength = 0;

    for (int i = 0; i < tmpStruct.counter; i++)
    {
        struct DirDist tmpValue = splitDirDist(tmpStruct.tmpArray[i]);
        char direction = tmpValue.direction;
        int distance = tmpValue.distance;

        switch (direction)
        {
        case 'R':
        {
            int pos = 0;
            for (pos = xPos; pos < xPos + distance; pos++)
            {
                matrix[pos][yPos] += 1;
                printf("%d,%d = %d\n", pos, yPos, matrix[pos][yPos]);
            }
            xPos = pos;
            break;
        }
        case 'L':
        {
            int pos = 0;
            for (pos = xPos; pos > xPos - distance; pos--)
            {
                matrix[pos][yPos] += 1;
                printf("%d,%d = %d\n", pos, yPos, matrix[pos][yPos]);
            }
            xPos = pos;
            break;
        }
        case 'U':
        {
            int pos = 0;
            for (pos = yPos; pos < yPos + distance; pos++)
            {
                matrix[xPos][pos] += 1;
                printf("%d,%d = %d\n", xPos, pos, matrix[xPos][pos]);
            }
            yPos = pos;
            break;
        }
        case 'D':
        {
            int pos = 0;
            for (pos = yPos; pos > yPos - distance; pos--)
            {
                matrix[xPos][pos] += 1;
                printf("%d,%d = %d\n", xPos, pos, matrix[xPos][pos]);
            }
            yPos = pos;
            break;
        }
        }
    }

    printf("HIT THE END!");
}