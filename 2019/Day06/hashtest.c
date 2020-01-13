
#include <stdio.h>
#include <stdlib.h>

unsigned long hash(unsigned char *str);

int main() {

    unsigned char * planet = "ABCD";
    long value = hash(planet);

    printf("value is: %lu",value);

    return 0;
}


unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}