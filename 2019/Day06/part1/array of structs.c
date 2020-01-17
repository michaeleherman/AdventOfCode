#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct planet
{
    char *planet;
    char *subplanet;
    char *child;
    bool end;;

} s_planet;

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
    // s_planet *head = NULL;
    // head = malloc(sizeof(s_planet));
    // printf("Head is at: %p\n", &head);
    // s_planet *current = head;
    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        planets[counter].end = false;
        buf[strlen(buf) - 1] = '\0';
        char *token = strtok(buf, ")");

        planets[counter].planet = strdup(token);
        token = strtok(NULL, ")");
        planets[counter].subplanet = strdup(token);
        planets[counter].child= strdup(token);

        counter++;
        planets = realloc(planets, (2+counter)*sizeof(s_planet));
       
        // current = current->child;


    }

    // qsort(planets, counter, sizeof(struct planet), planetComp);

    // print_list()

    // char *searchString = "COM";

    // for (int i = 0; i < counter; i++)
    // s_planet *curr = head;

    // printf("%p, %p\n", &head, &curr);
    // printf("head planet: %s\n", head->planet);
    // printf("curr planet: %s\n", curr->planet);
    for (int i = 0; i< counter; i++)
    {
        // if (strcmp(planets[i].planet,searchString) == 0) {
        // printf("starting mem loc: %p\n", curr->planet);
        printf("Planet: %s, child: %s\n", planets[i].planet,planets[i].child);
        // curr = curr->child;
        //  searchString = planets[i].child;
        //  i = 0;
        // }
    }

    return 0;
}