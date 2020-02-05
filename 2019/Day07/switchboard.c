#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "switchboard.h"
#include "opcodes.h"
#include "inputparser.h"

int parameterMode(int pos, int *intCodes, int inputValue)
{
    
    int opcode3Input;
    
    if (intCodes[pos] == 3) {
        opcode3Input = inputValue;
    }
    
    // printf("In function %s\n", __FUNCTION__);
    int currOpcode = intCodes[pos];
    int opcodeLength = sizeof(currOpcode);
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
        pos = opcode3(opcode3Input, pos, intCodes);
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
