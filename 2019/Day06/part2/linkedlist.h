#include "readfile.h"

typedef struct planet {
    char *planet;
    struct planet *next;
};

struct planet *makePlanetList(s_planets *hashOfPlanets, char *startPlanet);