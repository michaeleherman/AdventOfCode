#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define preambleLength 25
#define numberSize 1000
#define invalidNumber 20874512
//#define invalidNumber 127



long sumNumbers( long tmpArray[numberSize], int startPos, int tmpEnd);
void getMinMax(long numbers[numberSize], int startPos, int tmpEnd);


int main() {
    
    long numbers[numberSize];
    memset(numbers, 0, sizeof(long)*preambleLength);
    int end = 0;
    char chunk[100];
    long tmpArray[numberSize];
    memset(tmpArray, 0, sizeof(long) * numberSize);
    int tmpEnd = 0;
    long currentSum = 0;
    int startPos = 0;

    
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
//            memset(tmpArray, 0, sizeof(long) * numberSize);
            startPos = i+1;
            tmpEnd = startPos;
            continue;
        }
//        } else if ( currentSum < invalidNumber) {
//            tmpArray[tmpEnd] = numbers[i];
//        }
        
        currentSum = sumNumbers(numbers, startPos, tmpEnd);
//        printf("current sum %ld\n", currentSum);
        if (currentSum == invalidNumber) {
            printf("found the location at %d\n",i);
            getMinMax(numbers, startPos, tmpEnd);
            exit(0);
        } else if ( currentSum < invalidNumber) {
            tmpEnd++;
            continue;
        } else if ( currentSum > invalidNumber) {
//            memset(tmpArray, 0, sizeof(long) * numberSize);
            i = startPos;
            startPos++;
            tmpEnd = startPos;;
        }
    
    }
return 0;
            
}

long sumNumbers(long numbers[numberSize], int startPos, int tmpEnd) {
    long currentSum = 0;
    for (int i = startPos; i <= tmpEnd; i++){
        currentSum = currentSum + numbers[i];
//        printf("%ld ",tmpArray[i]);
    }

    
    return currentSum;
}

void getMinMax(long numbers[numberSize], int startPos, int tmpEnd) {
    long min = invalidNumber;
    long max = 0;
    
    for (int i = startPos;i <= tmpEnd; i++){
        printf("value it i is %ld\n", numbers[i]);
//        result = a > b ? x : y;
        min = numbers[i] < min ? numbers[i] : min;
        max = numbers[i] > max ? numbers[i] : max;
    }
    
    printf("Min %ld Max %ld\n",min, max);
    printf("Sum of min and max %ld\n", min + max);
}


