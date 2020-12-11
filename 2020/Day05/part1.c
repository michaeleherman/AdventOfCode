#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main(void){

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day05/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    char chunk[64];
    float lastRow = 127;
    float firstRow = 0;
    int maxSeatID = 0;

    float lastSeat = 7;
    float firstSeat = 0;
    int row = 0;
    int seat = 0;


    while (fgets(chunk, sizeof(chunk), fp) != NULL){

        for (int i = 0; i < strlen(chunk)-3; i++) {
            if (chunk[i] == 'F') {
                lastRow = floor((lastRow - firstRow)/2) + firstRow;
            } else if (chunk[i] == 'B') {
                firstRow = lastRow - floor((lastRow - firstRow)/2);
            }
            // printf("%c %f %f\n",chunk[i],firstRow,lastRow);
        }

    row = lastRow;
    printf("Row: %d\n", row);

    for (int i = strlen(chunk) -3; i < strlen(chunk);i++) {
        if (chunk[i] == 'L') {
            lastSeat = floor((lastSeat - firstSeat)/2) + firstSeat;
        } else if (chunk[i] == 'R') {
            firstSeat = lastSeat - floor((lastSeat - firstSeat)/2);
        }
        // printf("%c %f %f\n",chunk[i],firstSeat,lastSeat);
    }

    seat = lastSeat;
    printf("Seat %d\n", seat);

    int seatID = row * 8 + seat;

    maxSeatID = (maxSeatID > seatID) ? maxSeatID : seatID;

    printf("%d %d %d %d\n",row,seat,seatID,maxSeatID);
    lastRow = 127;
    firstRow = 0;
    lastSeat = 7;
    firstSeat = 0;
    
        }

    printf("Max seat ID: %d\n", maxSeatID);



        return 0;

}

 