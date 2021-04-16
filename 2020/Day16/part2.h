//
//  main.h
//  Advent of Code 2020
//
//  Created by Michael.Herman on 4/14/21.
//

#ifndef part2_h
#define part2_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

enum state {FALSE, TRUE};

#define CHUNK_SIZE 250
#define FIELDS_COUNT 20
#define ARRAYSIZE 1000

int validTix[ARRAYSIZE][FIELDS_COUNT];

int checkFields(int value);


#endif /* part2_h */
