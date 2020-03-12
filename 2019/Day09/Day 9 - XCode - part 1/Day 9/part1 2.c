#include <stdio.h>
#include <stdlib.h>
#include "switchboard.h"
#include "inputparser.h"
#include "combinator.h"
#include "ampfeeder.h"
#include <string.h>
#include "factorial.h"
#include "getmax.h"
#include <time.h>

#define ARRSIZE 5

int main() {
    
    clock_t start, end;
    start = clock();
    
    //Provide each amplifier its phase setting at its first input instruction; all further input/output instructions are for signals.
    //Don't restart the Amplifier Controller Software on any amplifier during this process.
    //To start the process, a 0 signal is sent to amplifier A's input exactly once.
    
    
    char str[] = "3,26,1001,26,-4,26,3,27,1002,27,2,27,1,27,26,27,4,27,1001,28,-1,28,1005,28,6,99,0,0,5";
    int *arr = malloc(sizeof(int) * ARRSIZE);
    int countOfAmpCombos = factorial(ARRSIZE); //Get total number of amplifier combos
    
    //populate amplifier array
    //the amplifiers need totally different phase settings: integers from 5 to 9
    for (int i = ARRSIZE-1; i >= 0; --i) {
        arr[i] = i+5;
        
    }
    
    //turn string of opcodes into array of opcodes
    int *intCodes;
    int intCodesSize;
    opcodes opArray = parse(str);
    intCodes = opArray.intcodes;
    intCodesSize = opArray.size;
    
    //get combinations
    combo results; //initialize results struct
    results.results = calloc(countOfAmpCombos,sizeof(int*));
    results.resultsCount = 0;
    results = permutator(arr, ARRSIZE, countOfAmpCombos);
    
    
    int *thrustArray = calloc(countOfAmpCombos,sizeof(int)); //initialize array for returned thrusts
    
    //Loop through each array of amplifier combinations
    for (int i = 0; i < countOfAmpCombos;i++) {
        
        int maxThrust = processArray(results.results[i],ARRSIZE,intCodes,intCodesSize);
        thrustArray[i] = maxThrust;
        
    }
    
    int maxThrust = getMax(thrustArray,countOfAmpCombos);
    
    //print contents of thrustarray
    //    for (int i = 0; i< countOfAmpCombos;i++) {
    //        printf("%d\n",thrustArray[i]);
    //
    //    }
    
    printf("Max thrust is: %d\n",maxThrust);
    
    end = clock();
    double time_taken = end - start;
    printf("Time: %f\n",time_taken/CLOCKS_PER_SEC);
    
    return 0;
    
}
