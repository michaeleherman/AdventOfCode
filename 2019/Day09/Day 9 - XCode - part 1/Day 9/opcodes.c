#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "switchboard.h"


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

    intCodes[pos + 3] = pos1 + pos2;

    return pos + 4;
}

int opcode2(int pos, int pos1, int pos2, int pos3, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);

    intCodes[pos3] = pos1 * pos2;

    return pos + 4;
}

int opcode3(int input, int pos, int *intCodes)
{
    // printf("In function %s\n", __FUNCTION__);

    intCodes[intCodes[pos + 1]] = input;

    return pos + 2;
}

int opcode4(int pos, int outputPos, int *intCodes)
{

    
    return intCodes[intCodes[pos + 1]];
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

