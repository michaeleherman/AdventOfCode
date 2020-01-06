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

    // // current = planets;
    // for (int i = 0; i < counter; i++)
    // {
    //     printf("Planet: %s, subplanet %s\n", orbitees[i],orbiters[i]);
    //     // current = current->orbits;
    // }

    findIndirect(orbitees, orbiters, counter);
}

void findIndirect(char **orbitees, char **orbiters, int counter)
{
    s_planet *planets = malloc(sizeof(s_planet));
    s_planet *current = planets;

    for (int i = 0; i < counter; i++) {
        if (strcmp("COM", orbitees[i]) = 0){
            continue;
        }
        current->planet = orbitees[i];
        current->satellite = malloc(sizeof(s_planet));
        current->satellite = orbiters[i];
        


    }


}