#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define preambleLength 25

enum method {
    min,
    max,
};

struct minMax {
    long min;
    long max;
};

void getThePreamble(long numbers[20], int startPos);
struct minMax getEnds(long preambleArray[preambleLength]);
int iterate(long preambleArray[preambleLength], long testNum);

long preambleArray[preambleLength];

int main() {
    
    long numbers[1000];
    memset(numbers, 0, sizeof(long)*20);
    int end = 0;
    char chunk[100];
    int currentPos = 0 + preambleLength;

    
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
    

    
    
    for (int i = currentPos; i < end; i++) {
        getThePreamble(numbers, i);
//        struct minMax ends = getEnds(preambleArray);
//        if ( numbers[i] >= ends.max || numbers[i] <= ends.min) {
//            printf("bad number %ld\n",numbers[i]);
//            exit(0);
//        }
        
        if (iterate(preambleArray, numbers[i]) == 1) {
            printf("The bad number is %ld\n",numbers[i]);
            exit(0);
        } else {
            printf("%ld is good\n", numbers[i]);
        }
    }
       

    


return 0;
            
}


void getThePreamble(long numbers[20], int currentPos){
    memset(preambleArray,0,sizeof(long) * preambleLength);
    int j = 0;
    for (int i = currentPos - preambleLength; i < currentPos; i++) {
        preambleArray[j] = numbers[i];
        j++;
    }
}

//struct minMax getEnds(long preambleArray[preambleLength]) {
//    struct minMax node;
//    node.min = preambleArray[0];
//    node.max = preambleArray[0];
//        for (int i = 0; i < preambleLength -1; i++) {
//            if (node.min < preambleArray[i + 1]) {
//                node.min = preambleArray[i];
//            } else {
//                node.min = preambleArray[i + 1];
//            }
//
//            if (node.max > preambleArray[i + 1]) {
//                node.max = preambleArray[i];
//            } else {
//                node.max = preambleArray[i + 1];
//            }
//        }
//    return node;
//}


int iterate(long preambleArray[preambleLength], long testNum) {
    
    for (int i = 0; i < preambleLength;i++) {
        for (int j = 0; j < preambleLength; j++) {
            if (i == j) {
                continue;
            }
            if (preambleArray[i] + preambleArray[j] == testNum) {
                return 0;
            }
        }
    }
    return 1;
}
