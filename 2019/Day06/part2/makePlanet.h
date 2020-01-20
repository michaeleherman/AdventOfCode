typedef struct l_planet {
    char *direct;
    struct l_planet *next;
} l_planet;

struct l_planet makePlanet (int directLocation, s_planet *planetsArray, int sizeOfPlanetsArray);

