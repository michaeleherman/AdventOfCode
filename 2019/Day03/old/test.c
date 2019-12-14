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

struct element
{
    char direction;
    int distance;
};

struct element getDirection(char *token);

int main()
{

    struct element myData = {0};

    char *testString = "L123";

    printf("in main\n");

    myData = getDirection(testString);
    // getDirection(testString);

    printf("Returned structure values: %c, %d\n", myData.direction, myData.distance);
}

struct element getDirection(char *token)
{
    struct element tmpData;

    tmpData.direction = token[0];

    //set temp variable for distance
    char tmpDistance[4];
    tmpData.distance = atoi(memcpy(tmpDistance, &token[1], 4));
    return tmpData;
}