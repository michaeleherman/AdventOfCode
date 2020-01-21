#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functions2.h"
#include "parseFile.h"

void makeStruct(s_planet *planets, int sizeOfPlanetsArray, int startLoc, struct planetPath *path)
{
    struct planetPath *current = path;
    current->planet = planets[startLoc].planet;
    current->next->planet = planets[startLoc].planet;
    current = current->next;
    
     while (strcmp(path->next, "COM") != 0)
    {

            if (strcmp(planets[sizeOfPlanetsArray].direct,current->planet) == 0) {
                current->next->planet = planets[sizeOfPlanetsArray].planet;
                current = current->next;
            }
        }
        directArray[directArrayCounter] = planets[j].direct;
        removeItem(planets, &sizeOfPlanetsArray, j);
        directArrayCounter++;
        directArray = realloc(directArray, sizeof(char *) * (directArrayCounter + 1));
        j = -1;
    }
    planetArray = realloc(directArray, sizeof(char **) * directArrayCounter);
    // memcpy(planetArray, directArray, sizeof(char*)*sizeOfPlanetsArray);
    directArray = NULL;
    orbits += loopCounter * directArrayCounter;
    loopCounter++;
    sizeOfPlanetArray = directArrayCounter;
    if (sizeOfPlanetsArray == 0)
    {
        break;
    }
}
