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
#include "functions.h"

struct element {
    char direction;
    int distance;
}
;

int main () {

struct element myData = { 0 };

char* testString = "L123";

printf("in main\n");

myData = getDirection(testString);
// getDirection(testString);

printf("%c, %d", myData.direction, myData.distance);
}
