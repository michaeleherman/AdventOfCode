typedef struct planet
{
    char *planet;
    char *direct;

} s_planet;

struct planetPath 
{
    char *planet;
    struct planet *next;
};

struct pfStruct
{
    struct planet *planets;
    int sizeOfPlanetsArray;
    int youLoc;
    int sanLoc;
};


struct pfStruct parseFile(FILE *file);

void makeStruct(s_planet *planets, int sizeOfPlanetsArray, int startLoc,struct planetPath path);

