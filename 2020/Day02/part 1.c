#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

    FILE *fp = fopen("/Users/michael/Documents/Code/AdventOfCode/2020/Day02/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }


    char chunk[512];
    int counter = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        printf("chunk: %s\n", chunk);
        printf("size of chunk: %lu\n", strlen(chunk));
        int ret, min, max;
        char letter;
        char *password;

        ret = sscanf(chunk, "%d-%d %c: %s[^\n]",&min,&max,&letter,password);
        // ret = sscanf(chunk,"%d%*c%d %c%*c %s", &min, &max, &letter, password);

        printf("%d %d %c %s\n",min,max,letter,password);
        // printf("%i %i %c %s", min, max, letter, password);

    }


    return 0;

}