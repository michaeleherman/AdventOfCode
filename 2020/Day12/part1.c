#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define chunkLength 10

enum direction {
    NORTH = 0,
    EAST = 90,
    SOUTH = 180,
    WEST = 270
};

struct container {
    int xPos;
    int yPos;
    int currentDirection;
    int instruction;
    int distance;
};

void moveBoat(struct container * boat);

struct container * boat = NULL;

int main() {
    int counter = 0;
    boat = malloc(sizeof(boat));
    boat->currentDirection = EAST;
    boat->xPos = 0;
    boat->yPos = 0;
    
    char chunk[chunkLength];
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day12/data.txt","r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
//        printf("%d - %s\n",counter, chunk);
//        printf("stringlen chunk %lu\n", strlen(chunk));
        chunk[strcspn(chunk, "\n")] = 0;
        char tmpInstruction[2];
        sscanf(chunk,"%c%d", tmpInstruction,&boat->distance);
        boat->instruction = tmpInstruction[0];

        
        moveBoat(boat);
        counter ++;
        
    }
    
    printf("distance is %d\n",abs(boat->xPos) + abs(boat->yPos));
    
    
    return 0;
    
}

void moveBoat(struct container * boat) {
    switch (boat->instruction) {
        case 'N':
            boat->yPos += boat->distance;
            break;
        case 'S':
            boat->yPos -= boat->distance;
            break;
        case 'E':
            boat->xPos += boat->distance;
            break;
        case 'W':
            boat->xPos -= boat->distance;
            break;
        case 'L':
            boat->currentDirection = (boat->currentDirection - boat->distance + 360) % 360;
            break;
        case 'R':
            boat->currentDirection = (boat->currentDirection + boat->distance) % 360;
            break;
        case 'F':
            switch (boat->currentDirection) {
                case NORTH:
                    boat->yPos += boat->distance;
                    break;
                case SOUTH:
                    boat->yPos -= boat->distance;
                    break;
                case EAST:
                    boat->xPos += boat->distance;
                    break;
                case WEST:
                    boat->xPos -= boat->distance;
                    break;
                default:
                    printf("uhoh. hit the default moving forward\n");
                    exit(0);
                    break;
            }
            break;
        default:
            printf("hit the default in direction\n");
            break;
    }
}

//Action N means to move north by the given value.
//Action S means to move south by the given value.
//Action E means to move east by the given value.
//Action W means to move west by the given value.
//Action L means to turn left the given number of degrees.
//Action R means to turn right the given number of degrees.
//Action F means to move forward by the given value in the direction the ship is currently facing.
