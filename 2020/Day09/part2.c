#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define preambleLength 25
#define invalidNumber 20874512

long sumNumbers( long tmpArray[1000], int tmpEnd);


int main() {
    
    long numbers[1000];
    memset(numbers, 0, sizeof(long)*20);
    int end = 0;
    char chunk[100];
    long tmpArray[1000];
    memset(tmpArray, 0, sizeof(long) * 1000);
    int tmpEnd = 0;
    long currentSum = 0;

    
    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day09/data.txt","r");


    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }


    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        char *strPtr;
        numbers[end] = strtol(chunk,&strPtr,10);
        end++;
       
    }
    

    for (int i = 0; i < end; i++) {
        printf("current number %ld\n",numbers[i]);
        if ( numbers[i] >= invalidNumber) {
            memset(tmpArray, 0, sizeof(long) * 1000);
            tmpEnd = 0;
            continue;
        } else if ( currentSum < invalidNumber) {
            tmpArray[tmpEnd] = numbers[i];
        }
        
        currentSum = sumNumbers(tmpArray, tmpEnd);
        printf("current sum %ld\n", currentSum);
        if (currentSum == invalidNumber) {
            printf("found the location at %d\n",i);
            exit(0);
        } else if ( currentSum < invalidNumber) {
            tmpEnd++;
            continue;
        } else if ( currentSum > invalidNumber) {
            memset(tmpArray, 0, sizeof(long) * 1000);
            tmpEnd = 0;
        }
    
    }
return 0;
            
}

long sumNumbers(long tmpArray[1000], int tmpEnd) {
    long currentSum = 0;
    for (int i = 0; i < tmpEnd; i++){
        currentSum = currentSum + tmpArray[i];
//        printf("%ld ",tmpArray[i]);
    }

    
    return currentSum;
}
