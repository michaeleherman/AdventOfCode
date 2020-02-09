#include <stdio.h>
#include <stdlib.h>
#include "switchboard.h"
#include "inputparser.h"
#include "combinator.h"
#include "ampfeeder.h"
#include <string.h>
#include "factorial.h"
#include "getmax.h"

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
    
    
    char str[] = "3,31,3,32,1002,32,10,32,1001,31,-2,31,1007,31,0,33,1002,33,7,33,1,33,31,31,1,32,31,31,4,31,99,0,0,0";
    int *arr = malloc(sizeof(int) * ARRSIZE);
    int countOfAmpCombos = factorial(ARRSIZE); //Get total number of amplifier combos
    
    //populate amplifier array
    for (int i = ARRSIZE-1; i >= 0; --i) {
        arr[i] = i;
        printf("%d - %d\n",i,arr[i]);
        
    }
    printf("\n");
    
    
    
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
    
    
    for (int m = 0; m < countOfAmpCombos;m++) {
        printf("%d - ",m);
         for (int n = 0; n < 5; n++) {
               printf("%d ", results.results[m][n]);
    
           }
                      printf("\n");
    }
    
    
    int *thrustArray = calloc(countOfAmpCombos,sizeof(int)); //initialize array for returned thrusts
    
    //Loop through each array of amplifier combinations
    for (int i = 0; i < countOfAmpCombos;i++) {
        
        int maxThrust = processArray(results.results[i],ARRSIZE,intCodes,intCodesSize);
        thrustArray[i] = maxThrust;

    }
    
    int maxThrust = getMax(thrustArray,countOfAmpCombos);
    
    //print contents of thrustarray
    for (int i = 0; i< countOfAmpCombos;i++) {
        printf("%d\n",thrustArray[i]);
        
    }
    
    printf("Max thrust is: %d\n",maxThrust);
    
    
    
    return 0;
}
