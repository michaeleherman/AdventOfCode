#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define chunkLength 12
#define rowLength 11
#define rowsOfSeats 10

enum seatState {
    EMPTY = 76,
    OCCUPIED = 35,
    FLOOR = 46,
    NOVALUE = 0
};

enum direction {
    n, s, e, w, se, sw, ne, nw
};

enum action {
    SIT = 35,
    VACATE = 76
};

struct bucket {
    char seats[rowsOfSeats][rowLength];
    int end;
};

struct adjacents {
    int adjacentSeats[8];
    int currentState;
    int row;
    int seat;
};

void doSeats(struct bucket container);
int checkAdjacents (struct adjacents adjacent);
void getAdjacents (struct adjacents adjacent);

struct bucket container;

int main() {

    char chunk[chunkLength];
    container.end = 0;
    
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day11/test.txt","r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        printf("%s\n",chunk);
        printf("stringlen chunk %lu\n", strlen(chunk));
        chunk[strcspn(chunk, "\n")] = 0;
        
        
        for (int i = 0; i < rowLength;i++) {
            printf("%d - %c\n",i, chunk[i]);
        }
        strcpy(container.seats[container.end],chunk);
        container.end++;
        
    }
    
    doSeats(container);
    
    
    
    
    return 0;
    
}

void doSeats(struct bucket container){

    bool change = 1;
    //    int e, w, n, s, ne, nw, se, sw;
    int loop = 0;
    char tmpSeats[rowsOfSeats][rowLength];
    for (int i = 0; i < rowsOfSeats;i++) {
        for (int j = 0; j < rowLength; j++) {
            tmpSeats[i][j] = container.seats[i][j];
        }
    }
    while ( change == 1) {
        change = 0;
        for (int row = 0; row < container.end; row++){
            for (int seat = 0; seat< rowLength-1; seat++) {
                if (tmpSeats[row][seat] == '.') {
                    continue;
                }
                struct adjacents *adjacent = NULL;
                adjacent->row = row;
                adjacent->seat = seat;
                adjacent->currentState = tmpSeats[row][seat];
                memset(adjacent->adjacentSeats, 0, 8*sizeof(int));
                getAdjacents(*adjacent);
                container.seats[row][seat] = checkAdjacents(*adjacent);
            }
             for (int i = 0; i < rowsOfSeats;i++) {
                for (int j = 0; j < rowLength; j++) {
                    tmpSeats[i][j] = container.seats[i][j];
                }
            }
            loop++;
        }
        printf("finally changed");
    }
}
    
int checkAdjacents (struct adjacents adjacent){
    int floor = 0;
    int occupied = 0;
    int empty = 0;
    int noValue = 0;
    
    for (int i = 0; i < 8; i++) {
        switch (adjacent.adjacentSeats[i]) {
            case EMPTY:
                empty++;
                break;
            case OCCUPIED:
                occupied++;
                break;
            case FLOOR:
                floor++;
                break;
            case NOVALUE:
                noValue++;
                break;
            default:
                break;
        }
    }
    if (adjacent.currentState == EMPTY && occupied == 0) {
        return SIT;
    } else if (adjacent.currentState == OCCUPIED && occupied >= 4) {
        return VACATE;
    }
    
    return 99;
}

void getAdjacents (struct adjacents adjacent) {
    int i = 0;
    int row = adjacent.row;
    int seat = adjacent.seat;
    int dx, dy;
    for (dx = -1; dx <= 1; ++dx) {
        for (dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) {
                continue;
            } else if ( seat + dx < 0 || row + dy < 0) {
                continue;
            } else if (seat + dx > rowLength || row + dy > rowsOfSeats) {
                continue;
            } else {
                adjacent.adjacentSeats[i] = container.seats[seat + dx][row + dy];
                i++;
            }
        }
    }
}
    
    //L = 76
    //# = 35
    //. = 46
    //if ((dx != 0 || dy != 0) && ((seat + dx > 0 && seat + dx < rowLength) || (row + dy > 0 && row -dy < rowsOfSeats ))) {
    
    //}
