#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void findMySeat(int *seats, int counter);
int cmpfunc (const void * a, const void * b);

int main(void){

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day05/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    char chunk[64];

    int maxSeatID = 0;

    float lastSeat = 7;
    float firstSeat = 0;

    int *seats = malloc(sizeof(int));
    int counter = 0;
    int seatID = 0;


    while (fgets(chunk, sizeof(chunk), fp) != NULL){
        float lastRow = 127;
        float firstRow = 0;
        int row = 0;
        int seat = 0;   
        float lastSeat = 7;
        float firstSeat = 0;
        chunk[strlen(chunk) -1] = '\0';

        for (int i = 0; i < strlen(chunk)-3; i++) {
            if (chunk[i] == 'F') {
                lastRow = floor((lastRow - firstRow)/2) + firstRow;
            } else if (chunk[i] == 'B') {
                firstRow = lastRow - floor((lastRow - firstRow)/2);
            }
            // printf("%c %f %f\n",chunk[i],firstRow,lastRow);
        }

        row = lastRow;
        // printf("Row: %d\n", row);

        for (int i = strlen(chunk) -3; i < strlen(chunk);i++) {
            if (chunk[i] == 'L') {
                lastSeat = floor((lastSeat - firstSeat)/2) + firstSeat;
            } else if (chunk[i] == 'R') {
                firstSeat = lastSeat - floor((lastSeat - firstSeat)/2);
            }
            // printf("%c %f %f\n",chunk[i],firstSeat,lastSeat);
        }

        seat = lastSeat;
        // printf("Seat %d\n", seat);

        seatID = (row * 8) + seat;

        // printf("%d %s %d %d %d\n",counter,chunk,row,seat,seatID);

        // memcpy(seats[counter],seatID,sizeof(int));
        seats[counter] = seatID;
        seats = realloc(seats, sizeof(int) * (counter + 2));
        counter++;

    
    }

    findMySeat(seats, counter);

    return 0;

}


void findMySeat (int *seats, int counter) {
    
    qsort(seats, counter, sizeof(int), cmpfunc);

    for (int i = 1; i < counter; i++) {
        printf("seat ID = %d\n", seats[i]);
        if (seats[i+1] - seats[i] == 2) {
            printf("%d %d Your seat ID is: %d\n",seats[i+1], seats[i],seats[i]+1);
            // break;
        }
    }

}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}   

 