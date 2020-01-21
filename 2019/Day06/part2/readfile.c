#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readfile.h"

s_planets *readFile () {

    FILE *file;
    file = fopen("./test_input2.txt","r");
    char buf[10];
    s_planets *planetsArray = malloc(sizeof(s_planets));
    int arraySize = 0;

    while (fgets(buf, sizeof(buf), file) != NULL) {

        buf[strlen(buf) -1] = '\0';
        planetsArray[arraySize].planet = strdup(strtok(buf,")"));
        planetsArray[arraySize].direct = strdup(strtok(NULL, ")"));

        arraySize++;
        planetsArray = realloc(planetsArray, sizeof(s_planets) * (arraySize + 1));


    }

    for (int i = 0; i<arraySize;i++){
        printf("%d, %s, %s\n", i, planetsArray[i].planet, planetsArray[i].direct);
    }

    return planetsArray;
}

