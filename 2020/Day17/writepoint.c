#include "writepoint.h"

extern int xSize;
extern int ySize;
extern int zSize;
extern int ***grid3d;

void writeCoordinate(int x, int y, int z, int value) {

  grid3d[x + xSize][y + ySize][z + zSize] = value;
}

int readCoordinate(int x, int y, int z) {

  return grid3d[x + xSize][y + ySize][z + zSize];
}