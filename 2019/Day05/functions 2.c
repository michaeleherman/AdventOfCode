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

int opcode1(int pos, int pos1, int pos2, int pos3, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);

    intCodes[pos3] = pos1 + pos2;

    return pos + 4;
}

int opcode2(int pos, int pos1, int pos2, int pos3, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);

    intCodes[pos3] = pos1 * pos2;

    return pos + 4;
}

int opcode3(int pos, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);
    int systemId;
    printf("Please enter the system ID: ");
    scanf("%d", &systemId);
    intCodes[intCodes[pos + 1]] = systemId;

    return pos + 2;
}

int opcode4(int pos, int outputPos, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);
    printf("Output is: %d\n", outputPos);
    exit(0);
    return pos + 2;
}

//Jump if true
int opcode5(int pos, int pos1, int pos2, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);
    if (pos1 != 0)
    {
        pos = pos2;
    }
    else
    {
        pos += 3;
    }

    return pos;
}

//Jump if false
int opcode6(int pos, int pos1, int pos2, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);
    if (pos1 == 0)
    {
        pos = pos2;
    }
    else
    {
        pos += 3;
    }

    return pos;
}

//less than
int opcode7(int pos, int pos1, int pos2, int pos3, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);

    intCodes[pos3] = (pos1 < pos2) ? 1 : 0;
    return pos + 4;
}

//equals
int opcode8(int pos, int pos1, int pos2, int pos3, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);
    intCodes[pos3] = (pos1 == pos2) ? 1 : 0;
    return pos + 4;
}

int parameterMode(int pos, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);
    int currOpcode = intCodes[pos];
    int opcodeLength = sizeof(currOpcode);
    char opCodeString[5] = {'\0'};

    sprintf(opCodeString, "%04d", currOpcode);

    // char *opCodeString = itoa(currOpcode);
    int instruction = currOpcode % 100;

    char charOne[2];
    char charTwo[2];
    int pos1, pos2, pos3 = 0;

    int modeOne = 0;
    modeOne = atoi(strncpy(charOne, &opCodeString[1], sizeof(char)));
    pos1 = (modeOne == 0) ? (intCodes[intCodes[pos + 1]]) : (intCodes[pos + 1]);

    if (instruction != 3 && instruction != 4 && instruction != 99)
    {

        int modeTwo = 0;
        modeTwo = atoi(strncpy(charTwo, &opCodeString[0], sizeof(char)));
        pos2 = (modeTwo == 0) ? (intCodes[intCodes[pos + 2]]) : (intCodes[pos + 2]);
    }

    switch (instruction)
    {

    case 1:
    {
        pos3 = intCodes[pos + 3];
        pos = opcode1(pos, pos1, pos2, pos3, intCodes);
        break;
    }
    case 2:
    {
        pos3 = intCodes[pos + 3];
        pos = opcode2(pos, pos1, pos2, pos3, intCodes);
        break;
    }
    case 3:
    {
        pos = opcode3(pos, intCodes);
        break;
    }
    case 4:
    {

        pos = opcode4(pos, pos1, intCodes);
        break;
    }
    case 5:
    {
        pos = opcode5(pos, pos1, pos2, intCodes);
        break;
    }
    case 6:
    {
        pos = opcode6(pos, pos1, pos2, intCodes);
        break;
    }
    case 7:
    {
        pos3 = intCodes[pos + 3];
        pos = opcode7(pos, pos1, pos2, pos3, intCodes);
        break;
    }
    case 8:
    {
        pos3 = intCodes[pos + 3];
        pos = opcode8(pos, pos1, pos2, pos3, intCodes);
        break;
    }
    }
    return pos;
}