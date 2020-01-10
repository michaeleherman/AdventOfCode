typedef struct planet
{
    char *planet;
    char *direct;
    char **indirect;

} s_planet;

typedef struct orbits
{
    int iteration;
    char **planets;
} s_orbits;

void parseFile(FILE *file);

void findDirect(s_planet *planets,int sizeOfPlanetArray, int comPosition);

void removeItem(s_planet *planets, int *sizeOfPlanetsArray, int itemToRemove);
