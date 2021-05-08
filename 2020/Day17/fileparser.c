#include "fileparser.h"

extern int ***grid3d;
extern int ***snapShot;

int x = 0;
int y = 0;
int z = 0;
extern int xSize;
extern int ySize;
extern int zSize;

int parseFile() {
  FILE *fp =
      fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day17/test.txt", "r");
  if (fp == NULL) {
    perror("error opening file");
    return (-1);
  }
  char chunk[CHUNK_SIZE];

  // int end = 0;
  grid3d = (int ***)malloc(xSize * sizeof(int **));
  snapShot = (int ***)malloc(xSize * sizeof(int **));

  makeTheGrid(xSize, ySize, zSize);

  while (fgets(chunk, sizeof(chunk), fp) != NULL) {
    // grid3d[x] = (int **)malloc((xSize + 1) * sizeof(int *));
    // snapShot[x] = (int **)malloc((xSize + 1) * sizeof(int *));
    chunk[strlen(chunk) - 1] = '\0';
    for (int i = 0; i < CHUNK_SIZE - 1; i++) {
      if (chunk[y] == '\0') {
        break;
      }
      //   grid3d[x][y] = (int *)malloc((strlen(chunk) * sizeof(int)));
      //   snapShot[x][y] = (int *)malloc((strlen(chunk) * sizeof(int)));
        writeCoordinate(x, y, z, chunk[y]);
    //   grid3d[x][y][z] = chunk[y];
      printf("chunk %d - %d - %d - %d grid value %d\n", x, y, z, chunk[y],
             readCoordinate(x,y,z));
      y++;
    }
    y = 0;
    x++;
  }
  return 0;
}

void makeTheGrid(int xSize, int ySize, int zSize) {
  int _xSize = xSize * 2;
  int _ySize = ySize * 2;
  for (int i = 0; i < _xSize; i++) {
    grid3d[x] = (int **)malloc((_xSize + 1) * sizeof(int *));
    snapShot[x] = (int **)malloc((_xSize + 1) * sizeof(int *));
    for (int j = 0; j < _ySize; j++) {
      grid3d[x][y] = (int *)malloc((_ySize + 1) * sizeof(int));
      snapShot[x][y] = (int *)malloc((_ySize + 1) * sizeof(int));
    }
  }
}