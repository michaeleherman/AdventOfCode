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


int ampInput(int *phaseSettings, int pSSize, int *intCodes, int iCodesSize){
    int totalThrust = 0;
    
    //send first phase setting and inputSignal to switchboard
    //switchboard should return the thrust output
    // thrustInput = (switchboard(a, b)
    //send next phase setting and thrustinput to switchboard
    //loop it
    //return final thrust input back to main
    
    for (int i = 0; i < pSSize;i++) { //loop through amplifiers
        
        inputs tmpInputs;
        tmpInputs.inputSignal = 0;
        tmpInputs.thrustSignal = 0;
        int inputStep = 0;
        
        for (int j = 0; j < iCodesSize; j++) { // loop through Intcodes
            intcodes tmpStruct;
            tmpStruct.intCodes = intCodes;
            tmpStruct.pos = intCodes[j];
            if (intCodes[j] == 3) {
                if (inputStep == 0) {
                    tmpStruct.inputValue = tmpInputs.inputSignal;
                    inputStep++;
                } else {
                    tmpStruct.inputValue = tmpInputs.thrustSignal;
                }
            }
                
//                totalThrust += parameterMode(tmpStruct);
            
            }
        }
    return 0;
        
}
