#include <stdio.h>
#include <stdlib.h>
#include "switchboard.h"
#include "inputparser.h"
#include <string.h>
#include <time.h>

int main() {
    
    clock_t start, end;
    start = clock();
    
    //Provide each amplifier its phase setting at its first input instruction; all further input/output instructions are for signals.
    //Don't restart the Amplifier Controller Software on any amplifier during this process.
    //To start the process, a 0 signal is sent to amplifier A's input exactly once.
    
    
    char str[] = "109,1,204,-1,1001,100,1,100,1008,100,16,101,1006,101,0,99";
    
    int *intCodes = malloc(sizeof(int));
    int intCodesSize = 0;
    
    char *token = strtok(str,",");
    
    while (token != NULL) {
        intCodes[intCodesSize] = atoi(token);
        intCodesSize++;
        intCodes = realloc(intCodes, (intCodesSize + 1) *(sizeof(int)));
        token = strtok(NULL,",");
    }
    
    int val = 0;
    int i = 0;
    int tmpVal = 0;
    
    while ( intCodes[intCodesSize] != 99 ) {
        
        val = parameterMode(i, intCodes, tmpVal, intCodesSize);
        tmpVal = val;
        if (intCodes[intCodesSize] == 4) {
            printf ("%d",val);
        }
    }
    
    

    
    
    end = clock();
    double time_taken = end - start;
    printf("Time: %f\n",time_taken/CLOCKS_PER_SEC);
    
    return 0;
    
}
