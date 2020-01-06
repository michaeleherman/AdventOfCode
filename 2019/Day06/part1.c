#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "functions.h"

typedef struct planet
{
    char *planet;
    struct planet *indirectOrbiters;
    char *directOrbiter;
    bool end;

} s_planet;

// struct planet *planets;

int main()
{

    FILE *file;
    int counter = 0;

    // planets = malloc(sizeof(struct planet));

    file = fopen("/Users/michael.herman/Documents/Code/AdventOfCode/2019/Day06/test_input.txt", "r");

    char buf[10];
    // char **fileArray;
    // char **tmpArray;
    // char *p;

    // fileArray = malloc(sizeof(char*));
    s_planet *head = NULL;
    head = malloc(sizeof(s_planet));
    // printf("Head is at: %p\n", &head);
    s_planet *current = head;
    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        // printf("current is %p\n", &current);
        buf[strlen(buf) - 1] = '\0';
        // planets[counter].string = strdup(buf);
        // printf("planet %d string is %s\n", counter, planets[counter].string);
        char *token = strtok(buf, ")");
        // planets[counter]->planet = strdup(token);

        current[counter].planet = strdup(token);
        token = strtok(NULL, ")");
        current[counter].directOrbiter = strdup(token);
        // current->directOrbiter = malloc(sizeof(s_planet));
        // current->child->planet = strdup(token);
        // current->child->child = NULL;
        // planets[counter]->end = false;

        counter++;
        // printf("current: %s, %p\n", current->planet, current->planet);
        // current = current->child;

        // planets = realloc(planets, (counter + 2) * sizeof(struct planet));
    }

    // qsort(planets, counter, sizeof(struct planet), planetComp);

    // print_list()

    // char *searchString = "COM";

    // for (int i = 0; i < counter; i++)
    s_planet *curr = head;

    // printf("%p, %p\n", &head, &curr);
    // printf("head planet: %s\n", head->planet);
    // printf("curr planet: %s\n", curr->planet);
    for (int i = 0; i < counter;i++)
    {
        // if (strcmp(planets[i].planet,searchString) == 0) {
        // printf("starting mem loc: %p\n", curr->planet);
        printf("Planet: %s, subplanet %s\n", curr[i].planet,curr[i].directOrbiter);
        // curr = curr->child;
        //  searchString = planets[i].child;
        //  i = 0;
        // }
    }

    return 0;
}