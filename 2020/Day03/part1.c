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
        chunk[rowLen -1] = '\0';
        forest[counter] = malloc(sizeof(int)*rowLen);
        char item;

        // printf("first character is %s\n",&chunk[0]);
        // printf("strcmp test is %d\n",strcmp(&chunk[0],"."));

        for (int i = 0; i<rowLen;i++) {
            item = chunk[i];
            if (strcmp(&item,".") == 0) {
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
            printf("%d", forest[i][j]);
        }
        printf("\n");
    }
    return 0;

}