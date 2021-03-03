#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define chunkLength 101
#define rowLength 100
#define rowsOfSeats 95
#define BETWEEN(value, min, max) (value < max && value > min)

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

enum bounds {
    INBOUNDS, OUTOFBOUNDS
};

struct bucket {
    int seats[rowsOfSeats][rowLength-1];
    int end;
    int adjacentSeats[8];
    int tmpSeats[rowsOfSeats][rowLength-1];
    int currentState;
    int row;
    int seat;
    bool changed;
};

//struct adjacents {
//    int adjacentSeats[8];
//    int tmpSeats[rowsOfSeats][rowLength-1];
//    int currentState;
//    int row;
//    int seat;
//    bool changed;
//};

void doSeats(struct bucket *container);
void checkAdjacents (struct bucket *container);
void getAdjacents (struct bucket *container);
void countSeats(struct bucket *container);
int validateCoordinates(int row, int seat);

struct bucket * container = NULL;

int main() {
    
    char chunk[chunkLength];
    container = malloc(sizeof(container));
    container->end = 0;
    container->changed = 1;
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day11/data.txt","r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        printf("%s\n",chunk);
        printf("stringlen chunk %lu\n", strlen(chunk));
        chunk[strcspn(chunk, "\n")] = 0;
        
        
        for (int i = 0; i < rowLength - 1; i++ ) {
            container->seats[container->end][i] = chunk[i];
        }
        for (int i = 0; i < rowLength - 1;i++) {
            printf("%d ", container->seats[container->end][i]);
        }
        container->end++;
        
    }
    
    doSeats(container);
    
    
    
    
    return 0;
    
}

void doSeats(struct bucket *container){
    int loop = 0;
    for (int i = 0; i < rowsOfSeats;i++) {
        memset(container->tmpSeats[i], 0, sizeof(int) * rowLength -1);
        for (int j = 0; j < rowLength-1; j++) {
            container->tmpSeats[i][j] = container->seats[i][j];
        }
    }
    while ( container->changed == true) {
        container->changed = false;
        for (container->row = 0; container->row < container->end; container->row++){
            for (container->seat = 0; container->seat< rowLength-1; container->seat++) {
                if (container->tmpSeats[container->row][container->seat] == FLOOR) {
                    continue;
                }
                container->currentState = container->tmpSeats[container->row][container->seat];
                memset(container->adjacentSeats, 0, 8*sizeof(int));
                getAdjacents(container);
                checkAdjacents(container);
            }
            
            
        }
        for (int i = 0; i < rowsOfSeats;i++) {
            for (int j = 0; j < rowLength -1; j++) {
                container->tmpSeats[i][j] = container->seats[i][j];
            }
        }
        
        loop++;
//        countSeats(container);
        printf("loop count %d\n",loop);
    }
    
    
    countSeats(container);
}

void checkAdjacents (struct bucket *container){
    int floor = 0;
    int occupied = 0;
    int empty = 0;
    
    
    for ( int i = 0; i < 8; i++){
        switch (container->adjacentSeats[i]) {
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
        if ( container->adjacentSeats[i] == NOVALUE) {
            break;
        }
    }
    if (container->currentState == EMPTY && occupied == 0) {
        container->changed = true;
        container->seats[container->row][container->seat] = SIT;
    } else if (container->currentState == OCCUPIED && occupied >= 5) {
        container->changed = true;
        container->seats[container->row][container->seat] = VACATE;
    }
}

void getAdjacents (struct bucket *container) {
    int i = 0;
    int jx = 0;
    int jy = 0;
    int row = container->row;
    int seat = container->seat;
    int dx, dy;
    for (dx = -1; dx <= 1; ++dx) {
        for (dy = -1; dy <= 1; ++dy) {
//            printf (" row %d seat %d\n",row+dy, seat+dx);
            if ((dx == 0 && dy == 0) || validateCoordinates(row + dy, seat + dx) == OUTOFBOUNDS) {
                continue;
            }
            jx = dx;
            jy = dy;
            while (container->tmpSeats[row + jy][seat + jx] == FLOOR) {

                if (validateCoordinates(row + (jy + (dy * 1)), seat + (jx + dx * 1)) == OUTOFBOUNDS) {
                    break;
                }
                jx = jx + (dx * 1);
                jy = jy + (dy * 1);
            }
            
            container->adjacentSeats[i] = container->tmpSeats[row + jy][seat + jx];
            i++;
//            if ( abs(dx) > 1) {
//                dx = dx / jx;
//                jx = 2;
//            }
//            if ( abs(dy) > 1) {
//                dy = dy / jy;
//                jy = 2;
//            }
        }
    }
}

int validateCoordinates(int row, int seat) {
    if (row >=0 && row < rowsOfSeats && seat >=0 && seat < rowLength -1) {
        return INBOUNDS;
    } else {
        return OUTOFBOUNDS;
    }
}


void countSeats(struct bucket *container) {
    int occupied = 0;
    for (int i = 0; i < rowsOfSeats; i++) {
        for (int j = 0; j < rowLength-1; j++) {
            printf("%d ", container->seats[i][j]);
            if ( container->seats[i][j] == OCCUPIED) {
                occupied++;
            }
        }
        printf("\n");
    }
    printf("Occupied seats %d\n",occupied);
}

//L = 76
//# = 35
//. = 46
//if ((dx != 0 || dy != 0) && ((seat + dx > 0 && seat + dx < rowLength) || (row + dy > 0 && row -dy < rowsOfSeats ))) {

//}

