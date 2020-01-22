#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "readfile.h"
#include "hash.h"
#include "part2.h"

int main()
{
    //Read in file
    //Parse file into array of structs, hash key as index
    //Find YOU and SAN locations
    //create linked list for each - take direct, store planet in next, move to next, find planet in directs, etc...
    //use intersection algorithm to find overlap point.
    //count distance from each to Intersection point.

    clock_t start, end;
    start = clock();

    r_planets planetsStruct = readFile();
    s_planets *planets = planetsStruct.planets;
    int planetsSize = planetsStruct.planetsSize;

    // for (int i = 0; i< planetsSize;i++) {
    //     int hashValue = hash(planets[i].planet);
    //     printf("%d - %d, %s, %s\n", i, hashValue, planets[i].planet,planets[i].direct); 
    // }

    insert(planets,planetsSize);

    printf("Min hash %d\n", hash("000"));
    printf("Max hash %d\n", hash("ZZZ") + 1);


    end = clock();

    return 0;
}