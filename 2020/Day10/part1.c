#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define countOfAdapters 93

void sortAdapters(long adapters[countOfAdapters], int end);

long adapters[countOfAdapters+2];

int main() {
    
    char chunk[10];
    int end = 1;
    int oneDifference = 0;
    int threeDifference = 0;
    adapters[0] = 0;

    
    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day10/test.txt","r");


    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }


    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        char *strPtr;
        adapters[end] = strtol(chunk,&strPtr,10);
        end++;
       
    }
    
    sortAdapters(adapters, end);
    
    adapters[end + 1] = adapters[end] + 3;
    end++;
    
    for (int i = 0; i < end; i++) {
        if ((adapters[i+1] - adapters[i]) == 1){
            oneDifference++;
        } else if ((adapters[i+1] - adapters[i]) == 3) {
            threeDifference++;
        }
    }
    
    printf("3 - %d 1 - %d\n", threeDifference, oneDifference);
    printf("product = %d\n",oneDifference * threeDifference);
    


  
return 0;
            
}


void sortAdapters(long adapters[countOfAdapters], int end) {
    long tmp;
    for (int i = 0; i < end; ++i) {
        for (int j = 0; j < end; ++j){
            if (adapters[i] < adapters[j]) {
                tmp = adapters[i];
                adapters[i] = adapters[j];
                adapters[j] = tmp;
            }
        }
    }
}
