#include "fileparser.h"

extern int ***grid3d;
extern int ***snapShot;

int parseFile(){
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day17/test.txt", "r");
    if (fp == NULL)
    {
        perror("error opening file");
        return (-1);
    }
    char chunk[CHUNK_SIZE];

    // int end = 0;
    grid3d = (int ***)malloc(xSize * sizeof(int **));
    snapShot = (int ***)malloc(xSize * sizeof(int **));

    while (fgets(chunk, sizeof(chunk), fp) != NULL)
    {
        grid3d[x] = (int **)malloc((xSize + 1) * sizeof(int *));
        snapShot[x] = (int **)malloc((xSize + 1) * sizeof(int *));
        chunk[strlen(chunk) - 1] = '\0';
        for (int i = 0; i < CHUNK_SIZE - 1; i++)
        {
            if (chunk[y] == '\0')
            {
                break;
            }
            grid3d[x][y] = (int *)malloc((strlen(chunk) * sizeof(int)));
            snapShot[x][y] = (int *)malloc((strlen(chunk) * sizeof(int)));
            grid3d[x][y][z] = chunk[y];
            printf("chunk %d - %d - %d - %d grid value %d at %p\n", x, y, z, chunk[y], grid3d[x][y][z], &grid3d[x][y][z]);
            y++;
        }
        y = 0;
        x++;
    }
    return 0;
}