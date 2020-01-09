typedef struct planet
{
    char *planet;
    char *direct;
    char **indirect;

} s_planet;

void parseFile(FILE *file);

void findDirect(s_planet *planets,int sizeOfPlanetArray);

void recurseIndirects (s_planet *planets, int planetsArrayPosition, int sizeOfPlanetsArray, int sizeOfIndirectArray, int i);