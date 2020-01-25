#include <stdio.h>
#include <stdlib.h>
#include "switchboard.h"
#include "inputparser.h"

int main() {

    char str[] = "3,15,3,16,1002,16,10,16,1,16,15,15,4,15,99,0,0";

    int *intCodes;
    int systemId;
    int *tmpIntCodes;
    int modeOne = 0;
    int modeTwo = 0;
    int instruction = 0;

    opcodes parsedString = parse(str);

    intCodes = parsedString.intcodes;
    int intCodesSize = parsedString.size;

    for (int i = 0;i<intCodesSize;i++) {
        printf("%d - %d\n", i, intCodes[i]);
    }

    // while (pos <= counter)
    // {
    //    pos = parameterMode(pos, intCodes);
    // }

    return 0;
}