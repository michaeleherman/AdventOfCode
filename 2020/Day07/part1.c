#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



#define myBag "shiny gold" 

void deleteItem (char **array, int *position, int *counter);
void findBags(char **chunks, int counter, char **bags, int *bagCounter);


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

    chunks = calloc(strlen(bag), sizeof(char) * sizeof(bag));

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
    //     char *contains = strstr(chunk,"contain");

    //     for (int i = 0; i < bagCounter; i++) {
    //         if(strstr(contains, bags[i])) {
    //             printf("found your bag in %s", chunks[i]);
    //             sscanf(chunks[i], "%s %s",bag,color);
    //             strcat(bag, " ");
    //             strcat(bag, color);
    //             bags[bagCounter] = malloc(sizeof(bag));
    //             strcpy(bags[bagCounter], bag);
    //             bagCounter++;
    //             bags = realloc(bags, sizeof(bag) * (bagCounter + 1));
    //         }
    //     }
    // }
        chunks[counter] = calloc(strlen(chunk),sizeof(char));
        strcpy(chunks[counter],chunk);

        chunks = realloc(chunks,sizeof(char) * (counter + 1));
        printf("file line %d size of chunk %lu size of chunk %lu\n", counter,strlen(chunk),sizeof(chunks[counter]));
        counter++;

    }

    for (int i = 0; i < counter; i++) {
        printf("%d %s\n",i, chunks[i]);
    }

return 0;
}
