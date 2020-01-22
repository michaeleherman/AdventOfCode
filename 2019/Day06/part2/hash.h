#ifndef _Guard

#define _Guard
typedef struct planets {
    char *planet;
    char *direct;
} s_planets;

#endif

int hash(char *str);

void insert(s_planets *planetArray,int sizeOfPlanets);

