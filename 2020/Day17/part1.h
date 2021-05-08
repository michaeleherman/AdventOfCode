
#ifndef part1_h
#define part1_h

#include "fileparser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ***grid3d;
int ***snapShot;
int xSize = 1000;
int ySize = 1000;
int zSize = 1000;

void copyGrid(int xSize, int ySize, int zSize);

#endif /* part1_h */
