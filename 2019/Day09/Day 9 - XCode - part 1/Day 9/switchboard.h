//
//  switchboard.h
//  Day 9
//
//  Created by Michael Herman on 3/13/20.
//  Copyright © 2020 Herman, Michael. All rights reserved.
//

#ifndef switchboard_h
#define switchboard_h

typedef struct intCodes {
    long *intCodes;
    long sizeOfIntcodes;
    long base;
    long pos;
} intCodes;


#endif /* switchboard_h */

struct intCodes parameterMode( intCodes dict );
