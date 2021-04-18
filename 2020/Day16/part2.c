#include "part2.h"

extern _field fields[ARRAYSIZE];

int main(void){
    int validEnd = part1();
    printf("valid end is %d\n",validEnd);

    int valid;
    int f, i, j;
    for (f = 0; f < fieldsEnd; ++f) {
        printf("Starting field %s\n",fields[f].fieldName);
        for (i = 0; i < FIELDS_COUNT; ++i) {
            for (j = 0; j < validEnd; ++j) {
                valid = checkFields(f, validTix[j][i]);
                if ( valid == FALSE ) {
                    printf("row %d position %d is invalid for %s\n",j,i,fields[f].fieldName);
                    break;
                } 
            }
            if ( valid == TRUE) {
                printf("row %d position %d is valid for %s \n",j,i, fields[f].fieldName);
                fields[i].position = i;
            }
            if (valid == FALSE) {
                break;
            }
        }
    }


    return 0;
    
}

int checkFields(int f, int value) {
    enum state valid = FALSE;
    for (int i = 0; i < fieldsEnd; i++) {
        if ((value >= fields[f].start1 && value <= fields[f].end1) || (value >= fields[f].start2 && value <= fields[f].end2)) {
            valid = TRUE;
        } else {
            valid = FALSE;
            break;
        }
    }
    return valid;
}
