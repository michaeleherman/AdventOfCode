#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct DirDist splitDirDist(char DirDist[5]);

struct DirDist {
    char direction;
    int distance;
};
