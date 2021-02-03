#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



#define myBag "shiny gold"

void deleteItem (char **array, int *position, int *counter);
void findBags(char **chunks, int counter, char **bags, int *bagCounter);
void makeBagList (char *chunk, char **chunks, int *counter);


int main() {

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day07/test.txt","r");
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    char chunk[512];
    char *bags[1] = {myBag};
    int bagCounter = 1;
    char color[25];
    char bag[50];
    bool exists = false;
    char **chunks;
    int counter = 0;

    chunks = malloc(sizeof(char));

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        makeBagList(chunk, chunks, &counter);

    }

    for (int i = 0; i < counter; i++) {
        printf("%d %s\n",i, chunks[i]);
        free(chunks[i]);
    }

    free (chunks);

return 0;
}

void makeBagList (char *chunk, char **chunks, int *counter){
        if (chunk[strlen(chunk) - 1] == '\n') {
            chunk[strlen(chunk) - 1] = '\0';
        }
        *chunks = realloc(chunks, (*counter + 1) * sizeof(char));
        chunks[*counter] = malloc(strlen(chunk) * sizeof(char));
        strcpy(chunks[*counter],chunk);

 
        // printf("file line %d size of chunk %lu size of chunk %lu\n", *counter,strlen(chunk),sizeof(chunks[*counter]));
        *counter = *counter + 1;
        chunks = realloc(chunks,sizeof(*chunks) * (*counter + 1));
}
