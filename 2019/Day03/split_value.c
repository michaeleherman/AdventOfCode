#include "split_value.h"

struct DirDist splitDirDist(char dirDist[]) {
    struct DirDist tmpDirDist;
    tmpDirDist.direction = dirDist[0];
    int tmpDistanceLength = strlen(dirDist) - 1;
    char tmpDistance[tmpDistanceLength];
    memcpy(tmpDistance,&dirDist[1],tmpDistanceLength);
    tmpDirDist.distance = atoi(tmpDistance);

//  printf("split_value direction, distance %c, %d\n", tmpDirDist.direction,tmpDirDist.distance);

    return tmpDirDist;
}