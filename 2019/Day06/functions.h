typedef struct planet
{
    char *planet;
    struct planet *orbits;

} s_planet;

void parseFile(FILE *file);

// void findIndirect(s_planet *planets);