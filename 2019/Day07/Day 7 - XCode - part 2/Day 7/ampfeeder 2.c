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
    int inputCounter = 0;
    inputs tmpInputs;
//    int *ampIntcodes[sizeOfArray*2];//to store the intcodes for each amplifiier use the amplifier number as the index
    struct s_arrs ampIntcodes[sizeOfArray*2];
    
    //create the arrays of intcodes
    for (int i = 0; i < sizeOfArray;i++) {
        ampIntcodes[array[i]].intCodes = malloc(sizeof(int) * iCodesSize);
        ampIntcodes[array[i]].startPos = 0;
        memcpy(ampIntcodes[array[i]].intCodes, intCodes,sizeof(int)*iCodesSize);
    }
    
    tmpInputs.inputSignal = array[0];
    tmpInputs.thrustSignal = 0;
    for (int n = 0;n<sizeOfArray;n++) {
        intcodes tmpCodes;
        tmpCodes.intCodes = ampIntcodes[array[n]].intCodes;
        tmpCodes.iCodesSize = iCodesSize;
        
        for (int i = 0;i<iCodesSize;i++){
            
            tmpCodes.pos = i;
            
            if (intCodes[i] == 3 && inputCounter < 2) {
                if (inputCounter == 0) {
                    tmpCodes.inputValue = tmpInputs.inputSignal;
                    inputCounter++;
                } else if (inputCounter == 1) {
                    tmpCodes.inputValue = tmpInputs.thrustSignal;
                    inputCounter++;
                }
            }
            
            if (intCodes[i] == 4) {
                totalThrust = parameterMode(tmpCodes);
                i++;
                tmpInputs.thrustSignal = totalThrust;
                inputCounter--;
                break;
            }
            
            if (intCodes[i] == 99) {
                return totalThrust;
            }
            
            i = parameterMode(tmpCodes)-1;
        }
    }
    
    
    
    
    
    return 0;
}
