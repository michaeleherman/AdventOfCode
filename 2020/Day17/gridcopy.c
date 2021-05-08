extern int ***grid3d;
extern int ***snapShot;

void copyGrid(int xSize, int ySize, int zSize) {
  for (int i = 0; i < xSize; i++) {
    for (int j = 0; j < ySize; j++) {
      for (int k = 0; k < zSize; k++) {
        snapShot[i + xSize][j + ySize][k + zSize] = grid3d[i + xSize][j + ySize][k + zSize];
      }
    }
  }
}