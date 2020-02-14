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
    int *ampIntcodes[sizeOfArray*2];//to store the intcodes for each amplifiier use the amplifier number as the index
    
    //create the arrays of intcodes
    for (int i = 0; i < sizeOfArray;i++) {
        ampIntcodes[array[i]] = malloc(sizeof(int) * iCodesSize);
        memcpy(ampIntcodes[array[i]], intCodes,sizeof(int)*iCodesSize);
    }
    
    //loop through amplifier array
    for (int i = 0; i < sizeOfArray;i++) { //loop through amplifiers
        
        int currentAmp = array[i];
        
        tmpInputs.inputSignal = currentAmp;
        tmpInputs.thrustSignal = totalThrust;
        
        
        
        int inputStep = 0;
        
        //Send each amplifier to the computer
        for (int j = 0; j < iCodesSize; j++) { // loop through Intcodes
            intcodes tmpStruct;
            tmpStruct.intCodes=ampIntcodes[currentAmp];
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
        
        if (i == 4) {
            i = -1;
        }
    }
    return totalThrust;
}
