//
//  part1.h
//  Advent of Code 2020
//
//  Created by Michael.Herman on 4/14/21.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define FIELDS_COUNT 20
#define ARRAYSIZE 1000
#define CHUNK_SIZE 250


typedef struct ticketField {
    char fieldName[50];
    int start1;
    int end1;
    int start2;
    int end2;
    int position;
    
} _field;

int checkValue(int value);
int part1(void);
void addToArray(int start, int end);

_field fields[ARRAYSIZE];

#endif /* functions_h */
