#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "functions-hash.h"

int main()
{
    FILE *file;
    file = fopen("./input.txt", "r");
    struct pfStruct planetsStruct;
    int countOfOrbits = 0;
    // struct s_planet *planets;
    int maxHash = getHash("ZZZ");

    printf("maxhash %d\n", maxHash);

    planetsStruct = parseFile(file, maxHash);

    

    for (int i = 0; i < maxHash; i++)
    {
        if (planetsStruct.planets[i].planet == NULL)
        {
            continue;
        }
        else
        {
            printf("%d - %s, %s\n", i, planetsStruct.planets[i].planet, planetsStruct.planets[i].direct);
        }
    }

    return 0;
}