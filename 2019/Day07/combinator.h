//
//  combinator.h
//  Day 7
//
//  Created by Herman, Michael on 1/30/20.
//  Copyright © 2020 Herman, Michael. All rights reserved.
//

#ifndef combinator_h
#define combinator_h

typedef struct comboStruct {
    int results[120][5];
    int resultsCount;
} combo;

#endif /* combinator_h */

combo permutator(int *arr, int length);