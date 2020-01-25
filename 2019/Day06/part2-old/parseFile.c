#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseFile.h"

struct pfStruct parseFile(FILE *file)
{
    struct pfStruct pf;
    char buf[10];
    int sizeOfPlanetsArray = 0;
    s_planet *planets = malloc(sizeof(s_planet));

    while (fgets(buf, sizeof(buf), file) != NULL) //Iterate through list, adding planet and direct to struct
    {                                             //in the array of structs

        buf[strlen(buf) - 1] = '\0';
        char *planet = strtok(buf, ")");
        char *direct = strtok(NULL, ")");

        if (strcmp(direct,"YOU") == 0) {
            pf.youLoc = sizeOfPlanetsArray;
        }
        else if (strcmp(direct, "SAN") == 0){
            pf.sanLoc = sizeOfPlanetsArray;
        }
       

        planets[sizeOfPlanetsArray].planet = strdup(planet);
        planets[sizeOfPlanetsArray].direct = strdup(direct);

        // printf("Planet and direct %s, %s\n", planets[sizeOfPlanetsArray].planet, planets[sizeOfPlanetsArray].direct);

        sizeOfPlanetsArray++;
        planets = realloc(planets, sizeof(s_planet) * (sizeOfPlanetsArray + 2));
    }
    pf.sizeOfPlanetsArray = sizeOfPlanetsArray;
    pf.planets = planets;

    return pf;
}