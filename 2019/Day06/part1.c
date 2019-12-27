#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct planet
{
    char *string;
    char *planet;
    char *child;
};

struct planet *planets;

int main()
{

    FILE *file;
    int counter = 0;

    planets = malloc(sizeof(struct planet));

    file = fopen("/Users/michael.herman/Documents/Code/AdventOfCode/2019/Day06/test_input.txt", "r");

    char buf[10];
    // char **fileArray;
    // char **tmpArray;
    // char *p;

    // fileArray = malloc(sizeof(char*));

    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        buf[strlen(buf) - 1] = '\0';
        planets[counter].string = strdup(buf);
        // printf("planet %d string is %s\n", counter, planets[counter].string);
        char *token = strtok(buf, ")");
        planets[counter].planet = strdup(token);
        token = strtok(NULL, ")");
        planets[counter].child = strdup(token);
        counter++;
        planets = realloc(planets,(counter + 2) * sizeof(struct planet));
    }

    for (int i = 0; i < counter; i++)
    {
    

        printf("Parent Planet: %s, Planet: %s\n", planets[i].planet, planets[i].child);
    }

    return 0;
}