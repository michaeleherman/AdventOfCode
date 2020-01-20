#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "parseFile.h"
#include "makePlanet.h"

l_planet * create(char *planet,l_planet *next)
{
    l_planet* new_planet = (l_planet*)malloc(sizeof(l_planet));
    if(new_planet == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_planet->direct = planet;
    new_planet->next = next;
 
    return new_planet;
}

l_planet *makePlanet(int directLocation, s_planet *planetsArray, int sizeOfPlanetsArray)
{
    //PsuedoCode

    //Get planetsArray
    //get directLocation, start a l_planet list with directPlanet as planet
    //store planet as next
    //move l_planet pointer so next is current
    //search planets array for planet in directs
    // when found, add planet as next
    // when you reach COM, be done and return the struct

    l_planet *planet = malloc(sizeof(l_planet));


    planet->direct = planetsArray[directLocation].direct;
    planet->next = NULL;

    for (int i = 0; i < sizeOfPlanetsArray; i++)
    {
        if (strcmp(current->direct, planetsArray[i].direct) == 0)
        {
            current->next = planetsArray[i].planet;
            current = current->next;

        }
    }

    return planet;
}