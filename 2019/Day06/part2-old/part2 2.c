#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "parseFile.h"
#include <time.h>

int main()
{

    clock_t start, end;
    start = clock();

    FILE *file;
    file = fopen("./test_input2.txt", "r");
    struct pfStruct planetsStruct;

    planetsStruct = parseFile(file);                //Parse the file
    struct planet *planets = planetsStruct.planets; //asign shorter names
    int sizeOfPlanetsArray = planetsStruct.sizeOfPlanetsArray;

    

    // struct planet youPlanet;
    // struct planet santaPlanet;
    printf("Getting ready to print list\n");
    for (int i = 0; i< 22;i++) {
        printf("%s, %s - %d\n",planets[sizeOfPlanetsArray].planet,planets[sizeOfPlanetsArray].direct, planets[sizeOfPlanetsArray].hashValue);
    }

    end = clock();
    double time_taken = end - start;
    printf("start: %ld end: %ld Time taken: %f\n", start, end, time_taken / CLOCKS_PER_SEC);

    return 0;
}