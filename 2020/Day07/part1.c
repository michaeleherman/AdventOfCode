#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define myBag "shiny gold"

struct package {
    char **chunks;
    char *chunk;
    int counter;
} ;

void deleteItem (char **array, int *position, int *counter);
void findBags(char **chunks, int counter, char **bags, int *bagCounter);
struct makeBagList( package tmpContainer);

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
    struct package tmpContainer; 

    chunks = malloc(sizeof(char));

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {

        tmpContainer.chunk = chunk;
        tmpContainer.counter = counter;
        tmpContainer.chunks = chunks;

        makeBagList(tmpContainer);

        printf("chunk: %d chunk 0: %s\n", counter-1, chunks[0]);
    } 




    for (int i = 0; i < counter; i++) {
        printf("%d %s\n",i, chunks[i]);
        // free(chunks[i]);
    }

    // free (chunks);

return 0;
}

struct makeBagList ( package tmpContainer){

        if (chunk[strlen(chunk) - 1] == '\n') {
            chunk[strlen(chunk) - 1] = '\0';
        }
        chunks = realloc(chunks, (*counter + 1) * sizeof(char));
        chunks[*counter] = malloc(strlen(chunk) * sizeof(char));
        strcpy(chunks[*counter],chunk);


        // printf("chunk is: %s\n", chunks[*counter]);
        *counter = *counter + 1;
        // chunks = realloc(chunks,sizeof(*chunks) * (*counter + 1));
}
