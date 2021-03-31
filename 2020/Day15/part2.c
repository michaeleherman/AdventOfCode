#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHUNK_SIZE 512
#define TARGET 30000000

struct obj {
    int lastPos;
    int currentPos;
};

void updateArray(int *end, int *tmpLoc);

struct obj *numArray;

int main(void){
    
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day15/test.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    char chunk[CHUNK_SIZE];
    int end = 0;
    int tokenCount = 0;
    numArray = malloc(sizeof(struct obj));
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        char delim[2] = ",";
        char *token = strtok(chunk,delim);
        while (token != NULL){
            int tmpLoc = atoi(token);
            if (end < tmpLoc) {
                updateArray(&end, &tmpLoc);
            }
            numArray[tmpLoc].currentPos = tokenCount;
            numArray[tmpLoc].lastPos = tokenCount;
            tokenCount++;
            token = strtok(NULL,delim);
            end++;
        }
    }
    
    int loop = tokenCount-1;
    int arrayLoc = end -1;
    int nextArrayLoc = 0;
    int spokenNumber = 0;
    
    while (loop != TARGET -1 ) {

        if (numArray[arrayLoc].currentPos - numArray[arrayLoc].lastPos == 0) {
            numArray[arrayLoc].lastPos = numArray[arrayLoc].currentPos;
            numArray[arrayLoc].currentPos = loop;
            nextArrayLoc = numArray[arrayLoc].currentPos - numArray[arrayLoc].lastPos;
            printf("%d - %d\n", loop, arrayLoc);
        } else {
            numArray[arrayLoc].lastPos = numArray[arrayLoc].currentPos;
            numArray[arrayLoc].currentPos = loop;
            arrayLoc = numArray[arrayLoc].currentPos - numArray[arrayLoc].lastPos;
        }

        
        
        loop++;
        if (loop == 10) {
            exit(0);
        }
    }
    
    return 0;
    
}

void updateArray(int *end, int *tmpLoc) {
    int oldEnd = *end;
    *end = *tmpLoc;
    numArray = realloc(numArray,sizeof(struct obj) * (*end + 2));
    for (int i = oldEnd;i < *end;i++) {
        numArray[i].currentPos = i;
        numArray[i].lastPos = i;
    }
}


//numArray[prevNum].currentPos - numArray[prevNum].lastPos == 0
