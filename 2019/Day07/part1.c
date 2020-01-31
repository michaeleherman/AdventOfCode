#include <stdio.h>
#include <stdlib.h>
#include "switchboard.h"
#include "inputparser.h"
#include "combinator.h"

int main() {

    char str[] = "3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0";
    int arr[5] = {0, 1, 2, 3, 4};

    int *intCodes;


    opcodes parsedString = parse(str);

    intCodes = parsedString.intcodes;
    int intCodesSize = parsedString.size;

    combo comboData = permutator(arr, 5);
    


    for (int h = 0; h < 120;h++)
    {   for (int i = 0; i< 5;i++) {
        printf("%d ",result[h][i]);
        resultCount++;
    }
        printf("\n");}

    return 0;
}
