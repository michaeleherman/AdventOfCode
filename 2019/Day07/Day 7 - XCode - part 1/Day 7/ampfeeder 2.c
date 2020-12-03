//
//  ampfeeder.c
//  Day 7
//
//  Created by Herman, Michael on 1/31/20.
//  Copyright © 2020 Herman, Michael. All rights reserved.
//

#include "ampfeeder.h"
#include "switchboard.h"
#include "opcodes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int processArray(int *array, int sizeOfArray, int *intCodes, int iCodesSize){
    
    int totalThrust = 0;
    inputs tmpInputs;
    
    //loop through amplifier array
    for (int i = 0; i < sizeOfArray;i++) { //loop through amplifiers
        
        tmpInputs.inputSignal = array[i];
        tmpInputs.thrustSignal = totalThrust;
        
        int inputStep = 0;
        
        //Send each amplifier to the computer
        for (int j = 0; j < iCodesSize; j++) { // loop through Intcodes
            intcodes tmpStruct;
            tmpStruct.intCodes=malloc(sizeof(int)*iCodesSize);
            memcpy(tmpStruct.intCodes,intCodes,sizeof(int)*iCodesSize);
            tmpStruct.intCodes = intCodes;
            tmpStruct.pos = j;
            if (intCodes[j] == 3) {
                if (inputStep == 0) {
                    tmpStruct.inputValue = tmpInputs.inputSignal;
                    inputStep++;
                } else {
                    tmpStruct.inputValue = tmpInputs.thrustSignal;
                }
            } else if (intCodes[j] == 4) {
                tmpStruct.inputValue = -1;
                totalThrust = parameterMode(tmpStruct);
                break;
            }
            else {
                tmpStruct.inputValue = -1;
            }
            
            j = parameterMode(tmpStruct)-1;
            
        }
    }
    return totalThrust;
}
