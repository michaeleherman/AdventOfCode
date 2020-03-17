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
    long val1 = 0;
    long val2 = 0;
    long storePosition = 0;
    long readPosition = 0;
    
    
    //get the mode and opcode
    long instruction = dict.intCodes[*pos];
    long opCode = instruction % 100;
    //first instruction is in the hundreds place
    long firstInstruction = (instruction >= 100) ? (instruction/100) % 10: 0;
    //second instruction is in the thousands place, if it exists
    long secondInstruction = (instruction >= 1000) ? instruction/1000 : -1;
    
    
    if (opCode == INPUT){
        storePosition = dict.intCodes[*pos + 1];
    }
    else if ( opCode == OUTPUT && firstInstruction == IMMEDIATE) {
        readPosition = *pos + 1;
    }
        else if ( opCode == OUTPUT && firstInstruction != IMMEDIATE) {
            readPosition = dict.intCodes[*pos + 1];
        }
     else if ( opCode == REBASE ) {
        storePosition = 0;
    } else {
        storePosition = dict.intCodes[*pos + 3];
    }
    
    if (storePosition > dict.sizeOfIntcodes) {
        dict.intCodes = realloc(dict.intCodes, sizeof(long) * (storePosition + 1));
        for (long i = dict.sizeOfIntcodes;i<storePosition;i++) {
            dict.intCodes[i] = 0;
        }
        dict.sizeOfIntcodes = storePosition;
    }
    
    if ( firstInstruction == IMMEDIATE ) {
        val1 = dict.intCodes[*pos + 1];
    } else if ( firstInstruction == RELATIVE ) {
        readPosition = dict.intCodes[*pos + 1] + *base;
    } else {
        val1 = dict.intCodes[dict.intCodes[*pos +1]];
    }
    
    if ( secondInstruction == IMMEDIATE ) {
        val2 = dict.intCodes[*pos + 2];
    } else if ( secondInstruction == RELATIVE ) {
        val2 = dict.intCodes[dict.intCodes[*pos +2]] + *base;
    }
    else if ( secondInstruction != NA ){
        val2 = dict.intCodes[dict.intCodes[*pos + 2]];
    }
    
    switch (opCode) {
        case ADD:
        {
            dict.intCodes[storePosition] = val1 + val2;
            *pos = *pos + 4;
            break;
        }
        case MULTIPLY:
            dict.intCodes[storePosition] = val1 * val2;
            *pos = *pos + 4;
            break;
        {
            
        }
        case INPUT:
        {
            dict.intCodes[*pos + *base] = 1;
            break;
            
        }
        case OUTPUT:
        {
            printf("%li ", dict.intCodes[readPosition]);
            *pos = *pos + 2;
            break;
        }
        case JUMP_IF_TRUE:
        {
            *pos = (val1 != 0) ? dict.intCodes[dict.intCodes[*pos + 1]] : *pos+3;
            break;
            
        }
        case JUMP_IF_FALSE:
        {
            *pos = (val1 == 0) ? dict.intCodes[dict.intCodes[*pos + 2]] : *pos+3;
            break;
            
        }
        case LESS_THAN:
        {
            dict.intCodes[storePosition] = (val1 < val2 ) ? 1 : 0;
            *pos = *pos + 4;
            break;
            
        }
        case EQUALS:
        {
            dict.intCodes[storePosition] = (val1 == val2 ) ? 1 : 0;
            *pos = *pos + 4;
            break;
        }
        case REBASE:
        {
            *base = *base + dict.intCodes[readPosition];
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
