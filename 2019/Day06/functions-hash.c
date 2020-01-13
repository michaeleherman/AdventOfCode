#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functions-hash.h"
#include "string.h"

struct pfStruct parseFile(FILE *file, int maxHash)
{
    struct pfStruct pf;
    char buf[10];
    int sizeOfPlanetsArray = 0;
    s_planet *planets = malloc(sizeof(s_planet) * maxHash);
    int comLocation = 0;

    while (fgets(buf, sizeof(buf), file) != NULL) //Iterate through list, adding planet and direct to struct
    {                                             //in the array of structs

        buf[strlen(buf) - 1] = '\0';
        char *token = strtok(buf, ")");
        int hashValue = getHash(token);

        planets[hashValue].planet = strdup(token);

        if (strcmp(token, "COM") != 0) //using strdup to copy value
        {
            token = strtok(NULL, ")");

            planets[hashValue].direct = strdup(token);
            sizeOfPlanetsArray++;
        }
        else
        {
            token = strtok(NULL, ")");
            planets[hashValue].direct = strdup(token);
            sizeOfPlanetsArray++;
            pf.comLocation = comLocation
        }
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

int getHash(char *planet)
{
    char c0[8];
    char c1[8];
    char c2[8];
    char prefix[8] = "1";

    int i0 = planet[0];
    int i1 = planet[1];
    int i2 = planet[2];

    sprintf(c0, "%d", i0);
    sprintf(c1, "%d", i1);
    sprintf(c2, "%d", i2);

    strcat(c1, c2);
    strcat(c0, c1);
    char *hashString = strcat(prefix, c0);

    int hashValue = atoi(hashString);

    return hashValue;

    // 1909090 will be the greatest value
}

char *reverseHash(int hashValue)
{

    char *hashChar[20];
    char *c0;
    char *c1;
    char *c2;

    sprintf(hashChar, "%d", hashValue);

    c0 = atoi(strncpy(c0, hashChar[1], 2 * (sizeof(char))));
    c1 = atoi(strncpy(c1, hashChar[3], 2 * (sizeof(char))));
    c2 = atoi(strncpy(c2, hashChar[5], 2 * (sizeof(char))));

    strcat(c1, c2);
    strcat(c0, c1);

    return c0;
}
