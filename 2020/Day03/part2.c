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
    char **forest = malloc(sizeof(char*));
    char chunk[256];
    int slopes[5][2] = {
        {1,1},
        {3,1},
        {5,1},
        {7,1},
        {1,2}
    };
    int treesArr[5];
    int rowLen = 32;

    int forestSize = 0;

while(fgets(chunk,sizeof(chunk), fp) != NULL) {
    forest[forestSize] = malloc(sizeof(char)*sizeof(chunk));
    strcpy(forest[forestSize], chunk);
    forest[forestSize][31] = '\0';
    // forest[forestSize] = chunk;
    forestSize++;
    forest = realloc(forest, sizeof(char*) * (forestSize+1));
}

    
for (int slope = 0;slope<5;slope++) {
    int position = 0;
    int opens = 0;
    int trees = 0;
    int right = slopes[slope][0];
    int down = slopes[slope][1];
    printf("%d - Right %d Down %d\n",slope,right,down);
    int row = 0;
    while (row<forestSize) {
        if (row == 0) {
            position = position + right;
            row = row + down;
            continue;
        }


        // printf("%d - row: %d position: %d - %c\n",rowLen, row, position, forest[row][position]);
        if ( forest[row][position] == '#') {
            trees++;
        }
        //when right is 3
        //28 wraps to 0
        //29 wraps to 1
        //30 wraps to 2
        //31 wraps to 3

        //when right is 7
        //24 wraps to 0
        //25 wraps to 1
        //26 wraps to 2
        //27 wraps to 3
        //28 wraps to 4
        //29 wraps to 5
        //30 wraps to 6
        //31 wraps to 7

        if (position >= rowLen - 1 - right) {
            position = position - rowLen + right + 1;
            row=row+down;
        } else {
            position = position + right;
            row=row+down;
        }
        

    }
    printf("Slope %d Trees %d\n",slope,trees);
    treesArr[slope] = trees;


}

long long treeProd = 1;

    for (int i = 0;i<=4;i++) {
        printf("Before calc - i: %d Array Value: %d Product:%lld\n",i,treesArr[i],treeProd);
        treeProd = treeProd*treesArr[i];
        printf("After calc - i: %d Array Value: %d Product:%lld\n",i,treesArr[i],treeProd);
    }

    printf("treesum %llo\n",treeProd);

       
    return 0;

    }