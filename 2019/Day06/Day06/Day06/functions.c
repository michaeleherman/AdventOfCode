#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "string.h"

void parseFile(FILE *file)
{
    char buf[10];
    int sizeOfPlanetsArray = 0;
    int comPosition = 0;
    s_planet *planets = malloc(sizeof(s_planet));

    while (fgets(buf, sizeof(buf), file) != NULL)
    {

        buf[strlen(buf) - 1] = '\0';
        char *token = strtok(buf, ")");

        planets[sizeOfPlanetsArray].planet = strdup(token);
                if (strcmp(token, "COM") == 0)
        {
            comPosition = sizeOfPlanetsArray;
        }
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

    findDirect(planets, sizeOfPlanetsArray,comPosition);

    for (int i = 0; i < sizeOfPlanetsArray; i++)
    {
        printf("Planet: %s, direct: %s\n", planets[i].planet, planets[i].direct);
        int j = 0;
        while (planets[i].indirect[j] != NULL)
        {
            printf("%s  ", planets[i].indirect[j]);
            j++;
        }

        printf("\n\n");
    }

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

void findDirect(s_planet *planets, int sizeOfPlanetsArray, int comPosition)
{
    //    Find direct for COM
    //  Iterate through list, comparing direct to planet
    //  if match, store planet location and delete row from planets
    //  Using stored planets, iterate through list comparing the stored planets against the planets
    //  if found, store direct

    char **directTmpArray = malloc(sizeof(char *));
    char **planetTmpArray = malloc(sizeof(char *));
    int tmpArrayCount = 1;
    int counter = 0;
    int totalOrbits = 0;
    planetTmpArray[0] = planets[comPosition].direct;
    for (int j = 0; j < tmpArrayCount; j++)
    {
        tmpArrayCount = 0;
        for (int i = 0; i < sizeOfPlanetsArray; i++)
        {
            if (strcmp(planetTmpArray[j], planets[i].planet) == 0)
            {
                directTmpArray[tmpArrayCount] = planets[i].direct;
                tmpArrayCount++;
                directTmpArray = realloc(directTmpArray, sizeof(char *) * (1 + tmpArrayCount));
                totalOrbits += counter;
                printf("Total Orbits %d", totalOrbits);
                counter++;
                removeItem(planets, &sizeOfPlanetsArray, i);
            }
        }
        planetTmpArray = directTmpArray;
    }
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
        for (int i = tempItem - 1; i < tempSize; i++)
        {
            planets[i] = planets[i + 1];
        }
        tempSize--;
        *sizeOfPlanetsArray = tempSize;
    }
}

