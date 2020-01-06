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
    s_planet *current = planets;

    char **orbitees = malloc(sizeof(char*));
    char **orbiters = malloc(sizeof(char*));;

    while (fgets(buf, sizeof(buf), file) != NULL)
    {

        buf[strlen(buf) - 1] = '\0';
        char *token = strtok(buf, ")");
        orbitees[counter] = strdup(token);
        // current->planet = strdup(token);
        token = strtok(NULL, ")");
        // current->orbits = malloc(sizeof(s_planet));
        // current->orbits->planet = strdup(token);
        // current->orbits->orbits = NULL;
        orbiters[counter] = strdup(token);
        // // printf("Planet: %s, subplanet %s\n", current[counter].planet, current[counter].orbiter);
        counter++;
        orbitees = realloc(orbitees, sizeof(char*)*(counter+1));
        orbiters = realloc(orbiters, sizeof(char*)*(counter+1));
        // current = current->orbits;


    }

    // current = planets;
    for (int i = 0; i < counter; i++)
    {
        printf("Planet: %s, subplanet %s\n", orbitees[i],orbiters[i]);
        // current = current->orbits;
    }

    // findIndirect(planets);
}

// void findIndirect(s_planet *planets)
// {
//     printf("array size is %d\n", planets[0].arraySize);
//     int counter = planets[0].arraySize;



// }