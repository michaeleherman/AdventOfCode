#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "functions.h"
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

    planetsStruct = parseFile(file);                //Parse the file
    struct planet *planets = planetsStruct.planets; //asign shorter names
    int sizeOfPlanetsArray = planetsStruct.sizeOfPlanetsArray;

    char **planetArray = malloc(sizeof(char *));
    planetArray[0] = "COM";


    countOfOrbits = countOrbits(planets, sizeOfPlanetsArray, planetArray, 1) + sizeOfPlanetsArray;

    printf("Count of orbits is: %d\n", countOfOrbits);

    // for (int i = 0; i< sizeOfPlanetsArray;i++) {
    //     printf("%s, %s\n", planets[i].planet,planets[i].direct);
    // }
     end = clock();
    double time_taken = end - start;
    printf("start: %ld end: %ld Time taken: %f\n", start, end, time_taken/CLOCKS_PER_SEC);

    return 0;
}