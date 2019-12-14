
//  main.c
//  AdventOfCode
//
//  Created by Michael Herman on 12/3/19.
//  Copyright © 2019 Michael Herman. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "split_value.h"

int main()
{

    // read the file line by line
    // assign each line to a char*
    // turn strings into arrays
    // calculate matrix size
    // for each item in array, fill matrix

    char wires0[] = "R75,D30,R83,U83,L12,D49,R71,U7,L72";
    char wires1[] = "U62,R66,U55,R34,D71,R55,D58,R83";
    char *token;
    int counter = 0;
    int *matrix = (int *)malloc(2 * sizeof(int));
    int xCoordinate = 0;
    int yCoordinate = 0;

    token = strtok(wires0, ",");

    printf("x, y: %d, %d\n", xCoordinate, yCoordinate);

    while (token != NULL)
    {

        printf("Token is %s\n", token);
        struct DirDist tmpDisDist = splitDirDist(token);
        char direction = tmpDisDist.direction;
        int distance = tmpDisDist.distance;
        printf("Distance: %d\n", distance);

        for (int i = 0; i < distance; i++)
        {
            *(matrix + i) = xCoordinate;
            *(matrix + i + 1) = yCoordinate;
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

            printf("Coordinates x,y: %d, %d\n", xCoordinate, yCoordinate);
        }

        token = strtok(NULL, ",");
        counter++;
    }

    //Resest everything
    int xCoordinate = 0;
    int yCoordinate = 0;
    char *token;
    int counter = 0;

    token = strtok(wires1, ",");

    while (token != NULL)
    {

        printf("Token is %s\n", token);
        struct DirDist tmpDisDist = splitDirDist(token);
        char direction = tmpDisDist.direction;
        int distance = tmpDisDist.distance;
        printf("Distance: %d\n", distance);

        for (int i = 0; i < distance; i++)
        {  

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

            printf("Coordinates x,y: %d, %d\n", xCoordinate, yCoordinate);
        }

        token = strtok(NULL, ",");
        counter++;
    }

    return 0;
}
