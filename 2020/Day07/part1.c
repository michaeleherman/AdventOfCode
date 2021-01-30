#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *getLeftBag (char *chunk);
char *getRightBag (char *chunk);


int main() {

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day07/test.txt","r");
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    char chunk[512];
    char delim[5] = "bags"; 
    char *bag = malloc(sizeof(char));
    char *leftBag;
    char *right1;
    char *right2;
    int numRight1, numRight2;

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        // char *leftBag = getLeftBag(chunk);
        // printf("leftBag: %s\n",leftBag);
        // printf("%s\n",strstr(chunk,"contain") + strlen("contain "));
        // char *rightBags = getRightBag(chunk);
        // printf("rightBag: %s\n",rightBags);
    //     chunk[strlen(chunk)-1] = '\0';
    //     char *delim = " bags contain ";
    //     char *ret = strstr(chunk, delim);
    //     int startPos = strlen(ret) - strlen(delim);
    //     char *test = malloc(sizeof(char) * startPos);
    //     memcpy(test,ret[startPos],strlen())
    //     printf("chunk: %s\nsubchunk: %s\n", chunk,);
    //     printf("strlen chunk: %lu strlen ret: %lu\n", strlen(chunk),strlen(ret)-strlen(delim));
    // light red bags contain 1 bright white bag, 2 muted yellow bags.
        sscanf(chunk,"%s bags contain %d %s bag%*c, %d %s bag",leftBag, &numRight1, right1, &numRight2, right2);
        printf("%s - %d %s %d %s", leftBag,numRight1,right1,numRight2,right2);


    }


    return 0;
}


// char *getLeftBag (char *chunk) {
//         char *subChunk = strstr(chunk,"bags contain");
//         char *leftBag = malloc(sizeof(char) * (strlen(chunk) - strlen(subChunk)));
//         for (int i = 0; i < strlen(chunk) - strlen(subChunk); i++) {
//             leftBag[i] = chunk[i];
//         }
//         return leftBag;
// }

// char *getRightBag (char *chunk) {
//     char *subChunk = strstr(chunk, "contain ") + strlen("contain");
//     return subChunk;
// }