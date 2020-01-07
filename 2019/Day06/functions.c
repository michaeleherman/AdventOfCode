#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"
#include "string.h"

void parseFile(FILE *file)
{
    char buf[10];
    int counter = 0;
    s_planet *planets = malloc(sizeof(s_planet));

    char **planetArray = malloc(sizeof(char *));
    char **directArray = malloc(sizeof(char *));

    while (fgets(buf, sizeof(buf), file) != NULL)
    {

        buf[strlen(buf) - 1] = '\0';
        char *token = strtok(buf, ")");
        planetArray[counter] = strdup(token);
        planets[counter].planet = strdup(token);
        // current->planet = strdup(token);
        token = strtok(NULL, ")");
        // current->orbits = malloc(sizeof(s_planet));
        // current->orbits->planet = strdup(token);
        // current->orbits->orbits = NULL;
        directArray[counter] = strdup(token);
        planets[counter].direct = strdup(token);
        // // printf("Planet: %s, subplanet %s\n", current[counter].planet, current[counter].orbiter);
        counter++;
        planetArray = realloc(planetArray, sizeof(char *) * (counter + 1));
        directArray = realloc(directArray, sizeof(char *) * (counter + 1));
        planets = realloc(planets, sizeof(s_planet) * (counter + 2));

        // current = current->orbits;
    }

    // // current = planets;
    // for (int i = 0; i < counter; i++)
    // {
    //     printf("Planet: %s, subplanet %s\n", planetArray[i],directArray[i]);
    //     // current = current->orbits;
    // }

    findIndirect(planets, planetArray, directArray, counter);
}

void findIndirect(s_planet *planets, char **planetArray, char **directArray, int counter)
{

    for (int i = 0; i < counter; i++)
    {
        int matches = 0;
        planets[i].indirect = malloc(matches * sizeof(char *));

        for (int j = 0; j < counter; j++)
        {

            if (strcmp(planets[j].planet, planets[i].direct) == 0)
            {
                matches++;
                planets[i].indirect[matches] = planets[j].direct;
                for (int k = 0; k < matches; k++)
                {
                    printf("Indirect: %s", planets[i].indirect[k]);
                    k++;
                }
                planets[i].indirect = realloc(planets[i].indirect[i], (matches + 2) * sizeof(char *));
            }
            else
            {
                printf("Nothing found for %s\n", directArray[i]);
            }
        }
    }
}