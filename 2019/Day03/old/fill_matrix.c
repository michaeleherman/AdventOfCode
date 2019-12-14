#include <stdlib.h>
#include <stdio.h>
#include "get_wire_array.h"
#include "fill_matrix.h"
#include "split_value.h"

struct matrixStruct fillmatrix(int xAxis, int yAxis, struct wireArrayStruct tmpStruct)
{
    struct matrixStruct tmpMatrixStruct;
    int *matrix = (int *)malloc(2 * sizeof(int));

    int x = 0;
    int y = 0;
    int i = 0;
    int counter = 0;

    int xLength = 0;
    int yLength = 0;

    for (int count = 0; count < tmpStruct.counter; count++)
    {
        struct DirDist tmpValue = splitDirDist(tmpStruct.tmpArray[count]);
        char direction = tmpValue.direction;
        int distance = tmpValue.distance;

        switch (direction)
        {
            case 'R':
            {

                for ( i = 0; i < distance; i++)
                {

                    *(matrix + 0) = i + x;
                    *(matrix + 1) = y;
                    counter++;
                    // printf("%d,%d\n", *(matrix + 0), *(matrix + 1));
                }
                x = i;
                break;
            }
            case 'L':
            {
                for ( i = 0; i < distance; i++)
                {

                    *(matrix + 0) = i - x;
                    *(matrix + 1) = x;
                    counter++;
                    // printf("%d,%d\n", *(matrix + 0), *(matrix + 1));
                }
                x = i;
                break;
            }
            case 'U':
            {
                for ( i = 0; i < distance; i++)
                {

                    *(matrix + 0) = x;
                    *(matrix + 1) = i + y;
                    counter++;
                    // printf("%d,%d\n", *(matrix + 0), *(matrix + 1));
                }
                y = i;
                break;
            }
            case 'D':
            {
                for ( i = 0; i < distance; i++)
                {

                    *(matrix + 0) = x;
                    *(matrix + 1) = y - i;
                    counter++;
                    // printf("%d,%d\n", *(matrix + 0), *(matrix + 1));
                }
                y = y - i;
                break;
            }
        }
    }
    tmpMatrixStruct.counter = counter;
    tmpMatrixStruct.matrixArray = &matrix;

    return tmpMatrixStruct;
}