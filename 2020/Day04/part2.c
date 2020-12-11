#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef enum { False, True } boolean;

void getField(char *chunk,int *validFieldCount, boolean *cidExists);
boolean checkDates (char *field, int start, int end);


int main(void){

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day04/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    // char *codes[8]= {
    //     "byr","iyr","eyr","hgt","hcl","ecl","pid","cid"
    // };

    char chunk[256];
    int valid = 0;
    int validFieldCount = 0;
    boolean cidExists = False;

    // memset(&currentPassport[0], 0, sizeof(currentPassport));
    int recordCount = 0;
    boolean complete;

    while (fgets(chunk, sizeof(chunk), fp) != NULL){
            printf("%s",chunk);
            if (chunk[0] == '\n') {
                recordCount++;
                if (validFieldCount == 7 && cidExists == False) {
                    complete = True;
                    valid++;
                } else if (validFieldCount == 8) {
                    complete = True;
                    valid++;
                    printf("Record %d is valid\n\n",recordCount);
                } else {
                    printf ("Record %d is invalid\n\n",recordCount);
                    complete = False;
                }
            } else
            {
                chunk[strlen(chunk)-1] = '\0';
                // int characterCount = charCount(chunk);
                // printf("character count is %d\n",characterCount);
                char *savePtr;
                char *token = strtok_r(chunk, " ",&savePtr);

                while ( token != NULL) {
                    getField(token, &validFieldCount, &cidExists);
                    token = strtok_r(NULL, " ",&savePtr);
                }
            }
        
            
            
        }

}

void getField(char *field, int *validFieldCount, boolean *cidExists) {
    char *fieldValue;
    char *fieldToken = strtok_r(field,":",&fieldValue);
//    while ( fieldToken != NULL) {
        char *fieldKey = fieldToken;
        fieldToken = strtok_r(NULL, ":",&fieldValue);
        if (strcmp(fieldKey,"byr") == 0) {
            int startYear = 1920;
            int endYear = 2002;
            if (checkDates(fieldToken, startYear, endYear) == True) {
                *validFieldCount = *validFieldCount + 1;
            }
            return;
        }
        if (strcmp(fieldKey,"iyr") == 0) {
            int startYear = 2010;
            int endYear = 2020;
            if (checkDates(fieldToken, startYear, endYear) == True) {
                *validFieldCount = *validFieldCount + 1;
            }
            return;
        }
        if (strcmp(fieldKey,"eyr") == 0) {
            int startYear = 2020;
            int endYear = 2030;
            if (checkDates(fieldToken, startYear, endYear) == True) {
                *validFieldCount = *validFieldCount + 1;
            }
            return;
        }
        if (strcmp(fieldKey,"hgt") == 0) {
            char units[3] = {0};
            char heightString[20];
            char *eptr;
            unsigned long heightLength = strlen(fieldToken) -2;
            strncpy(heightString, fieldToken, heightLength);
            heightString[heightLength] = '\0';
            long height = strtol(heightString, &eptr, 10);
            strncpy(units,&fieldToken[strlen(fieldToken) - 2],2);
            if (strcmp(units,"cm") == 0){
                if (height >= 150 && height <= 193) {
                    *validFieldCount = *validFieldCount + 1;
                }
            } else if (strcmp(units,"in") == 0) {
                if (height >= 59 && height <= 76) {
                    *validFieldCount = *validFieldCount + 1;
                }
            }
            return;

        }
        if (strcmp(fieldKey,"hcl") == 0) {
            if (fieldToken[0] == '#' && strlen(fieldToken) == 7) {
                for (int i = 1; i < 7; i++) {
                    if ((fieldToken[i] < '0' && fieldToken[i] > '9') || (fieldToken[i] < 'a' && fieldToken[i] > 'f') ) {
                        return;
                    }
                }
                *validFieldCount = *validFieldCount + 1;
            }
            return;
        }
        if (strcmp(fieldKey,"ecl") == 0) {
            char *eyeColors[7] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
            for (int i = 0; i < 7; i++) {
                if (strcmp(fieldToken,eyeColors[i]) == 0) {
                    *validFieldCount = *validFieldCount + 1;
                    break;;
                }
            }
            return;
        }
        if (strcmp(fieldKey,"pid") == 0) {
            if (strlen(fieldToken) == 9) {
                for (int i = 0; i < 9; i++)
                    if(fieldToken[i] < '0' && fieldToken[i] > '9' ) {
                        return;
                    }
                    *validFieldCount = *validFieldCount + 1;                   
            }
            return;
        }
        if (strcmp(fieldKey,"cid") == 0) {
            *validFieldCount = *validFieldCount + 1;        
            *cidExists = True;
            return;
        }
}

boolean checkDates (char *field, int start, int end) {
    char *tmpValue;
    long fieldValue = strtol(field, &tmpValue, 10);
    if (fieldValue >= start && fieldValue <= end) {
        return True;
    }
    return False;
}
