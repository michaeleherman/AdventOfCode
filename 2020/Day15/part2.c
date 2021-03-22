#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHUNK_SIZE 512
#define TARGET 30000000

struct obj {
    int lastPos;
    int currentPos;
};

struct obj **numArray;

int main(void){

    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day15/test.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    char chunk[CHUNK_SIZE];
    numArray = malloc(sizeof(struct obj));
    int end = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        char delim[2] = ",";
        char *token = strtok(chunk,delim);
        while (token != NULL){
            int tmpLoc = atoi(token);
            struct obj numArray[tmpLoc];
            numArray[tmpLoc].lastPos = end;
            token = strtok(NULL,delim);
            *numArray = (struct obj *) realloc(numArray,sizeof(struct obj *) * (end + 2));
            end++;
        }
    }

    // int i = end;
    // int num = 0;
    // while (i < TARGET ) {
    //     int j;
    //     for (j = end -2; j >= 0; j--) {
    //         if (numArray[i -1] == numArray[j]) {
    //             numArray[i] = i - 1 - j;
    //             break;
    //         }
    //     }
    //     if (j == -1) {
    //         numArray[i] = 0;
    //     }
    //     numArray = realloc(numArray, sizeof(int) * ( end + 2));
    //     end++;
    //     printf("%d,%d\n", i, numArray[i]);
    //     i++;
    // }



    return 0;

}
