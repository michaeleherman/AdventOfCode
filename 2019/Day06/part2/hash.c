#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "readfile.h"

int hash(char *str)
{

    int hash = 13;

    for (int i = 0; i < strlen(str); i++)
    {
        hash = hash * 31 + str[i];
        // printf("%d\n", hash);
    }

    return hash;
}

// char *unhash() {

// }

s_planets *insert(s_planets *planetArray, int sizeOfPlanets)
{

    int arraySize = hash("ZZZ") + 1;
    s_planets *hashOfPlanets = malloc(sizeof(s_planets) * arraySize);
    memset(hashOfPlanets, 0, sizeof(s_planets) * arraySize);

    for (int i = 0; i < sizeOfPlanets; i++)
    {
        int arrayLoc = hash(planetArray[i].direct);
        while (hashOfPlanets[arrayLoc].direct != NULL)
        {
            arrayLoc += 1;
        }
        hashOfPlanets[arrayLoc].direct = planetArray[i].direct;
        hashOfPlanets[arrayLoc].planet = planetArray[i].planet;
    }

    return hashOfPlanets;

}