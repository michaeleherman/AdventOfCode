#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseFile.h"
#include "hash.h"

struct pfStruct parseFile(FILE *file)
{
    struct pfStruct pf;
    char buf[10];
    int sizeOfPlanetsArray = 0;
    s_planet *planets = malloc(sizeof(s_planet)*21);

    while (fgets(buf, sizeof(buf), file) != NULL) //Iterate through list, adding planet and direct to struct
    {                                             //in the array of structs

        buf[strlen(buf) - 1] = '\0';
        char *planet = strtok(buf, ")");
        char *direct = strtok(NULL, ")");
        int planetHash = getHash(direct);
        printf("Hash is %d\n", planetHash);

        if (strcmp(direct, "YOU"))
        {
            pf.youLoc = sizeOfPlanetsArray;
        }
        else if (strcmp(direct, "SAN"))
        {
            pf.sanLoc = sizeOfPlanetsArray;
        }

        if (planets[planetHash].hashValue != 0) {

        }
        planets[planetHash].planet = strdup(planet);
        planets[planetHash].direct = strdup(direct);
    
        printf("Planet and direct %s, %s\n", planets[planetHash].planet, planets[planetHash].direct);

        sizeOfPlanetsArray++;
        // planets = realloc(planets, sizeof(s_planet) * (sizeOfPlanetsArray + 2));
    }
    pf.sizeOfPlanetsArray = 22;
    pf.planets = planets;

    return pf;
}