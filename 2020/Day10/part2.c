#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define countOfAdapters 93


void sortAdapters(long adapters[countOfAdapters], int end);
void calculate(int groupCounts[93]);

long adapters[countOfAdapters+2] = { 0 };
int groupCounts[93];
int groupEnd = 0;


int main() {
    
    char chunk[10];
    int end = 1;
    adapters[0] = 0;
    int groupCount = 0;
    memset(groupCounts, 0, sizeof(groupCounts));

    
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day10/data.txt","r");


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
    
    adapters[end] = adapters[end-1] + 3;
//    end++;
    
    for (int i = end; i >= 0; i--) {
        if ( (adapters[i] - adapters[i-1]) >= 3) {
            if (groupCount != 0) {
                groupCounts[groupEnd] = groupCount;
                groupEnd++;
                groupCount = 0;
            }
            continue;
        } else if ((adapters[i] - adapters[i-1]) == 1) {
            if ((adapters[i] - adapters[i-2]) >= 3) {
                if (groupCount != 0) {
                    groupCounts[groupEnd] = groupCount;
                    groupEnd++;
                    groupCount = 0;
                }
                continue;
            } else if (adapters[i -1] == 0) {
                if (groupCount != 0) {
                    groupCounts[groupEnd] = groupCount;
                    groupEnd++;
                    groupCount = 0;
                }
                continue;
            } else {
                groupCount++;
            }
            
        }
    }
    
    calculate(groupCounts);

  
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


void calculate(int groupCounts[93]) {
    int i = 0;
    long long total = 1;
    int offset=0;
    while (groupCounts[i] != 0) {
        printf("loop %d has %d",i,groupCounts[i]);
        switch(groupCounts[i]){
            case 0 :
                break;
            case 1 :
                offset = 0;
                break;
            case 2:
                offset = 0;
                break;
            case 3:
                offset = 1;
                break;
            default:
                offset = groupCounts[i] -2;
        }
        total = total * (pow(2,groupCounts[i])-offset);
        i++;
    }
    
    printf("total combinations %lld\n",total);
}
