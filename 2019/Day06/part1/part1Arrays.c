#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    char **planets;
    planets = malloc(sizeof(char*));

    FILE *file;
    int counter = 0;

    file = fopen("/Users/michael.herman/Documents/Code/AdventOfCode/2019/Day06/test_input.txt", "r");

    char buf[10];

    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        char **planet;
        planet = malloc(2*sizeof(char*));
        buf[strlen(buf) - 1] = '\0';

        // char *string = strdup(buf);
        // printf("planet %d string is %s\n", counter, planets[counter].string);
        char *token = strtok(buf, ")");
        // char *parent = strdup(token);
        planet[0] = strdup(token);
        token = strtok(NULL, ")");
        // char *planet = strdup(token);
        planet[1] = strdup(token);
        planets[counter] = *planet;
        counter++;
        planets = realloc(planets, (counter + 2) * sizeof(char*));
    }

    for (int i = 0; i < counter; i++)
    {
        
                printf("Planet: %s, Child: %s\n", planets[i],planets[i+1]);
    }


    return 0;
}