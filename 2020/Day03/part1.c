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

    char chunk[256];
    int counter = 0;
    int position = 0;
    int opens = 0;
    int trees = 0;
    

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (counter == 0) {
            position = position + 3;
            counter++;
            continue;
        }

        int rowLen = strlen(chunk);
        chunk[rowLen-1] = '\0';
        printf("%d - row: %d position: %d - %c\n",rowLen, counter, position, chunk[position]);
        if ( chunk[position] == '.') {
            opens++;
        } else {
            trees++;
        }

        //29 wraps to 1
        //28 wraps to 0
        //30 wraps to 2
        //31 wraps to 3

        if (position >= rowLen -4) {
            position = position - rowLen + 4;
            counter++;
        } else {
            position = position + 3;
            counter++;
        }
        

    }

    printf("Trees: %d Open %d\n",trees, opens);

       
    return 0;

}