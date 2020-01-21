#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int getHash(char *planet)
{
    char c0[8];
    char c1[8];
    char c2[8];
    char prefix[8] = "1";

    int i0 = planet[0];
    int i1 = planet[1];
    int i2 = planet[2];

    sprintf(c0, "%d", i0);
    sprintf(c1, "%d", i1);
    sprintf(c2, "%d", i2);

    strcat(c1, c2);
    strcat(c0, c1);
    char *hashString = strcat(prefix, c0);

    int hashValue = atoi(hashString) % 23;

    return hashValue;

    // 1909090 will be the greatest value
}


char *reverseHash(int hashValue)
{

    char *hashChar[20];
    char *c0;
    char *c1;
    char *c2;
    int i0, i1, i2;

    sprintf(*hashChar, "%d", hashValue); //copy integer to char string

    strncpy(c0, hashChar[1], 2 * (sizeof(char))); //copy characters 1 and 2 to C0
    strncpy(c1, hashChar[3], 2 * (sizeof(char)));
    strncpy(c2, hashChar[5], 2 * (sizeof(char)));
    i0 = atoi(c0);
    i1 = atoi(c1);
    i2 = atoi(c2);

    strcat(c1, c2);
    strcat(c0, c1);

    return c0;
}