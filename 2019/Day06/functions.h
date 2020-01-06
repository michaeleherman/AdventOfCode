typedef struct planet
{
    char *planet;
    struct planet *orbits;
    struct planet *satellite;

} s_planet;

void parseFile(FILE *file);

void findIndirect(char **orbitees, char **orbiters, int counter);