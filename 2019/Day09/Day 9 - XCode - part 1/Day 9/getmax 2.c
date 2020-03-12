//
//  getmax.c
//  Day 7
//
//  Created by Michael Herman on 2/8/20.
//  Copyright © 2020 Herman, Michael. All rights reserved.
//

#include "getmax.h"

int getMax(int *thrustArray, int sizeOfArray) {
    int maxThrust = thrustArray[0];
    
    for (int i = 0; i<sizeOfArray-1;i++) {
        if (maxThrust < thrustArray[i+1]) {
            maxThrust = thrustArray[i+1];
        }
    }
    
    return maxThrust;
}
