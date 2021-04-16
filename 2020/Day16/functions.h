//
//  part1.h
//  Advent of Code 2020
//
//  Created by Michael.Herman on 4/14/21.
//

#ifndef part1_h
#define part1_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define FIELDS_COUNT 20
#define ARRAYSIZE 1000
#define CHUNK_SIZE 250


struct ticketField {
    char fieldName[50];
    int start1;
    int end1;
    int start2;
    int end2;
    
};

int checkValue(int value);
int part1(void);
void addToArray(int start, int end);

struct ticketField fields[ARRAYSIZE];

#endif /* part1_h */
