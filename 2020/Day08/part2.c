#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



struct instruction {
    char operation[10];
    int value;
};



int runConsole(char chunks[700][50], int end);
void modifier(char chunks[700][50], int end) ;

int *executed;
long accumulator = 0;



int main() {
    
    executed = calloc(700, sizeof(int));
    char chunk[50];
    char chunks[700][50];
    int end = 0;
    
    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day08/data.txt","r");


    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }


    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (chunk[strlen(chunk) -1]== '\n') {
            chunk[strlen(chunk) -1] = '\0';
        }
       
        strcpy(chunks[end],chunk);
        end++;

    }
    
    modifier(chunks, end);
    

return 0;
            
}

void modifier(char chunks[700][50], int end) {
    char tmpChunks[700][50];
    memcpy(tmpChunks,chunks,700*50*sizeof(char));
    char tmpOp[4];
    char value[10];
    for (int i = 0; i < end; i++) {
        accumulator = 0;
        memcpy(tmpChunks,chunks,700*50*sizeof(char));
        memset(executed, 0, 700 * sizeof(int));
        sscanf(chunks[i],"%s %s",tmpOp, value);
        if (strcmp(tmpOp,"jmp") == 0) {
            sprintf(tmpChunks[i],"%s %s","nop",value);
        }
        if (strcmp(tmpOp,"nop") == 0) {
            sprintf(tmpChunks[i],"%s %s","jmp",value);
        }
        if (runConsole(tmpChunks, end) == 1) {
            printf("found the one on loop %d -  %ld\n", i, accumulator);
            exit(0);
        } else {
            printf("not the one on loop %d\n",i);
        }
    }


}


int runConsole(char tmpChunks[700][50], int end) {
    int loopCount = 0;
    char operation[10];
    char *strPtr;
    long value;
//    char delim[2] = " ";
    char tmpValue[10];
    
//    operation = strtok(tmpChunks[0],delim);
//    value = strtol(strtok(NULL, delim),&strPtr, 10);
    
    long i = 0;
    while ( i < end) {
        sscanf(tmpChunks[i],"%s %s",operation, tmpValue);
        value = strtol(tmpValue,&strPtr, 10);
        if (executed[i] == 1) {
            return 0;
        }
        if (strcmp(operation,"acc") == 0) {
            accumulator = accumulator + value;
            executed[i] = 1;
            i++;
        } else if (strcmp(operation,"nop") == 0) {
            executed[i] = 1;
            i++;
        } else {
            executed[i] = 1;
            if ( value == 0) {
                return 0;
            }
            i = i + value;
        }
        
        if (i >= end) {
            return 1;
        }
        
        loopCount++;
//        operation = strtok(tmpChunks[i],delim);
//        value = strtol(strtok(NULL, delim),&strPtr, 10);
        
    }
    
    return 0;
}
