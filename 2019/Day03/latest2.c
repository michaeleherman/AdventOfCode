//    char str[res];
//
//    while (fscanf(filePtr, "%s\n", tmpStr) != EOF) {
//
//  main.c
//  AdventOfCode
//
//  Created by Michael Herman on 12/3/19.
//  Copyright © 2019 Michael Herman. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//    char str[res];
//
//    while (fscanf(filePtr, "%s\n", tmpStr) != EOF) {
//
//  main.c
//  AdventOfCode
//
//  Created by Michael Herman on 12/3/19.
//  Copyright © 2019 Michael Herman. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char * makeWireArray (wireArrayText) {
    int distance = 0;
    char direction = '\0';
    char **wireArray;
    char *token;

    wireArray = malloc(1 * sizeof(char *));
    //     char **orderedIds;

    // orderedIds = malloc(variableNumberOfElements * sizeof(char*));
    // for (int i = 0; i < variableNumberOfElements; i++)
    //     orderedIds[i] = malloc((ID_LEN+1) * sizeof(char)); // yeah, I know sizeof(char) is 1, but to make it clear..

    token = strtok(wireArrayText, ",");

    int maxR = 0;
    int maxL = 0;
    int maxU = 0;
    int maxD = 0;

    while (token != NULL)
    {
        //        strcpy(wireArray[counter], token);
        direction = token[0];
        char tmpDistance[4];
        distance = atoi(memcpy(tmpDistance, &token[1], 4));

        //Find the max distance for each direction
        if (direction == 'R' && direction > maxR)
        {
            maxR = direction;
        }
        else if (direction == 'L' && direction > maxL)
        {
            maxL = direction;
        }
        else if (direction == 'U' && direction > maxU)
        {
            maxU = direction;
        }
        else
        {
            if (direction > maxD)
            {
                maxD = direction;
            }
        }

        xLength = maxL + maxR;
        yLength = maxU + maxD;

        wireArray[counter] = malloc((4 + 1) * sizeof(char));
        wireArray[counter] = token;

//        printf("Token is %s\n", token);
//
//        for (int z = 0; z <= counter; z++)
//        {
//            printf("%d, %s\n", counter, wireArray[z]);
//        }

        token = strtok(NULL, ",");
        counter++;
    }
}

int main(int argc, const char *argv[])
{

    //Input file
    //    char fileName[60] = "/Users/Dad/Documents/Code/AdventOfCode/2019/Day03/input.txt";
    //    FILE *filePtr;
    //    filePtr = fopen(fileName,"r");
    char wires[2][40];
    strcpy(wires[0], "R75,D30,R83,U83,L12,D49,R71,U7,L72");
    strcpy(wires[1], "U62,R66,U55,R34,D71,R55,D58,R83");
    int counter = 0;
    int xLength = 0;
    int yLength = 0;

    wireArray0 = makeWireArray(wires[0]);
    wireArray1 = makeWireArray(wires[1]);
  
    int **matrix;
    matrix = malloc(1 * sizeof(int));
    
    int xPos = 0;
    int yPos = 0;
    
    
    for (int i = 0; i <= counter; i++)
    {
        matrix[i] = malloc((i+1) * sizeof(int));
        printf("Current value: %s\n", wireArray[i]);
        direction = wireArray[i][0];
        char tmpDistance[4];
        distance = atoi(memcpy(tmpDistance, &wireArray[i][1], 4));

        switch (direction)
        {
        case 'R':
           {
            for (int j = 0; j < 2; j++)
            {
                matrix[j] = malloc(2 * sizeof(int));
                matrix[i][j] =
                printf("%d,%d = %d\n",pos, yPos, matrix[pos][yPos]);
            }
            xPos = pos;
            break;}
        case 'L':
           { int pos = 0;
            for (pos = xPos; pos > xPos - distance; pos--)
            {
                matrix[pos][yPos] += 1;
                printf("%d,%d = %d\n",pos, yPos, matrix[pos][yPos]);
            }
            xPos = pos;
            break;}
        case 'U':
           { int pos = 0;
            for (pos = yPos; pos < yPos + distance; pos++)
            {
                matrix[xPos][pos] += 1;
                printf("%d,%d = %d\n",xPos, pos, matrix[xPos][pos]);
            }
            yPos = pos;
            break;}
        case 'D':
            {int pos = 0;
            for (pos = yPos; pos > yPos - distance; pos--)
            {
                matrix[xPos][pos] += 1;
                printf("%d,%d = %d\n",xPos, pos, matrix[xPos][pos]);
            }
            yPos = pos;
            break;}
        }
    }

    return 0;
}

