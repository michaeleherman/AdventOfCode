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

    r_planets planetsStruct = readFile();  //reads file and parses into array
    s_planets *planets = planetsStruct.planets;
    int planetsSize = planetsStruct.planetsSize;
    int maxHash = hash("ZZZ") + 1;

    s_planets *hashOfPlanets = insert(planets,planetsSize); //takes planets array and hashes planet

    for (int i = 0; i < maxHash -1; i++)
    {
        if (hashOfPlanets[i].planet != NULL)
        {
            printf("%d, %s - %s\n", i, hashOfPlanets[i].planet, hashOfPlanets[i].direct);
        }
    }

    end = clock();
    double time_taken = end - start;
    printf("Time: %f\n",time_taken/CLOCKS_PER_SEC);

    return 0;
}