typedef struct planet
{
    char *planet;
    char *direct;
    char **indirect;

} s_planet;

void parseFile(FILE *file);

void findIndirect(s_planet *planets,char **orbitees, char **orbiters, int counter);