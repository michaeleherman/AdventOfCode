#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "functions-hash.h"
#include <time.h>

int main()
{
    clock_t start, end;

    start = clock();

    FILE *file;
    file = fopen("./input.txt", "r");
    struct pfStruct planetsStruct;
    int countOfOrbits = 0;
    // struct s_planet *planets;
    int maxHash = hash("ZZZ", strlen("ZZZ")) + 1;

    planetsStruct = parseFile(file, maxHash);

    struct planet *planets = planetsStruct.planets;
    int sizeOfPlanetsArray = planetsStruct.sizeOfPlanetsArray;
    int comLocation = planetsStruct.comLocation;

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

    printf("Max hash was: %d\n", maxHash);

    end = clock();

    double time_taken = (end - start);
    printf("start: %ld end: %ld Time taken: %f\n", start, end, time_taken/CLOCKS_PER_SEC);


    return 0;
}