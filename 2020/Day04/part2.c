#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int charCount(char *chunk);
void getField(char *chunk,char *passport[8],int fieldCount);
void searchArray(char *passport[8],int *valid, int fieldCount, int *recordCount) ;

struct passports {
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
    char *currentPassport[8];
    memset(&currentPassport[0], 0, sizeof(currentPassport));
    int recordCount = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL){
            printf("%s",chunk);
            if (chunk[0] == '\n') {
                recordCount++;
                if (fieldCount == 7) {
                    searchArray(currentPassport, &valid, fieldCount, &recordCount);
                } else if (fieldCount == 8) {
                    valid++;
                    printf("Record %d is valid\n\n",recordCount);
                } else {
                    printf ("Record %d is invalid\n\n",recordCount);
                }
                
                fieldCount = 0;
                memset(&currentPassport[0], 0, sizeof(currentPassport));
                fieldCount = 0;
            } else
            {
                // int characterCount = charCount(chunk);
                // printf("character count is %d\n",characterCount);
                char *savePtr;
                char *token = strtok_r(chunk, " ",&savePtr);

                while ( token != NULL) {
                    getField(token, currentPassport,fieldCount);
                    // currentPassport[fieldCounter] = field;
                    fieldCount++;
                    token = strtok_r(NULL, " ",&savePtr);
                }
            }
            
        }

    printf("Valid passports: %d\n", valid);
       
    return 0;

    }

int charCount(char *chunk) {
    int characterCount = 0;
    for (int i = 0;i<strlen(chunk);i++) {
        if (chunk[i] == '\0') {
            break;
        }
        characterCount++;
    }

    return characterCount;

}

void getField(char *field, char *passport[8], int fieldCount) {
    char *localSave;
    char *fieldToken = strtok_r(field,":",&localSave);
    passport[fieldCount] = strdup(fieldToken);

}

void searchArray(char *passport[8],int *valid, int fieldCount, int *recordCount) {
    for (int i = 0; i<fieldCount;i++) {
        if (strcmp(passport[i],"cid") == 0) {
            printf("Record %d is invalid\n\n",*recordCount);
            return;
        }
    }
    printf("Record %d is valid\n\n",*recordCount);
    (*valid)++;
}

void checkParams(char *param, char *value) {


}