#include "part1.h"
#include "gridcopy.h"
#include "checkneighbors.h"

int main()
{
    xSize = 3;
    ySize = 3;
    zSize = 1;
    int fileParseStatus;
    fileParseStatus = parseFile();

    copyGrid(xSize, ySize, zSize);

    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            for (int k = 0; k < zSize; k++)
            {
                grid3d[i][j][k] = checkNeighbors(i, j, k);
                // printf("Grid - %d %d 0 - %d at %p\n", i, j, grid3d[i][j][k], &grid3d[i][j][k]);
                // printf("Copy - %d %d 0 - %d at %p\n", i, j, snapShot[i][j][k], &snapShot[i][j][k]);
            }
        }
    }

    return 0;
}

