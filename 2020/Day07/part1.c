#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define myBag "shiny gold"
#define lines 600
#define chunkSize 512
#define bagSize 64

// typedef struct node {
//     char bagArray[400][64];
//     int countOfBags;
//     char chunks[400][512];
//     int counter;
// } node;


void makeBagsArray(char **chunks, char *chunk, int *counter);
bool canHold(char chunk[chunkSize], char bags[lines][bagSize], int *countOfBags);
char *getExteriorBag (char chunk[chunkSize]);
bool checkForDupBags (char bags[lines][bagSize], char bag[bagSize], int bagCount);
int removeChunk (char chunks[lines][chunkSize], int i, int counter);

int main() {

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day07/data.txt","r");


    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    char chunks[lines][chunkSize];
    char bags[lines][bagSize];
    char chunk[chunkSize];
    int countOfBags = 1;
    int counter = 0;
    
    memcpy(bags[0],myBag, strlen(myBag));

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (chunk[strlen(chunk) -1]== '\n') {
            chunk[strlen(chunk) -1] = '\0';
        }
    
        memcpy(chunks[counter], chunk, strlen(chunk)+1);
        counter++;
    }
    
    
    for (int i = 0; i < counter; i++) {
//        bool doesHold = canHold(chunks[i], bags, &countOfBags);
        for (int j = 0; j < countOfBags; j++) {
            char *interiorBags = strstr(chunks[i],"contain");
            if (strstr(interiorBags, bags[j])) {
                char exteriorBag[bagSize];
                strcpy(exteriorBag,getExteriorBag(chunks[i]));
                bool dupBag = checkForDupBags(bags, exteriorBag, countOfBags);
                if ( dupBag == 0 ) {
//                    strcpy(bags[countOfBags],exteriorBag);
                    memcpy(bags[countOfBags], exteriorBag, strlen(exteriorBag) + 1);
                    counter = removeChunk(chunks, i, counter);
                    countOfBags++;
                    i = -1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < countOfBags; i++) {
        printf("%s\n",bags[i]);
    }
    
    printf("Number of bags is: %d\n", countOfBags-1);

        

return 0;
            
}


char *getExteriorBag (char chunk[chunkSize]) {
    char exteriorBagColor[25];
    char tmpExteriorBag[25];
    sscanf(chunk,"%s %s",tmpExteriorBag,exteriorBagColor);
    strcat(tmpExteriorBag, " ");
    strcat(tmpExteriorBag, exteriorBagColor);
    static char exteriorBag[bagSize];
    memcpy(exteriorBag, tmpExteriorBag, strlen(tmpExteriorBag) + 1);
    strcpy(exteriorBag, tmpExteriorBag);
    return exteriorBag;
}

bool checkForDupBags (char bags[lines][bagSize], char bag[bagSize], int bagCount) {
    for (int i = 0; i < bagCount; i++) {
        if (strcmp(bags[i],bag) == 0) {
            return true;
        }
    }
    return false;
}

int removeChunk (char chunks[lines][chunkSize], int index, int counter){
    int i;
    for ( i = index ; i < counter -1; i++) {
        strcpy(chunks[i],chunks[i+1]);
    }
    
    return counter - 1;
}

