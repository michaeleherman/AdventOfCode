#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MULTIPLIER (37)

size_t
hash(const char *s)
{
    size_t h;
    unsigned const char *us;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) s;

    h = 0;
    while(*us != '\0') {
        h = h * MULTIPLIER + *us;
        us++;
    } 

    return h;
}
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
    // s_planet *head = NULL;
    // head = malloc(sizeof(s_planet));
    // printf("Head is at: %p\n", &head);
    // s_planet *current = head;
    while (fgets(buf, sizeof(buf), file) != NULL)
    {
        buf[strlen(buf) - 1] = '\0';
        char *token = strtok(buf, ")");
        char *parent = token;

    
        token = strtok(NULL, ")");
        char *child = token;
                int hashValue = hash(parent);

        counter++;

        printf("parent is %s, hash is %d, child is %s\n", parent, hashValue, child);


    }

    // qsort(planets, counter, sizeof(struct planet), planetComp);

    // print_list()

    // char *searchString = "COM";

    // for (int i = 0; i < counter; i++)
    // s_planet *curr = head;

    // printf("%p, %p\n", &head, &curr);
    // printf("head planet: %s\n", head->planet);
    // printf("curr planet: %s\n", curr->planet);
    // for (int i = 0; i< counter; i++)
    // {
    //     // if (strcmp(planets[i].planet,searchString) == 0) {
    //     // printf("starting mem loc: %p\n", curr->planet);
    //     printf("Planet: %s, child: %s\n", planets[i].planet,planets[i].child);
    //     // curr = curr->child;
    //     //  searchString = planets[i].child;
    //     //  i = 0;
    //     // }
    // }

    return 0;
}