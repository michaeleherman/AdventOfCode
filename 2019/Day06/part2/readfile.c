#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"
#include "part2.h"

r_planets readFile () {

    FILE *file;
    file = fopen("./input.txt","r");
    char buf[10];
    s_planets *planetsArray = malloc(sizeof(s_planets));
    int arraySize = 0;
    r_planets planetsStruct;

    while (fgets(buf, sizeof(buf), file) != NULL) {

        buf[strlen(buf) -1] = '\0';
        planetsArray[arraySize].planet = strdup(strtok(buf,")"));
        planetsArray[arraySize].direct = strdup(strtok(NULL, ")"));

        arraySize++;
        planetsArray = realloc(planetsArray, sizeof(s_planets) * (arraySize + 1));


    }

    planetsStruct.planets = planetsArray;
    planetsStruct.planetsSize = arraySize;



    return planetsStruct;
}

