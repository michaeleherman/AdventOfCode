#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHUNK_SIZE 3

int main()
{
    int xSize = 1;
    int ySize = 1;
    int zSize = 1;
    int x = 0;
    int y = 0;
    int z = 0;

    int ***grid3d = (int ***) malloc((zSize + 1) * sizeof(int **));

    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day17/test.txt", "r");
    if (fp == NULL)
    {
        perror("error opening file");
        return (-1);
    }
    char chunk[CHUNK_SIZE];
    int end = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL)
    {   
        grid[x] = (int **) malloc((xSize+1) * sizeof(int *));
        for (int i = 0; i < CHUNK_SIZE; i++)
        {
            grid3d[x][y] = (int*) malloc ((ySize+1) * sizeof(int));
            grid3d[x][i][z] = chunk[i];
            ySize++;
        }
        x++;
        xSize++;
    }

    for (int i = 0;i < xSize;i++) {
        for (int j = 0;j < ySize;j++ ) {
            printf("%d ",grid3d[i][j][0]);
        }
        printf("\n");
    }

    return 0;
}