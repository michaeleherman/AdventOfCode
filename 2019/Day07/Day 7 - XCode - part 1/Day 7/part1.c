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
    
    //    1. parse opcode string into array
    //    2. create array of amplifier combinations
    //        For each set of amplifier combinations
    //            for each amplifier (pass current amp combo and codes)
    //                opcode value, pass to opcode computer
    //                    if opcode = 3, pass input value (first amplifier, second thrust)
    //                    if opcode = 4, expect thrust return
    //            add thrust value to thrust value for set
    //        insert thrust into array of thrusts
    //    find greatest signal in array of thrusts
    
    
    char str[] = "3,8,1001,8,10,8,105,1,0,0,21,46,55,76,89,106,187,268,349,430,99999,3,9,101,4,9,9,1002,9,2,9,101,5,9,9,1002,9,2,9,101,2,9,9,4,9,99,3,9,1002,9,5,9,4,9,99,3,9,1001,9,2,9,1002,9,4,9,101,2,9,9,1002,9,3,9,4,9,99,3,9,1001,9,3,9,1002,9,2,9,4,9,99,3,9,1002,9,4,9,1001,9,4,9,102,5,9,9,4,9,99,3,9,101,1,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,1,9,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,99,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,99,3,9,101,1,9,9,4,9,3,9,101,1,9,9,4,9,3,9,101,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,1001,9,2,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,99,3,9,101,1,9,9,4,9,3,9,102,2,9,9,4,9,3,9,101,2,9,9,4,9,3,9,101,1,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1002,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,2,9,4,9,3,9,102,2,9,9,4,9,3,9,101,1,9,9,4,9,99,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,102,2,9,9,4,9,3,9,102,2,9,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1001,9,1,9,4,9,3,9,1002,9,2,9,4,9,3,9,101,2,9,9,4,9,3,9,101,1,9,9,4,9,99";
    int *arr = malloc(sizeof(int) * ARRSIZE);
    int countOfAmpCombos = factorial(ARRSIZE); //Get total number of amplifier combos
    
    //populate amplifier array
    for (int i = ARRSIZE-1; i >= 0; --i) {
        arr[i] = i;
        
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
