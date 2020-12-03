#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day03/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    int **forest = malloc(sizeof(int*));
    char chunk[256];
    int counter = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        int rowLen = strlen(chunk);
        if (strcmp(&chunk[rowLen],"\n")) {
            rowLen = rowLen -1;
        }
        forest[counter] = malloc(sizeof(int)*rowLen);

        for (int i = 0; i<rowLen;i++) {
            if (strcmp(&chunk[i],".")) {
                forest[counter][i] = 0;
            } else {
                forest[counter][i] = 1;
            }
        }

        counter++;
        forest = realloc(forest, sizeof(int*) * counter+2 );


    }

    for (int i = 0;i<counter;i++) {
        for (int j = 0;j<32;j++) {
            printf("%c", forest[i][j]);
        }
    }
    return 0;

}