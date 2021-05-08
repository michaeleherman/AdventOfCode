#ifndef fileparser_h
#define fileparser_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "writepoint.h"

#define CHUNK_SIZE 5

int parseFile();
void makeTheGrid(int xSize, int ySize, int zSize);

#endif