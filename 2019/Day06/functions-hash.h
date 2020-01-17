typedef struct planet
{
    char *planet;
    char *direct;

} s_planet;

struct pfStruct
{
    struct planet *planets;
    int sizeOfPlanetsArray;
    int comLocation;
};


struct pfStruct parseFile(FILE *file,int maxHash);

// void findDirect(s_planet *planets,int sizeOfPlanetArray, char *firstPlanet);

void removeItem(s_planet *planets, int *sizeOfPlanetsArray, int itemToRemove);

int countOrbits(s_planet *planets, int sizeOfPlanetsArray, int *planetArray, int sizeOfPlanetArray);

int getHash(char *planet);

char *reverseHash(int hashValue);

unsigned long hash(const char* str, unsigned int length);