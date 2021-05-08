#include "part1.h"
#include "checkneighbors.h"
#include "gridcopy.h"

int main() {

  int fileParseStatus;
  fileParseStatus = parseFile();

  copyGrid(xSize, ySize, zSize);

  for (int i = 0; i < xSize; i++) {
    for (int j = 0; j < ySize; j++) {
      for (int k = 0; k < zSize; k++) {
        grid3d[i][j][k] = checkNeighbors(i, j, k);
      }
    }
  }

  return 0;
}
