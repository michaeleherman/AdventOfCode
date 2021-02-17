#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



struct instruction {
    char operation[10];
    int value;
};



void runConsole(char chunks[700][50], int end);

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
    
    runConsole(chunks, end);
    

return 0;
            
}


void runConsole(char chunks[700][50], int end) {
    int loopCount = 0;
    char *operation;
    char *strPtr;
    long value;
    char delim[2] = " ";
    
    operation = strtok(chunks[0],delim);
    value = strtol(strtok(NULL, delim),&strPtr, 10);
    
    long i = 0;
    while ( i < 999) {

        if (strcmp(operation,"acc") == 0) {
            accumulator = accumulator + value;
            executed[i] = 1;
            i++;
        } else if (strcmp(operation,"nop") == 0) {
            executed[i] = 1;
            i++;
        } else {
            executed[i] = 1;
            i = i + value;

        }
        loopCount++;
        if (executed[i] == 1) {
            printf("Loop count %d total accumulated is %ld\n", loopCount,accumulator);
            break;
        }
        operation = strtok(chunks[i],delim);
        value = strtol(strtok(NULL, delim),&strPtr, 10);
        
    }
}
