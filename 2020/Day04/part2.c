#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "valuecheck.h"


struct passport {
    int fieldCount;
    char *byr;
    char *iyr;
    char *eyr;
    char *hgt;
    char *hcl;
    char *ecl;
    char *pid;
    char *cid;
} passport;



void getField(char *chunk,struct passport *currentPassport,int fieldCount);
char searchArray(struct passport *currentPassport,int *valid, int fieldCount, int *recordCount) ;


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
    int fieldCount = 0;
    struct passport currentPassport;
    // memset(&currentPassport[0], 0, sizeof(currentPassport));
    int recordCount = 0;
    char complete;

    while (fgets(chunk, sizeof(chunk), fp) != NULL){
            printf("%s",chunk);
            if (chunk[0] == '\n') {
                recordCount++;
                if (fieldCount == 7) {
                     complete = searchArray(&currentPassport, &valid, fieldCount, &recordCount);
                    // if ( complete == "t") {
                    //     valid++;
                    // }
                } else if (fieldCount == 8) {
                    complete = "t";
                    // valid++;
                    printf("Record %d is valid\n\n",recordCount);
                } else {
                    printf ("Record %d is invalid\n\n",recordCount);
                }
                
                fieldCount = 0;
            } else
            {
                // int characterCount = charCount(chunk);
                // printf("character count is %d\n",characterCount);
                char *savePtr;
                char *token = strtok_r(chunk, " ",&savePtr);

                while ( token != NULL) {
                    getField(token, &currentPassport,fieldCount);
                    // currentPassport[fieldCounter] = field;
                    currentPassport.fieldCount++;
                    token = strtok_r(NULL, " ",&savePtr);
                }
            }
            
        }

}

void getField(char *field, struct passport *currentPassport, int fieldCount) {
    char *localSave;
    char *fieldToken = strtok_r(field,":",&localSave);
    while ( fieldToken != NULL) {
        char *field = fieldToken;
        fieldToken = strtok_r(NULL, ":",&localSave);
        if (strcmp(field,"byr")) {
            passport.byr = fieldToken;
        }
        if (strcmp(field,"iyr")) {
            passport.iyr = fieldToken;
        }
        if (strcmp(field,"eyr")) {
            passport.eyr = fieldToken;
        }
        if (strcmp(field,"hgt")) {
            passport.hgt = fieldToken;
        }
        if (strcmp(field,"hcl")) {
            passport.hcl = fieldToken;
        }
        if (strcmp(field,"ecl")) {
            passport.ecl = fieldToken;
        }
        if (strcmp(field,"pid")) {
            passport.pid = fieldToken;
        }
        if (strcmp(field,"cid")) {
            passport.cid = fieldToken;
        }


    }

}

char searchArray(struct passport *currentPassport,int *valid, int fieldCount, int *recordCount) {
    for (int i = 0; i<fieldCount;i++) {
        if (strcmp(passport[i],"cid") == 0) {
            printf("Record %d is invalid\n\n",*recordCount);
            return "f";
        }
    }
    printf("Record %d is valid\n\n",*recordCount);
    return "t";
    // (*valid)++;
}

void checkParams(char *param, char *value) {


}