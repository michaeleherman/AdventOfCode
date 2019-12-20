#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "functions.h"

    void opcode4(int outputPos, int *intCodes)
{
    printf("Output is: %d", intCodes[intCodes[outputPos]]);
}

void parameterMode(int pos, int *intCodes, int systemId)
{
    int currOpcode = intCodes[pos];
    int opcodeLength = sizeof(currOpcode);
    char *opCodeString;
    sprintf(opCodeString, "%d", currOpcode);
    // char *opCodeString = itoa(currOpcode);
    int instruction = currOpcode % 100;

    int paramOne = atoi(&opCodeString[1]);
    int paramTwo = atoi(&opCodeString[0]);

    int pos1 = (paramOne == 0) ? (intCodes[intCodes[pos + 1]]) : (intCodes[pos + 1]);
    int pos2 = (paramTwo == 0) ? (intCodes[intCodes[pos + 1]]) : (intCodes[pos + 1]);

    if (instruction == 1)
    {
        (intCodes[intCodes[pos + 3]] = intCodes[pos1] + intCodes[pos2]);
    } else if (instruction == 2) {
        (intCodes[intCodes[pos + 3]] = intCodes[pos1] * intCodes[pos2]);
    }
}

int switcher(int pos, int systemId, int *intCodes)
{
    switch (intCodes[pos])
    {
    case 1:
    {
        intCodes[intCodes[pos + 3]] = intCodes[intCodes[pos + 1]] + intCodes[intCodes[pos + 2]];
        pos += 3;
        break;
    }
    case 2:
    {
        intCodes[intCodes[pos + 3]] = intCodes[intCodes[pos + 1]] * intCodes[intCodes[pos + 2]];
        pos += 3;
        break;
    }
    case 3:
    {
        printf("Please enter the system ID: ");
        scanf("%d", &systemId);
        intCodes[intCodes[pos + 1]] = systemId;
        pos += 1;
        break;
    }
    case 4:
    {
        printf("Output is: %d", intCodes[intCodes[pos + 1]]);
        break;
    }
    default:
    {
        parameterMode(pos, intCodes, systemId);
    }
    }
    return pos;
}