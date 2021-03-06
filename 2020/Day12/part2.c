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
    int xWay;
    int yWay;
};

void moveBoat(struct container * boat);
void rotation(struct container * boat);

struct container * boat = NULL;

int main() {
    int counter = 0;
    boat = malloc(sizeof(boat));
    boat->currentDirection = EAST;
    boat->xPos = 0;
    boat->yPos = 0;
    boat->xWay = 10;
    boat->yWay = 1;
    
    char chunk[chunkLength];
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day12/data.txt","r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        printf("%d - %s\n",counter, chunk);
        //        printf("stringlen chunk %lu\n", strlen(chunk));
        chunk[strcspn(chunk, "\n")] = 0;
        char tmpInstruction[2];
        sscanf(chunk,"%c%d", tmpInstruction,&boat->distance);
        boat->instruction = tmpInstruction[0];
        
        
        moveBoat(boat);
        printf("way point %d,%d\n", boat->xWay,boat->yWay);
        printf("points %d,%d\n\n", boat->xPos, boat->yPos);

        counter ++;
        
    }
    
    printf("distance is %d\n",abs(boat->xPos) + abs(boat->yPos));
    
    
    return 0;
    
}

void moveBoat(struct container * boat) {
    switch (boat->instruction) {
        case 'N':
            boat->yWay = boat->yWay + boat->distance;
            break;
        case 'S':
            boat->yWay = boat->yWay - boat->distance;
            break;
        case 'E':
            boat->xWay = boat->xWay + boat->distance;
            break;
        case 'W':
            boat->xWay = boat->xWay - boat->distance;
            break;
        case 'L':
//            boat->currentDirection = (boat->currentDirection - boat->distance + 360) % 360;
            rotation(boat);
            break;
        case 'R':
//            boat->currentDirection = (boat->currentDirection + boat->distance) % 360;
            rotation(boat);
            break;
        case 'F':
            boat->yPos = (boat->yWay * boat->distance) + boat->yPos;
            boat->xPos = (boat->xWay * boat->distance) + boat->xPos;
            break;
        default:
            printf("hit the default in direction\n");
            break;
    }
}

void rotation(struct container * boat) {
    int tmpPos = 0;
    if (boat->distance == 180) {
        boat->yWay = boat->yWay * -1;
        boat->xWay = boat->xWay * -1;
    } else if ((boat->instruction == 'R' && boat->distance == 90) || (boat->instruction == 'L' && boat->distance == 270)){
        tmpPos = boat->xWay;
        boat->xWay = boat->yWay;
        boat->yWay = tmpPos * -1;
    } else if ((boat->instruction == 'R' && boat->distance == 270) || (boat->instruction == 'L' && boat->distance == 90)){
        tmpPos = boat->xWay;
        boat->xWay = boat->yWay * -1;
        boat->yWay = tmpPos;
    }
}

//Action N means to move north by the given value.
//Action S means to move south by the given value.
//Action E means to move east by the given value.
//Action W means to move west by the given value.
//Action L means to turn left the given number of degrees.
//Action R means to turn right the given number of degrees.
//Action F means to move forward by the given value in the direction the ship is currently facing.

//Counter Clockwise Rotation x,y
// 90 y, -x
// 180 -x, -y
// 270 -y, x

//Clockwise Rotation x,y
// 90 -y,x
// 180 -x, -y
// 270 y, -x
