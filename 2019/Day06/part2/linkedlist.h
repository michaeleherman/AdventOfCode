#include "readfile.h"

#ifndef linked_planets
#define linked_planets

typedef struct planet {
    char *planet;
    struct planet *next;
} planet;

#endif

struct planet *makePlanetList(s_planets *hashOfPlanets, char *startPlanet);

int findDistance(char *intersection, planet *tmpPlanet);