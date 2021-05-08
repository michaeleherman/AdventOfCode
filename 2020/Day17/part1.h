
#ifndef part1_h
#define part1_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileparser.h"

enum state
{
    ACTIVE = 35,
    INACTIVE = 46
};
int ***grid3d;
int ***snapShot;
int xSize;
int ySize;
int zSize;

void copyGrid(int xSize, int ySize, int zSize);

#endif /* part1_h */
