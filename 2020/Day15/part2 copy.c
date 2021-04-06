#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
     
#define CHUNK_SIZE 512
#define TARGET 30000000
#define TESTCOUNT 50
#define fileName "/Users/michael.herman/Code/AdventOfCode/2020/Day15/data.txt"

struct obj {
    int lastPos;
    int currentPos;
};

int updateArray(int end, int tmpLoc);

struct obj numArray[TARGET];
clock_t start, end;
double cpu_time_used;

int main(void){
    start = clock();
    
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    char chunk[CHUNK_SIZE];
    int end = 0;
    int tokenCount = 0;
    int tmpLoc = 0;
    // numArray = malloc(sizeof(struct obj));
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        char delim[2] = ",";
        char *token = strtok(chunk,delim);
        while (token != NULL){
            tmpLoc = atoi(token);
             if (end <= tmpLoc) {
                 end = updateArray(end, tmpLoc);
             }
            numArray[tmpLoc].currentPos = tokenCount;
            numArray[tmpLoc].lastPos = tokenCount;
            tokenCount++;
            token = strtok(NULL,delim);

//            end++;
        }
    }
    
    int loop = tokenCount;
    int prevLoc = tmpLoc;
    int currLoc = 0;
    int spokenNumber = 0;
    int locDelta = 0;
    
    while (loop < TARGET -1) {
//        if (spokenNumber == 10) {
//            printf("hit spoken number %d",spokenNumber);
//            exit(0);
//        }
        locDelta = numArray[prevLoc].currentPos - numArray[prevLoc].lastPos;
         if (end <= locDelta){
             end = updateArray(end, locDelta);
         }
        
        if (numArray[prevLoc].lastPos == -1) {
            numArray[prevLoc].lastPos = 0;
            currLoc = 0;
            numArray[currLoc].lastPos = 0;
            numArray[currLoc].currentPos = loop;
        } else {
            currLoc = locDelta;
            if (numArray[currLoc].lastPos == -1) {
                numArray[currLoc].lastPos = loop;
                numArray[currLoc].currentPos = loop;
            } else {
                numArray[currLoc].lastPos = numArray[currLoc].currentPos;
                numArray[currLoc].currentPos = loop;
            }

        }
        
        prevLoc = currLoc;
        loop++;
        spokenNumber = numArray[prevLoc].currentPos - numArray[prevLoc].lastPos;
        if (loop == TARGET -1) {
            printf("loop: %d spokenNumber: %d\n",loop, spokenNumber);
        }
//        if (loop == TESTCOUNT) {
//            exit(0);
//        }
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("execution time %f\n",cpu_time_used);
    return 0;
    
}

 int updateArray(int end, int tmpLoc) {
     int oldEnd = end;
//     numArray = realloc(numArray,sizeof(struct obj) * (tmpLoc + 2));
     for (int i = oldEnd;i <= tmpLoc;i++) {
         end++;
         numArray[i].currentPos = 0;
         numArray[i].lastPos = -1;
     }
     return end;
 }


//numArray[prevNum].currentPos - numArray[prevNum].lastPos == 0



