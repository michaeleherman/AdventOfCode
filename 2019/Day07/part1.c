#include <stdio.h>
#include <stdlib.h>
#include "switchboard.h"
#include "inputparser.h"
#include "combinator.h"
#include <string.h>

int main() {

    char str[] = "3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0";
    int arr[5] = {0, 1, 2, 3, 4};
    combo results;
    memset(results.results,0,sizeof(int)*120);
    results.resultsCount = 0;

    int *intCodes;
    int intCodesSize;
    
    opcodes opArray = parse(str);
    intCodes = opArray.intcodes;
    intCodesSize = opArray.size;


    results = permutator(arr, 5); //gets the combinations of arr
    
    //send each array in results to ampfeeder
    
    
    

    for (int h = 0; h < results.resultsCount;h++)
    {   for (int i = 0; i< 5;i++) {
        printf("%d ",results.results[h][i]);
    }
        printf("\n");}

    return 0;
}
