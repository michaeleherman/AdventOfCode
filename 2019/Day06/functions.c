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


    recurseIndirects(planets, sizeOfPlanetsArray);
}

void findDirect(s_planet *planets, int sizeOfPlanetsArray)
{
    printf("size of planets is: %lu\n", sizeof(planets));
    for (int i = 0; i < sizeOfPlanetsArray; i++)
    {
        int matches = 0;
        planets[i].indirect = malloc(sizeof(char *));

        for (int j = 0; j < sizeOfPlanetsArray; j++)
        {

            if (strcmp(planets[j].planet, planets[i].direct) == 0)
            {

                planets[i].indirect[matches] = planets[j].direct;
                // printf("match (%d) at %d on %s\n", matches,j, planets[j].direct);
                printf("Planet is %s\n",planets[j].planet);
                printf("Indirects: ");
                for (int k = 0; k <= matches; k++)
                {

                    printf("%s ", planets[i].indirect[k]);
                }
                printf("\n\n");
                matches++;
                planets[i].indirect = realloc(planets[i].indirect, (matches + 1) * sizeof(char *));
            }
            else
            {
                // printf("Nothing found at %d for %s\n", j, directArray[i]);
            }
        }
    }

}

void recurseIndirects (s_planet *planets, int sizeOfPlanetsArray) {
    int indirectArrayPos = 0;

    if ( iPlanet == NULL) {
        printf("no match");
    } else {
        for (int i = 0;i < sizeOfPlanetsArray; i++) {
            if (strcmp(planets[i].planet, iPlanet) == 0) {
                planets[i].indirect[indirectArrayPos] = iPlanet;
                indirectArrayPos++;
                planets[i].indirect = realloc(planets[i].indirect, (indirectArrayPos + 1) * sizeof(char *));
                recurseIndirects(planets, iPlanet, sizeOfPlanetsArray)
            }
        }

    }



}