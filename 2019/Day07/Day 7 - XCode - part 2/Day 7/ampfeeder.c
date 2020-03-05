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
    
//    array[0] = 9;
//    array[1] = 8;
//    array[2] = 7;
//    array[3] = 6;
//    array[4] = 5;
    int thrust = 0;
    int inputCounter = 0;
    int thrustSignal = 0;
    int counter = 0;
    //    inputs tmpInputs;
    //    int *ampIntcodes[sizeOfArray*2];//to store the intcodes for each amplifiier use the amplifier number as the index
    struct s_arrs ampIntcodes[sizeOfArray*2];
    
    //create the arrays of intcodes
    for (int i = 0; i < sizeOfArray;i++) {
        ampIntcodes[array[i]].intCodes = malloc(sizeof(int) * iCodesSize);
        ampIntcodes[array[i]].startPos = 0;
        ampIntcodes[array[i]].ranOnce = 0;
        memcpy(ampIntcodes[array[i]].intCodes, intCodes,sizeof(int)*iCodesSize);
    }
    
    
    //    tmpInputs.thrustSignal = 0;
    
    int inputValue = 0;
    int n = 0;
    
    while ( n < 6 ) {
         
        int *ranOnce = &ampIntcodes[array[n]].ranOnce;
        //        tmpCodes.intCodes = ampIntcodes[array[n]].intCodes;
        //        tmpCodes.iCodesSize = iCodesSize;
        int *intCodes = ampIntcodes[array[n]].intCodes;
        int *i = &ampIntcodes[array[n]].startPos;
        
        if (*ranOnce == 0) {
            inputCounter = 0;
        }
        
        while (intCodes[*i] != 100){
            
            if (intCodes[*i] == 3) {
                if (inputCounter == 0 && *ranOnce == 0) {
                    inputValue = array[n];
                    inputCounter++;
                    *ranOnce += 1;
                } else {
                    inputValue = thrustSignal;
                }
            }
            
            if (intCodes[*i] == 4) {
                thrust = parameterMode(*i, intCodes, inputValue, iCodesSize );
                *i += 2;
                thrustSignal = thrust;
                ampIntcodes[array[n]].startPos = *i;
                n = (n + 1) % sizeOfArray;
                counter++;
                break;
                
            }
            
            if (intCodes[*i] == 99) {
                return thrustSignal;
            }
            
            *i = parameterMode(*i, intCodes, inputValue, iCodesSize);
        }
    }
    
    
    
    
    
    return 0;
}
