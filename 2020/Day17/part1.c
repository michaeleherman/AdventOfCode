#include "part1.h"

int main()
{
    // int xSize = 3;
    // int ySize = 3;
    // int zSize = 1;
    // int x = 0;
    // int y = 0;
    // int z = 0;

    // // grid3d = (int ***)malloc(xSize * sizeof(int **));
    // // grid3d[x] = (int **)malloc(ySize * sizeof(int *));
    // // grid3d[x][y] = (int *)malloc(zSize * sizeof(int));

    // FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day17/test.txt", "r");
    // if (fp == NULL)
    // {
    //     perror("error opening file");
    //     return (-1);
    // }
    // char chunk[CHUNK_SIZE];

    // // int end = 0;
    // grid3d = (int ***)malloc(xSize * sizeof(int **));
    // snapShot = (int ***)malloc(xSize * sizeof(int **));

    // while (fgets(chunk, sizeof(chunk), fp) != NULL)
    // {
    //     grid3d[x] = (int **)malloc((xSize + 1) * sizeof(int *));
    //     snapShot[x] = (int **)malloc((xSize + 1) * sizeof(int *));
    //     chunk[strlen(chunk) - 1] = '\0';
    //     for (int i = 0; i < CHUNK_SIZE - 1; i++)
    //     {
    //         if (chunk[y] == '\0')
    //         {
    //             break;
    //         }
    //         grid3d[x][y] = (int *)malloc((strlen(chunk) * sizeof(int)));
    //         snapShot[x][y] = (int *)malloc((strlen(chunk) * sizeof(int)));
    //         grid3d[x][y][z] = chunk[y];
    //         printf("chunk %d - %d - %d - %d grid value %d at %p\n", x, y, z, chunk[y], grid3d[x][y][z], &grid3d[x][y][z]);
    //         y++;
    //     }
    //     y = 0;
    //     x++;
    // }

    copyGrid(xSize, ySize, zSize);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d %d 0 - %d at %p\n", i, j, grid3d[i][j][0], &grid3d[i][j][0]);
            printf("%d %d 0 - %d at %p\n", i, j, snapShot[i][j][0], &snapShot[i][j][0]);
        }
    }

    return 0;
}

void testCube()
{
}

void copyGrid(int xSize, int ySize, int zSize)
{
    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {

            snapShot[i][j][0] = grid3d[i][j][0];
        }
    }
}

// If a cube is active and exactly 2 or 3 of its neighbors are also active, the cube remains active. Otherwise, the cube becomes inactive.
// If a cube is inactive but exactly 3 of its neighbors are active, the cube becomes active. Otherwise, the cube remains inactive.