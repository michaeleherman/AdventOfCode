#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


typedef enum { False, True } boolean;

void getField(char *chunk,int *validFieldCount);
boolean checkDates (char *field, int start, int end) 


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
                    getField(token, &validFieldCount);            
                    token = strtok_r(NULL, " ",&savePtr);
                }
            }
        
            
            
        }

}

void getField(char *field, int *validFieldCount) {
    char *fieldValue;
    char *fieldToken = strtok_r(field,":",&fieldValue);
//    while ( fieldToken != NULL) {
        char *fieldKey = fieldToken;
        fieldToken = strtok_r(NULL, ":",&fieldValue);
        if (strcmp(fieldKey,"byr") == 0) {
            int startYear = 1920;
            int endYear = 2002;
            if (checkDates(fieldToken, startYear, endYear) == True) {
                validFieldCount++;
            }
            return;
        }
        if (strcmp(fieldKey,"iyr") == 0) {
            int startYear = 2010;
            int endYear = 2020;
            if (checkDates(fieldToken, startYear, endYear) == True) {
                validFieldCount++;
            }
            return;
        }
        if (strcmp(fieldKey,"eyr") == 0) {
            int startYear = 2020;
            int endYear = 2030;
            if (checkDates(fieldToken, startYear, endYear) == True) {
                validFieldCount++;
            }
            return;
        }
        if (strcmp(fieldKey,"hgt") == 0) {
            char units[2] = fieldToken[strlen(fieldToken) -2];

        }
        if (strcmp(fieldKey,"hcl") == 0) {
            
            return;
        }
        if (strcmp(fieldKey,"ecl") == 0) {

            return;
        }
        if (strcmp(fieldKey,"pid") == 0) {
            
            return;
        }
        if (strcmp(fieldKey,"cid") == 0) {

            return;
//    }
    
}

boolean checkDates (char *field, int start, int end) {
    long startYear = strotol(start, 10);
    long endYear = strtol(end, 10);
    long fieldValue = strtol(field, 10);
    if (fieldValue >= startYear && fieldValue <= endYear) {
        return True;
    }
}