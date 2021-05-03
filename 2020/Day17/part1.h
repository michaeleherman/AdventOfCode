
#ifndef part1_h
#define part1_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum state
{
    ACTIVE = 35,
    INACTIVE = 46
};
int ***grid3d;
int ***snapShot;

void copyGrid(int xSize, int ySize, int zSize);
void parseFile();

#endif /* part1_h */
