#include "checkneighbors.h"

// If a cube is active and exactly 2 or 3 of its neighbors are also active, the cube remains active. Otherwise, the cube becomes inactive.
// If a cube is inactive but exactly 3 of its neighbors are active, the cube becomes active. Otherwise, the cube remains inactive.

extern int ***grid3d;
extern int ***snapShot;

int checkNeighbors(int x, int y, int z)
{
    int cubeState = grid3d[x][y][z];
    int activeNeighbors = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            for (int k = z - 1; k <= z + 1; k++)
            {
                if (i == x && j == y && k == z)
                {
                    continue;
                }
                else
                {
                    if (snapShot[i][j][k] == ACTIVE)
                    {
                        activeNeighbors++;
                    }
                }
            }
        }
    }
    if (cubeState == ACTIVE)
    {
        if (activeNeighbors == 2 || activeNeighbors == 3)
        {
            return ACTIVE;
        }
        else
        {
            return INACTIVE;
        }
    }
    else
    {
        if (activeNeighbors == 3)
        {
            return ACTIVE;
        }
        else
        {
            return INACTIVE;
        }
    }

    return 0;
}
