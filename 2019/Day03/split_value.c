#include "split_value.h"

struct DirDist splitDirDist(char dirDist[5]) {
    struct DirDist tmpDirDist;
    tmpDirDist.direction = dirDist[0];
    char tmpDistance[4];
    memcpy(tmpDistance,&dirDist[1],4);
    tmpDirDist.distance = atoi(tmpDistance);

    printf("split_value direction, distance %c, %d\n", tmpDirDist.direction,tmpDirDist.distance);

    return tmpDirDist;
}