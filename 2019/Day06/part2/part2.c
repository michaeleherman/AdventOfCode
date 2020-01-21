#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "readfile.h"

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

    readFile();


    end = clock();

    return 0;
}