#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "string.h"

struct pfStruct parseFile(FILE *file)
{
    struct pfStruct pf;
    char buf[10];
    int sizeOfPlanetsArray = 0;
    s_planet *planets = malloc(sizeof(s_planet));

    while (fgets(buf, sizeof(buf), file) != NULL) //Iterate through list, adding planet and direct to struct
    {                                             //in the array of structs

        buf[strlen(buf) - 1] = '\0';
        char *token = strtok(buf, ")");

        planets[sizeOfPlanetsArray].planet = strdup(token); //using strdup to copy value

        token = strtok(NULL, ")");

        planets[sizeOfPlanetsArray].direct = strdup(token);
        // printf("Planet and direct %s, %s\n", planets[sizeOfPlanetsArray].planet, planets[sizeOfPlanetsArray].direct);

        sizeOfPlanetsArray++;
        planets = realloc(planets, sizeof(s_planet) * (sizeOfPlanetsArray + 2));
    }

    pf.planets = planets;
    pf.sizeOfPlanetsArray = sizeOfPlanetsArray;

    return pf;
}

int countOrbits(s_planet *planets, int sizeOfPlanetsArray, char **planetArray, int sizeOfPlanetArray)
{

    bool continueLoop = true;
    int loopCounter = 0;
    int orbits = 0;

    while (continueLoop == true)
    {
        char **directArray = malloc(sizeof(char *));
        int directArrayCounter = 0;

        for (int i = 0; i < sizeOfPlanetArray; i++)
        {
            for (int j = 0; j < sizeOfPlanetsArray; j++)
            {
                if (strcmp(planets[j].planet, planetArray[i]) == 0)
                {
                    directArray[directArrayCounter] = planets[j].direct;
                    removeItem(planets, &sizeOfPlanetsArray, j);
                    directArrayCounter++;
                    directArray = realloc(directArray, sizeof(char *) * (directArrayCounter + 1));
                    j = -1;
                }
            }
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

    return orbits;
}

void removeItem(s_planet *planets, int *sizeOfPlanetsArray, int itemToRemove)
{
    int tempSize = *sizeOfPlanetsArray;
    int tempItem = itemToRemove;

    if (tempItem >= tempSize)
    {
        printf("Error - tried to delete nonexistent location");
        exit(1);
    }
    else
    {
        for (int i = tempItem; i < tempSize; i++)
        {
            planets[i] = planets[i + 1];
        }
        tempSize--;
        *sizeOfPlanetsArray = tempSize;
        if (tempItem == 0)
        {
            tempItem = -1;
        }
    }
}


