#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "switchboard.h"
#include "opcodes.h"
#include "inputparser.h"

typedef int OpCode;
const OpCode ADD = 1;
const OpCode MULTIPLY = 2;
const OpCode INPUT = 3;
const OpCode OUTPUT = 4;
const OpCode JUMP_IF_TRUE = 5;
const OpCode JUMP_IF_FALSE = 6;
const OpCode LESS_THAN = 7;
const OpCode EQUALS = 8;
const OpCode END = 99;

int parameterMode(int i, int *intCodes, int inputValue, int iCodesSize)
{

    int pos = i;
    int opcode3Input = 0;

    
    if (intCodes[pos] == INPUT) {
        opcode3Input = inputValue;
    }
    
    // printf("In function %s\n", __FUNCTION__);
    int currOpcode = intCodes[pos];
    char opCodeString[5] = {'\0'};

    sprintf(opCodeString, "%04d", currOpcode);

    // char *opCodeString = itoa(currOpcode);
    int instruction = currOpcode % 100;

    char charOne[2];
    char charTwo[2];
    int pos1=0, pos2 = 0, pos3 = 0;

    int modeOne = 0;
    modeOne = atoi(strncpy(charOne, &opCodeString[1], sizeof(char)));
    pos1 = (modeOne == 0) ? (intCodes[intCodes[pos + 1]]) : (intCodes[pos + 1]);

    if (instruction != INPUT && instruction != OUTPUT && instruction != END)
    {

        int modeTwo = 0;
        modeTwo = atoi(strncpy(charTwo, &opCodeString[0], sizeof(char)));
        pos2 = (modeTwo == 0) ? (intCodes[intCodes[pos + 2]]) : (intCodes[pos + 2]);
    }

    switch (instruction)
    {

    case ADD:
    {
        pos3 = intCodes[pos + 3];
        pos = opcode1(pos, pos1, pos2, pos3, intCodes);
        break;
    }
    case MULTIPLY:
    {
        pos3 = intCodes[pos + 3];
        pos = opcode2(pos, pos1, pos2, pos3, intCodes);
        break;
    }
    case INPUT:
    {
        pos = opcode3(opcode3Input, pos, intCodes);
        break;
    }
    case OUTPUT:
    {
        int output;
        output = opcode4(pos, pos1, intCodes);
        return output;
        break;
    }
    case JUMP_IF_TRUE:
    {
        pos = opcode5(pos, pos1, pos2, intCodes);
        break;
    }
    case JUMP_IF_FALSE:
    {
        pos = opcode6(pos, pos1, pos2, intCodes);
        break;
    }
    case LESS_THAN:
    {
        pos3 = intCodes[pos + 3];
        pos = opcode7(pos, pos1, pos2, pos3, intCodes);
        break;
    }
    case EQUALS:
    {
        pos3 = intCodes[pos + 3];
        pos = opcode8(pos, pos1, pos2, pos3, intCodes);
        break;
    }
    }

    
    return pos;
}
