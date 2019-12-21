#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "functions.h"

void printStuff(const char source[14], int pos, int instruction, int val1, int val2, int val3)
{
    printf("Source function: %s Position: %d\n", source, pos);
    printf("Instruction: %d\n", instruction);
    printf("Values to use: %d, %d\n", val1, val2);
    printf("Destination Position: %d\n\n\n", val3);
}

void opcode1(int pos1, int pos1Mode, int pos2, int pos2Mode, int pos3, int *intCodes)
{

    pos1 = (pos1Mode == 0) ? (intCodes[intCodes[pos1]]) : (intCodes[pos1]);
    pos2 = (pos2Mode == 0) ? (intCodes[intCodes[pos2]]) : (intCodes[pos2]);

    intCodes[intCodes[pos3]] = pos1 + pos2;
}

void opcode2(int pos1, int pos1Mode, int pos2, char pos2Mode, int pos3, int *intCodes)
{

    pos1 = (pos1Mode == 0) ? (intCodes[intCodes[pos1]]) : (intCodes[pos1]);
    pos2 = (pos2Mode == 0) ? (intCodes[intCodes[pos2]]) : (intCodes[pos2]);

    intCodes[intCodes[pos3]] = pos1 * pos2;
}

void opcode3(int pos, int *intCodes)
{
    int systemId;
    printf("Please enter the system ID: ");
    scanf("%d", &systemId);
    intCodes[intCodes[pos + 1]] = systemId;
}

void opcode4(int outputPos, int *intCodes)
{
    printf("Output is: %d\n", outputPos);
}

//Jump if true
void opcode5(int pos, int *intCodes)
{
    int param1 = intCodes[pos + 1];
    int param2 = intCodes[pos + 2];
    int instruction = 0;

    if (param1 != 0)
    {
        instruction = param2;
    }
}

//Jump if false
void opcode6(int pos, int *intCodes)
{
    int param1 = intCodes[pos + 1];
    int param2 = intCodes[pos + 2];
    int instruction = 0;

    if (param1 == 0)
    {
        instruction = param2;
    }
}

//less than
void opcode7(int pos, int *intCodes)
{
    int param1 = intCodes[pos + 1];
    int param2 = intCodes[pos + 2];
    int param3 = intCodes[pos + 3];
    int instruction = 0;

    intCodes[param3] = (param1 < param2) ? 1 : 0;
}

//equals
void opcode8(int pos, int *intCodes)
{
    int param1 = intCodes[pos + 1];
    int param2 = intCodes[pos + 2];
    int param3 = intCodes[pos + 3];
    int instruction = 0;

    intCodes[param3] = (param1 == param2) ? 1 : 0;
}

void parameterMode(int pos, int *intCodes)
{
    int currOpcode = intCodes[pos];
    int opcodeLength = sizeof(currOpcode);
    char opCodeString[5] = {'\0'};

    sprintf(opCodeString, "%04d", currOpcode);

    // char *opCodeString = itoa(currOpcode);
    int instruction = currOpcode % 100;

    char charOne[2];
    char charTwo[2];

    int modeOne = 0;
    int modeTwo = 0;
    int pos1, pos2 = 0;

    modeOne = atoi(strncpy(charOne, &opCodeString[1], sizeof(char)));
    modeTwo = atoi(strncpy(charTwo, &opCodeString[0], sizeof(char)));

    // pos1 = (modeOne == 0) ? (intCodes[intCodes[pos + 1]]) : (intCodes[pos + 1]);
    // pos2 = (modeTwo == 0) ? (intCodes[intCodes[pos + 2]]) : (intCodes[pos + 2]);
    if (instruction == 1)
    {
        opcode1(pos + 1, modeOne, pos + 2, modeTwo, pos + 3, intCodes);
        // (intCodes[intCodes[pos + 3]] = pos1 + pos2);
    }
    else if (instruction == 2)
    {
        opcode2(pos + 1, modeOne, pos + 2, modeTwo, pos + 3, intCodes);
    }

    // printStuff(__FUNCTION__, pos, instruction, pos1, pos2, intCodes[pos + 3]);
}

int switcher(int pos, int *intCodes)
{
    switch (intCodes[pos])
    {
    case 1:
    {
        opcode1(pos + 1, 0, pos + 2, 0, pos + 3, intCodes);
        // printStuff(__FUNCTION__, pos, 1, intCodes[intCodes[pos + 1]], intCodes[intCodes[pos + 2]], intCodes[intCodes[pos + 3]]);
        pos += 3;
        break;
    }
    case 2:
    {
        opcode2(pos + 1, 0, pos + 2, 0, pos + 3, intCodes);
        // printStuff(__FUNCTION__, pos, 2, intCodes[intCodes[pos + 1]], intCodes[intCodes[pos + 2]], intCodes[intCodes[pos + 3]]);
        pos += 3;
        break;
    }
    case 3:
    {
        opcode3(pos, intCodes);

        // printStuff(__FUNCTION__, pos, 3, intCodes[intCodes[pos + 1]], -1, -1);
        pos += 1;
        break;
    }
    case 4:
    {
        opcode4(intCodes[intCodes[pos + 1]], intCodes);
        // printStuff(__FUNCTION__, pos, 4, intCodes[intCodes[pos + 1]], -1, -1);
        pos += 1;
        break;
    }

    case 99:
    {
        exit(0);
    }
    default:
    {
        parameterMode(pos, intCodes);
        pos += 3;
    }
    }
    return pos;
}