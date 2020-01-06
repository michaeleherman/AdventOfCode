#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct planet
{
    char *planet;
    struct planet *indirectOrbiters;
    char *directOrbiter;
    bool end;

} s_planet;

void parseFile(FILE *file)
{
    char buf[10];
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
}