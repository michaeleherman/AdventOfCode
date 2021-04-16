#include "part2.h"

extern struct ticketField fields[ARRAYSIZE];

int main(void){
    int validEnd = part1();
    printf("valid end is %d\n",validEnd);

    int valid;
    for (int i = 0; i < FIELDS_COUNT; i++) {
        for (int j = 0; j < validEnd; j++) {
            valid = checkFields(validTix[j][i]);
            if ( valid == FALSE ) {
                printf("invalid field is %s\n",fields[j].fieldName);
            }
        }
    }


    return 0;
    
}

int checkFields(int value) {
    enum state valid;
    for (int i = 0; i < 20; i++) {
        if ((value >= fields[i].start1 && value <= fields[i].end1) || (value >= fields[i].start2 && value <= fields[i].end2)) {
            valid = TRUE;
        } else {
            valid = FALSE;
            break;
        }
    }
    return valid;
}