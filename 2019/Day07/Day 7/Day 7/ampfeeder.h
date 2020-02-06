//
//  ampfeeder.h
//  Day 7
//
//  Created by Herman, Michael on 1/31/20.
//  Copyright © 2020 Herman, Michael. All rights reserved.
//

#ifndef ampfeeder_h
#define ampfeeder_h

#include <stdio.h>

typedef struct inputs {
    int inputSignal;
    int thrustSignal;
} inputs;

typedef struct intcodes {
    int pos;
    int *intCodes;
    int inputValue;
} intcodes;



#endif /* ampfeeder_h */

int ampInput(int phaseSettings[120][5], int pSSize, int *intCodes, int iCodesSize);
