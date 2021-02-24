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

//enum direction {
//    n, s, e, w, se, sw, ne, nw
//};

enum action {
    SIT = 35,
    VACATE = 76,
    DONOTHING = 999
};

struct bucket {
    char seats[rowsOfSeats][rowLength];
    int end;
};

struct adjacents {
    int adjacentSeats[8];
    char tmpSeats[rowsOfSeats][rowLength];
    int currentState;
    int row;
    int seat;
    bool changed;
};

void doSeats(struct bucket *container);
int checkAdjacents (struct adjacents *adjacent);
void getAdjacents (struct adjacents *adjacent);
void countSeats(struct bucket *container);

struct bucket * container = NULL;
struct adjacents * adjacent = NULL;

int main() {
    
    char chunk[chunkLength];
    container = malloc(sizeof(container));
    container->end = 0;
    adjacent = malloc(sizeof(adjacent));
    adjacent->changed = 1;
    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day11/test.txt","r");
    
    
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
        strcpy(container->seats[container->end],chunk);
        container->end++;
        
    }
    
    doSeats(container);
    
    
    
    
    return 0;
    
}

void doSeats(struct bucket *container){
    printf("entering do seats\n");
    //    int e, w, n, s, ne, nw, se, sw;
    int loop = 0;
    //    char tmpSeats[rowsOfSeats][rowLength];
    for (int i = 0; i < rowsOfSeats;i++) {
        for (int j = 0; j < rowLength; j++) {
            adjacent->tmpSeats[i][j] = container->seats[i][j];
        }
    }
    while ( adjacent->changed == true) {
        adjacent->changed = false;
        for (int row = 0; row < container->end; row++){
            for (int seat = 0; seat< rowLength-1; seat++) {
                if (adjacent->tmpSeats[row][seat] == '.') {
                    continue;
                }
                adjacent->row = row;
                adjacent->seat = seat;
                adjacent->currentState = adjacent->tmpSeats[row][seat];
                memset(adjacent->adjacentSeats, 0, 8*sizeof(int));
                getAdjacents(adjacent);
                container->seats[row][seat] = checkAdjacents(adjacent);
            }
            
            
        }
        for (int i = 0; i < rowsOfSeats;i++) {
            for (int j = 0; j < rowLength; j++) {
                adjacent->tmpSeats[i][j] = container->seats[i][j];
            }
        }
        
        loop++;
        printf("loop count %d\n",loop);
    }
    
    
    countSeats(container);
}

int checkAdjacents (struct adjacents *adjacent){
    int floor = 0;
    int occupied = 0;
    int empty = 0;

    
    for ( int i = 0; i < 8; i++){
        switch (adjacent->adjacentSeats[i]) {
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
                break;
            default:
                break;
        }
        if ( adjacent->adjacentSeats[i] == NOVALUE) {
            break;
        }
    }
    if (adjacent->currentState == EMPTY && occupied == 0) {
        adjacent->changed = true;
        return SIT;
    } else if (adjacent->currentState == OCCUPIED && occupied >= 5) {
        adjacent->changed = true;
        return VACATE;
    } else {
        return adjacent->currentState;
    }
}

void getAdjacents (struct adjacents *adjacent) {
    int i = 0;
    int j = 2;
    int row = adjacent->row;
    int seat = adjacent->seat;
    int dx, dy;
    for (dx = -1; dx <= 1; ++dx) {
        for (dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) {
                continue;
            } else if ( seat + dx < 0 || row + dy < 0) {
                continue;
            } else if (seat + dx > rowLength -1 || row + dy > rowsOfSeats -1) {
                continue;
            } else {
                while ( adjacent->tmpSeats[row + dy][seat + dx] == FLOOR) {
                    if (seat + dx > rowLength -1 || row + dy > rowsOfSeats -1 || seat + dx < 0 || row + dy < 0) {
                        break;
                    }
                    dy = dy * j;
                    dx = dx * j;
                    j++;
                }
                adjacent->adjacentSeats[i] = adjacent->tmpSeats[row + dy][seat + dx];
                i++;
            }
        }
    }
}

//while ( adjacent->tmpSeats[row + dy][seat + dx] == FLOOR) {
//    dy = dy * j;
//    dx = dx * j;
//}

void countSeats(struct bucket *container) {
    int occupied = 0;
    for (int i = 0; i < rowsOfSeats; i++) {
        for (int j = 0; j < rowLength; j++) {
            if ( container->seats[i][j] == OCCUPIED) {
                occupied++;
            }
        }
    }
    printf("Occupied seats %d\n",occupied);
}

//L = 76
//# = 35
//. = 46
//if ((dx != 0 || dy != 0) && ((seat + dx > 0 && seat + dx < rowLength) || (row + dy > 0 && row -dy < rowsOfSeats ))) {

//}
