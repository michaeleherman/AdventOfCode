typedef struct planet
{
    char *planet;
    char *direct;

} s_planet;

struct pfStruct
{
    struct planet *planets;
    int sizeOfPlanetsArray;
    int youLoc;
    int sanLoc;
};

struct pfStruct parseFile(FILE *file);