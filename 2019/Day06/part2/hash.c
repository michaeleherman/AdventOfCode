#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "part2.h"

int hash(char *str) {

    int hash = 13;

    for (int i = 0;i < strlen(str);i++) {
        hash = hash * 31 + str[i];
        // printf("%d\n", hash);
    }

    return hash;
}


// char *unhash() {

// }

void insert(s_planets *planetArray,int sizeOfPlanets) {

    int arraySize = hash("ZZZ") + 1;
    s_planets *hashOfPlanets = malloc(sizeof(s_planets) * arraySize);
    memset(hashOfPlanets,0,sizeof(s_planets) * arraySize);

    for (int i = 0; i<sizeOfPlanets;i++) {
        int arrayLoc = hash(planetArray[i].direct);
        hashOfPlanets[arrayLoc].direct = planetArray[i].direct;
        hashOfPlanets[arrayLoc].planet = planetArray[i].planet;
    }

    for (int i = 0; i < arraySize; i++){
        printf("%d, %s - %s",i,hashOfPlanets[i].planet,hashOfPlanets[i].direct);
    }

}