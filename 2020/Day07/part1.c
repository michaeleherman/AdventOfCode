#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define myBag "shiny gold"


void makeBagsArray(char **chunks, char *chunk, int *counter);
bool canHold(char *chunk, char **bags, int *countOfBags);
char * getExteriorBag (char *chunk);
bool checkForDupBags (char **bags, char *bag, int bagCount);

int main() {
    

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day07/data.txt","r");


    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    char *chunk;
    int countOfBags = 1;
    char **chunks;
    int counter = 0;
    char **bags;

    chunks = malloc(sizeof(char) * (counter + 1));
    chunk = calloc(512, sizeof(char));
    
    bags = malloc(sizeof(char) * countOfBags);
    bags[0] = malloc(sizeof(char) * strlen(myBag));
    strcpy(bags[0],myBag);

    while (fgets(chunk, sizeof(chunk) * 512, fp) != NULL) {
//        makeBagsArray(chunks, chunk, &counter);
        if (chunk[strlen(chunk) -1]== '\n') {
            chunk[strlen(chunk) -1] = '\0';
        }
        printf("mem allocated %lu strlen(chunk) %lu\n",strlen(chunk) * sizeof(char), strlen(chunk));
        chunks[counter] = malloc(strlen(chunk) * sizeof(char*));
        printf("making - %d %s\n", counter, chunk);
        memcpy(chunks[counter], chunk, strlen(chunk)+1);
//        strcpy(chunks[counter], chunk);
        counter++;
        chunks = realloc(chunks,sizeof(char*) * (counter + 1));
    }
    
    
    for (int i = 0; i < counter; i++) {
        bool doesHold = canHold(chunks[i], bags, &countOfBags);
        printf("doeshold: %d\n", doesHold);
        printf("Chunk %d - %s\n", i,chunks[i]);
        if ( doesHold == 1) {
            i = -1;
        }
    }

    for (int i = 0; i < countOfBags; i++) {
        printf("%d %s\n",i, bags[i]);
    }


return 0;
}

void makeBagsArray(char **chunks, char *chunk, int *counter){

    if (chunk[strlen(chunk) -1]== '\n') {
        chunk[strlen(chunk) -1] = '\0';
    }

    chunks[*counter] = malloc(strlen(chunk) * sizeof(char*));
    printf("making - %d %s\n", *counter, chunk);
    strcpy(chunks[*counter], chunk);
}

bool canHold(char *chunk, char **bags, int *countOfBags) {
    bool doesHold = false;
    for (int i = 0; i < *countOfBags; i++) {
        char *interiorBags = strstr(chunk,"contain");
        if (strstr(interiorBags, bags[i])) {
            bags = realloc(bags, sizeof(char*) * (*countOfBags));
            char *exteriorBag = getExteriorBag(chunk);
//            bool dupBag = checkForDupBags(bags, exteriorBag, *countOfBags);
//            if ( dupBag == 0 ) {
                bags[*countOfBags] = malloc(sizeof(char*) * (strlen(exteriorBag) + 1));
//                strcpy(bags[*countOfBags],exteriorBag);
                memcpy(bags[*countOfBags], exteriorBag, strlen(exteriorBag) + 1);
                *countOfBags = *countOfBags + 1;
                doesHold = true;
//            }

//            dupBag = false;
        }
    }
    return doesHold;
}

char * getExteriorBag (char *chunk) {
    char exteriorBagColor[25];
    char tmpExteriorBag[25];
    sscanf(chunk,"%s %s",tmpExteriorBag,exteriorBagColor);
    strcat(tmpExteriorBag, " ");
    strcat(tmpExteriorBag, exteriorBagColor);
    char *exteriorBag = malloc(sizeof(char*) * strlen(tmpExteriorBag));
    memcpy(exteriorBag, tmpExteriorBag, strlen(tmpExteriorBag) + 1);
//    strcpy(exteriorBag, tmpExteriorBag);
    return exteriorBag;
}

bool checkForDupBags (char **bags, char *bag, int bagCount) {
    for (int i = 0; i < bagCount; i++) {
        if (strcmp(bags[i],bag) == 0) {
            return true;
        }
    }
    return false;
}
