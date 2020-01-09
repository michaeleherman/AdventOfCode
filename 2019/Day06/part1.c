#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "functions.h"

    struct s_planet *planets;

int main()
{

    FILE *file;
    int counter = 0;

    file = fopen("/Users/michael/Documents/Code/AdventOfCode/2019/Day06/test_input.txt", "r");

    parseFile(file);

    // qsort(planets, counter, sizeof(struct planet), planetComp);

    return 0;
}