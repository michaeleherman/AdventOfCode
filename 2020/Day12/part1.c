#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define chunkLength 10

struct container {
    int xPos;
    int yPos;
    int currentDirection;
    int instruction;
    int distance;
};

struct container * boat = NULL;

int main() {
    
    boat = malloc(sizeof(boat));
    boat->currentDirection = 'E';
    boat->xPos = 0;
    boat->yPos = 0;
    
    char chunk[chunkLength];
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day11/data.txt","r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        printf("%s\n",chunk);
        printf("stringlen chunk %lu\n", strlen(chunk));
        chunk[strcspn(chunk, "\n")] = 0;
        int direction = 0;
        int distance = 0;
        
        sscanf(chunk,"%d%d", &direction,&distance);
        
      
        
    }
    

    
    
    return 0;
    
}

void moveBoat(struct container * boat) {
    switch (boat->instruction) {
        case 'N':
            <#statements#>
            break;
            
        default:
            break;
    }
}

