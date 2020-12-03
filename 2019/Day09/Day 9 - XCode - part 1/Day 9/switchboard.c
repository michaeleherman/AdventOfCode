#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "opcodes.h"
#include "switchboard.h"

typedef int OpCode;
const OpCode ADD = 1;
const OpCode MULTIPLY = 2;
const OpCode INPUT = 3;
const OpCode OUTPUT = 4;
const OpCode JUMP_IF_TRUE = 5;
const OpCode JUMP_IF_FALSE = 6;
const OpCode LESS_THAN = 7;
const OpCode EQUALS = 8;
const OpCode REBASE = 9;
const OpCode END = 99;

typedef int Mode;
const Mode NA = -1;
const Mode POSITION = 0;
const Mode IMMEDIATE = 1;
const Mode RELATIVE = 2;

struct intCodes parameterMode( intCodes dict )
{
    long *pos = &dict.pos;
    long *base = &dict.base;
    long opcodePosition = 0;
    long firstPosition = 0;
    long secondPosition = 0;
    
    
    //get the mode and opcode
    long instruction = dict.intCodes[*pos];
    long opCode = instruction % 100;
    //first instruction is in the hundreds place
    long firstInstruction = (instruction >= 100) ? (instruction/100) % 10: 0;
    //second instruction is in the thousands place, if it exists
    long secondInstruction = (instruction >= 1000) ? instruction/1000 : -1;
    
    if (opCode == ADD || opCode == MULTIPLY || opCode == LESS_THAN || opCode == EQUALS) {
        opcodePosition = dict.intCodes[*pos + 3];
    }
    
    if ( firstInstruction == IMMEDIATE) {
        firstPosition = *pos + 1;
    }
    else if ( firstInstruction == RELATIVE) {
        firstPosition = dict.intCodes[*pos + 1] + *base;
    }
    else {
        firstPosition = dict.intCodes[*pos + 1];
    }
    
    if ( secondInstruction != -1 ) {
        if ( secondInstruction == IMMEDIATE) {
            secondPosition = *pos + 2;
        }
        else if ( secondInstruction == RELATIVE) {
            secondPosition = dict.intCodes[*pos + 2] + *base;
        }
        else {
            secondPosition = dict.intCodes[*pos + 2];
        }
        
    }
    
    
    if ((opCode == ADD || opCode == MULTIPLY || opCode == INPUT) && opcodePosition > dict.sizeOfIntcodes) {
        dict.intCodes = realloc(dict.intCodes, sizeof(long) * (opcodePosition + 1));
        for (long i = dict.sizeOfIntcodes;i<opcodePosition;i++) {
            dict.intCodes[i] = 0;
        }
        dict.sizeOfIntcodes = opcodePosition + 1;
    }
    
    switch (opCode) {
        case ADD:
        {
            dict.intCodes[opcodePosition] = dict.intCodes[firstPosition] + dict.intCodes[secondPosition];
            *pos = *pos + 4;
            break;
        }
        case MULTIPLY:
            dict.intCodes[opcodePosition] = dict.intCodes[firstPosition] * dict.intCodes[secondPosition];
            *pos = *pos + 4;
            break;
        {
            
        }
        case INPUT:
        {
            dict.intCodes[firstPosition] = 1;
            *pos = *pos + 2;
            break;
            
        }
        case OUTPUT:
        {
            printf("%li ", dict.intCodes[opcodePosition]);
            *pos = *pos + 2;
            break;
        }
        case JUMP_IF_TRUE:
        {
            *pos = (dict.intCodes[firstPosition] != 0) ? dict.intCodes[secondPosition] : *pos+3;
            break;
            
        }
        case JUMP_IF_FALSE:
        {
            *pos = (dict.intCodes[firstPosition == 0]) ? dict.intCodes[secondPosition] : *pos+3;
            break;
            
        }
        case LESS_THAN:
        {
            dict.intCodes[opcodePosition] = (dict.intCodes[firstPosition] < dict.intCodes[secondPosition] ) ? 1 : 0;
            *pos = *pos + 4;
            break;
            
        }
        case EQUALS:
        {
            dict.intCodes[opcodePosition] = (dict.intCodes[firstPosition] == dict.intCodes[secondPosition] ) ? 1 : 0;
            *pos = *pos + 4;
            break;
        }
        case REBASE:
        {
            *base = dict.intCodes[firstPosition] + *base;
            *pos = *pos + 2;
            break;
            
        }
        case END:
        {
            printf("Hit the end. Exiting...\n");
            exit(0);
        }
            
        default:
            break;
    }
    
    
    
    
    
    
    
    
    //execute and then return next position
    
    return dict;
}
