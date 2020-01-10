#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "string.h"

void parseFile(FILE *file)
{
    char buf[10];
    int sizeOfPlanetsArray = 0;
    s_planet *planets = malloc(sizeof(s_planet));

    while (fgets(buf, sizeof(buf), file) != NULL)
    {

        buf[strlen(buf) - 1] = '\0';
        char *token = strtok(buf, ")");

        planets[sizeOfPlanetsArray].planet = strdup(token);
        token = strtok(NULL, ")");
        planets[sizeOfPlanetsArray].direct = strdup(token);
        sizeOfPlanetsArray++;
        planets = realloc(planets, sizeof(s_planet) * (sizeOfPlanetsArray + 2));
    }

    // for (int i = 0; i < sizeOfPlanetsArray; i++)
    // {
    //     int loopCounter = 0;
    //     planets[i].indirect = malloc(2 * sizeof(char *));
    //     int sizeOfIndirectArray = 0;
    //     recurseIndirects(planets, i, sizeOfPlanetsArray, sizeOfIndirectArray, loopCounter);
    // }

    findDirect(planets, sizeOfPlanetsArray);

    int totalOrbits = 0;
    for (int i = 0; i < sizeOfPlanetsArray; i++)
    {
        printf("Planet: %s, direct: %s\n", planets[i].planet, planets[i].direct);
        int j = 0;
        while (planets[i].indirect[j] != NULL)
        {
            printf("%s  ", planets[i].indirect[j]);
            j++;
        }
        printf("\nCount of orbits: %d\n", 1 + j);
        totalOrbits += 1 + j;
        printf("\n\n");
    }

    printf("Total orbits is: %d\n", totalOrbits);
}

// void findDirect(s_planet *planets, int sizeOfPlanetsArray)
// {

//     for (int i = 0; i < sizeOfPlanetsArray; i++)
//     {
//         int lastFoundLocation = -1;
//         int  indirectCount = 0;
//         planets[i].indirect = malloc(sizeof(s_planet));
//         char *currentPlanet = planets[i].direct;
//         for (int j = 0; j < sizeOfPlanetsArray; j++)
//         {
//              if (strcmp(currentPlanet, planets[j].planet) == 0)
//             {
//                 lastFoundLocation = j;
//                 planets[i].indirect[indirectCount] = planets[j].direct;
//                 indirectCount++;
//                 planets[i].indirect = realloc(planets[i].indirect, (1 + indirectCount) * sizeof(s_planet));
//                 currentPlanet = planets[j].direct;
//                 j = -1;
//             }

//         }
//     }
// }

void findDirect(s_planet *planets, int sizeOfPlanetsArray)
{
    s_orbits *orbits = malloc(sizeof(s_orbits));
    int counter = 0;
    int planetsAdded = 0;
    for (int i = 0; i < sizeOfPlanetsArray; i++)
    {
        bool matchFound = false;
        orbits[counter].planets = malloc(sizeof(char *));
        char *currentPlanet = planets[i].planet;
        char *currentDirect = planets[i].direct;
        orbits[counter].planets[0] = currentDirect;

        for (int j = i + 1; j < sizeOfPlanetsArray; j++)
        {
            if (strcmp(currentPlanet, planets[j].planet) == 0)
            {
                matchFound = true;
                planetsAdded++;
                orbits[counter].planets[j] = planets[j].direct;
                orbits[counter].planets = realloc(orbits[i].planets, sizeof(char *) * (planetsAdded + 1));
                removeItem(planets, &sizeOfPlanetsArray, &i);
            }
        }
        if (matchFound == true)
        {
            orbits[counter].iteration = counter;
            counter++;
        }

        if (matchFound == false)
        {
            removeItem(planets, &sizeOfPlanetsArray, &i);
        }
    }
}

void removeItem(s_planet *planets, int *sizeOfPlanetsArray, int *itemToRemove)
{
    int tempSize = *sizeOfPlanetsArray;
    int tempItem = *itemToRemove;

    if (tempItem >= tempSize)
    {
        printf("Error - tried to delete nonexistent location");
        exit(1);
    }
    else
    {
        for (int i = tempItem - 1; i < tempSize; i++)
        {
            planets[i] = planets[i + 1];
        }
        tempSize--;
        tempItem = -1;
        *sizeOfPlanetsArray = tempSize;
        *itemToRemove = tempItem;
    }
}
