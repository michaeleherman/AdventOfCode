#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "functions.h"

void printStuff(int pos, int instruction, int val1, int val2, int val3)
{
    printf("Position: %d\n", pos);
    printf("Instruction: %d\n", instruction);
    printf("Values to use: %d, %d\n", val1, val2);
    printf("Destination Position: %d\n\n\n", val3);
}

void opcode4(int outputPos, int *intCodes)
{
    printf("Output is: %d", intCodes[intCodes[outputPos]]);
}

void parameterMode(int pos, int *intCodes, int systemId)
{
    int currOpcode = intCodes[pos];
    int opcodeLength = sizeof(currOpcode);
    char opCodeString[5] = {'\0'};

    sprintf(opCodeString, "%04d", currOpcode);

    // char *opCodeString = itoa(currOpcode);
    int instruction = currOpcode % 100;

    char charOne[2];
    char charTwo[2];

    int paramOne = 0;
    int paramTwo = 0;
    int pos1, pos2 = 0;

    paramOne = atoi(strncpy(charOne, &opCodeString[1], sizeof(char)));
    paramTwo = atoi(strncpy(charTwo, &opCodeString[0], sizeof(char)));

    pos1 = (paramOne == 0) ? (intCodes[intCodes[pos + 1]]) : (intCodes[pos + 1]);
    pos2 = (paramTwo == 0) ? (intCodes[intCodes[pos + 2]]) : (intCodes[pos + 2]);
    printf("Current start POS: %d\n", pos);
    if (instruction == 1)
    {
        (intCodes[intCodes[pos + 3]] = intCodes[pos1] + intCodes[pos2]);
    }
    else if (instruction == 2)
    {
        (intCodes[intCodes[pos + 3]] = intCodes[pos1] * intCodes[pos2]);
    }

    printStuff(pos, instruction, pos1, pos2, intCodes[pos + 3]);
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
        printf("Output is: %d\n", intCodes[intCodes[pos + 1]]);
        pos += 1;
        break;
    }

    case 99:
    {
        exit(0);
    }
    default:
    {
        parameterMode(pos, intCodes, systemId);
        pos += 3;
    }
    }
    return pos;
}