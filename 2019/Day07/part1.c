#include <stdio.h>
#include <stdlib.h>
#include "switchboard.h"
#include "inputparser.h"
#include "combinator.h"
#include "ampfeeder.h"
#include <string.h>
#include "factorial.h"

#define ARRSIZE 5

int main() {
    
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
    
    
    char str[] = "3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0";
    int *arr = malloc(sizeof(int) * ARRSIZE);
    int countOfAmpCombos = factorial(ARRSIZE); //Get total number of amplifier combos
    
    //populate amplifier array
    for (int i = ARRSIZE - 1; i >= 0; --i) {
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
    results.resultsCount = 0;
    results = permutator(arr, ARRSIZE, countOfAmpCombos);
    
    
    int *thrustArray = malloc(sizeof(int)); //initialize array for returned thrusts
    
    //Loop through each array of amplifier combinations
    for (int i = 0; i < countOfAmpCombos;i++) {
        
        int maxThrust = processArray(results.results[i],ARRSIZE,intCodes,intCodesSize);
        thrustArray[i] = maxThrust;
        thrustArray = realloc(thrustArray, sizeof(int) * (i + 2));
    }
    
    int maxThrust = getMax(thrustArray);
    
    //print contents of thrustarray
    for (int i = 0; i< countOfAmpCombos;i++) {
        printf("%d\n",thrustArray[i]);
        
    }
    
    printf("Max thrust is: %d\n",maxThrust);
    
    
    
    return 0;
}
