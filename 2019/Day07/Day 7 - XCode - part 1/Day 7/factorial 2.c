//
//  factorial.c
//  Day 7
//
//  Created by Michael Herman on 2/8/20.
//  Copyright © 2020 Herman, Michael. All rights reserved.
//

#include "factorial.h"

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return ( n * factorial(n -1));
}
