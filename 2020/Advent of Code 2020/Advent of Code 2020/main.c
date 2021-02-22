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

void doSeats(struct bucket container);
int checkAdjacents (int adjacents[8], int currentState);
void getAdjacents (struct bucket container);



int main() {
    struct bucket container;
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
                int adjacents[8];
                memset(adjacents, 0, 8*sizeof(int));
                if (tmpSeats[row][seat] == '.') {
                    continue;
                }
                if ( row == 0) {
                    if (seat == 0) {
                        adjacents[e] = tmpSeats[row][seat + 1];
                        adjacents[se] = tmpSeats[row + 1][seat + 1];
                        adjacents[s] = tmpSeats[row + 1][seat];
                        getAdjacents(container);
                        container.seats[row][seat] = checkAdjacents(adjacents,tmpSeats[row][seat]);
                    } else if (seat == rowLength - 1) {
                        adjacents[w] = tmpSeats[row][seat - 1];
                        adjacents[sw] = tmpSeats[row + 1][seat - 1];
                        adjacents[s] = tmpSeats[row + 1][seat];
                        if ((w + sw + s) == 3 * 'L') {
                            container.seats[row][seat] = '#';
                            change = 1;
                        }
                    } else {
                        adjacents[e] = tmpSeats[row][seat + 1];
                        adjacents[w] = tmpSeats[row][seat - 1];
                        adjacents[s] = tmpSeats[row + 1][seat];
                        adjacents[se] = tmpSeats[row + 1][seat + 1];
                        adjacents[sw] = tmpSeats[row + 1][seat - 1];
                        if (e != '#' && w != '#' && s != '#' && se != '#' && sw != '#') {
                            container.seats[row][seat] = '#';
                            change = 1;
                        } else if ((e + w + s + se + sw) >= '#' *4) {
                            container.seats[row][seat] = 'L';
                            change = 1;
                        }
                    }
                }
                if ( row > 0 && row < rowsOfSeats - 1) {
                    if ( seat == 0) {
                        adjacents[e] = tmpSeats[row][seat + 1];
                        adjacents[s] = tmpSeats[row + 1][seat];
                        adjacents [n] = tmpSeats[row - 1][seat];
                        adjacents[ne] = tmpSeats[row - 1][seat + 1];
                        adjacents[se] = tmpSeats[row + 1][seat + 1];
                        if (e != '#' && s != '#' && n != '#' && se != '#' && ne != '#') {
                            container.seats[row][seat] = '#';
                            change = 1;
                        } else if ((e + s + n + ne + se) >= 4 * '#') {
                            container.seats[row][seat] = 'L';
                            change = 1;
                        }
                    } else if ( seat == rowLength - 1) {
                        adjacents[w] = tmpSeats[row][seat - 1];
                        adjacents[s] = tmpSeats[row + 1][seat];
                        adjacents[n] = tmpSeats[row - 1][seat];
                        adjacents[nw] = tmpSeats[row -1][seat -1];
                        adjacents[sw] = tmpSeats[row + 1][seat - 1];
                        if (w != '#' && s != '#' && n != '#' && nw != '#' && sw != '#') {
                            container.seats[row][seat] = '#';
                            change = 1;
                        } else if ((w + s + n + nw + sw) >= 4 * '#') {
                            container.seats[row][seat] = 'L';
                            change = 1;
                        }
                    } else {
                        adjacents[w] = tmpSeats[row][seat - 1];
                        adjacents[s] = tmpSeats[row + 1][seat];
                        adjacents[n] = tmpSeats[row - 1][seat];
                        adjacents[e] = tmpSeats[row][seat + 1];
                        adjacents[nw] = tmpSeats[row -1][seat -1];
                        adjacents[sw] = tmpSeats[row + 1][seat - 1];
                        adjacents[ne] = tmpSeats[row - 1][seat + 1];
                        adjacents[se] = tmpSeats[row + 1][seat + 1];
                        if (w != '#' && s != '#' && n != '#' && e != '#' && nw != '#' && sw != '#' && ne != '#' && ne != '#' && se != '#') {
                            container.seats[row][seat] = '#';
                            change = 1;
                        } else if ((w + s + n + nw + sw) >= 4 * '#') {
                            container.seats[row][seat] = 'L';
                            change = 1;
                        }
                    }
                }
                if ( row == rowsOfSeats - 1) {
                    if ( seat == 0) {
                        adjacents[e] = tmpSeats[row][seat + 1];
                        adjacents[se] = tmpSeats[row + 1][seat + 1];
                        adjacents[s] = tmpSeats[row + 1][seat];
                        if (e != '#' && se != '#' && s != '#') {
                            container.seats[row][seat] = '#';
                            change = 1;
                        }
                    } else if (seat == rowLength - 1) {
                        adjacents[w] = tmpSeats[row][seat - 1];
                        adjacents[sw] = tmpSeats[row + 1][seat - 1];
                        adjacents [s] = tmpSeats[row + 1][seat];
                        if ( w != '#' && sw !='#' && s != '#') {
                            tmpSeats[row][seat] = '#';
                            change = 1;
                        }
                    } else {
                        adjacents[e] = tmpSeats[row][seat + 1];
                        adjacents[w] = tmpSeats[row][seat - 1];
                        adjacents[n] = tmpSeats[row - 1][seat];
                        adjacents[ne] = tmpSeats[row - 1][seat + 1];
                        adjacents[nw] = tmpSeats[row - 1][seat - 1];
                        if (e != '#' && w != '#' && n != '#' && ne != '#' && nw != '#') {
                            container.seats[row][seat] = '#';
                            change = 1;
                        } else if ((e + w + n + ne + nw) >= '#' *4) {
                            container.seats[row][seat] = 'L';
                            change = 1;
                        }
                    }
                }
            }
        }
//        memset(tmpSeats, 0, rowLength * rowsOfSeats * sizeof(char));
        for (int i = 0; i < rowsOfSeats;i++) {
            for (int j = 0; j < rowLength; j++) {
                tmpSeats[i][j] = container.seats[i][j];
            }
        }
//        memset(seats, 0, rowLength * rowsOfSeats  * sizeof(char));
        loop++;
    }
    printf("finally changed");
}

int checkAdjacents (int adjacents[8], int currentState){
    int floor = 0;
    int occupied = 0;
    int empty = 0;
    int noValue = 0;
    
    for (int i = 0; i < 8; i++) {
        switch (adjacents[i]) {
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
    if (currentState == EMPTY && occupied == 0) {
        return SIT;
    } else if (currentState == OCCUPIED && occupied >= 4) {
        return VACATE;
    }
    
    return 99;
}

void getAdjacents (struct bucket container) {
    int adjacents[8];
    memset(adjacents, 0, 8 * sizeof(int));
    int i = 0;
    int row = 0;
    int seat = 0;
    int dx, dy;
    for (dx = -1; dx <= 1; ++dx) {
        for (dy = -1; dy <= 1; ++dy) {
            if ((dx != 0 || dy != 0) && ((seat + dx > 0 && seat + dx < rowLength) || (row + dy > 0 && row -dy < rowsOfSeats ))) {
                adjacents[i] = container.seats[seat + dx][row + dy];
                i++;
            }
        }
    }
}

//L = 76
//# = 35
//. = 46
