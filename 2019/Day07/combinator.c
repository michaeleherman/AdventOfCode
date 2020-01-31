//
//  combinator.c
//  Day 7
//
//  Created by Herman, Michael on 1/30/20.
//  Copyright © 2020 Herman, Michael. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "combinator.h"


struct combo * permutator(int *arr, int length) {
        
    combo *c_results = malloc(sizeof(combo));
//    int c_results.result[120][5];
    int cSize = 5;
    int c[cSize];
    memset(c, 0, sizeof(c[0]) * cSize);
    int i = 1;
    int k, p;
    int resultsCount = 1;
    memcpy(c_results->results[0], arr, sizeof(int)*cSize);
    
    while (i < length)
    {
        if (c[i] < i)
        {
            if (i % 2 == 0)
            {
                k = i % 2;
            }
            else
            {
                k = c[i];
            }
            p = arr[i];
            arr[i] = arr[k];
            arr[k] = p;
            ++c[i];
            i = 1;
            memcpy(c_results->results[resultsCount], arr, sizeof(int)*cSize);
            resultsCount++;
        } else {
            c[i] = 0;
            ++i;
        }
        
        if (resultsCount == 120) {
            c_results->resultsCount = 120;
            break;
        }
    }
    
    return c_results;
}
