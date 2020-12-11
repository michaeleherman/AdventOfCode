#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



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

typedef enum { False, True } boolean;

void getField(char *chunk,struct passport *currentPassport);
char searchArray(struct passport *currentPassport,int *valid, int *recordCount) ;


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
    struct passport currentPassport = {0};

    // memset(&currentPassport[0], 0, sizeof(currentPassport));
    int recordCount = 0;
    boolean complete;

    while (fgets(chunk, sizeof(chunk), fp) != NULL){
            printf("%s",chunk);
            if (chunk[0] == '\n') {
                recordCount++;
                if (currentPassport.fieldCount == 7) {
                    complete = searchArray(&currentPassport, &valid, &recordCount);
                    // if ( complete == "t") {
                    //     valid++;
                    // }
                } else if (currentPassport.fieldCount == 8) {
                    complete = True;
                    // valid++;
                    printf("Record %d is valid\n\n",recordCount);
                } else {
                    printf ("Record %d is invalid\n\n",recordCount);
                    complete = False;
                }
                    memset(&currentPassport, 0, sizeof(passport));
            } else
            {
                chunk[strlen(chunk)-1] = '\0';
                // int characterCount = charCount(chunk);
                // printf("character count is %d\n",characterCount);
                char *savePtr;
                char *token = strtok_r(chunk, " ",&savePtr);

                while ( token != NULL) {
                    getField(token, &currentPassport);
                    // currentPassport[fieldCounter] = field;
                    currentPassport.fieldCount++;
                    token = strtok_r(NULL, " ",&savePtr);
                }
            }
        
            
            
        }

}

void getField(char *field, struct passport *currentPassport) {
    char *fieldValue;
    char *fieldToken = strtok_r(field,":",&fieldValue);
//    while ( fieldToken != NULL) {
        char *fieldKey = fieldToken;
        fieldToken = strtok_r(NULL, ":",&fieldValue);
        if (strcmp(fieldKey,"byr") == 0) {
            currentPassport->byr = fieldToken;
        }
        if (strcmp(fieldKey,"iyr") == 0) {
            currentPassport->iyr = fieldToken;
        }
        if (strcmp(fieldKey,"eyr") == 0) {
            currentPassport->eyr = fieldToken;
        }
        if (strcmp(fieldKey,"hgt") == 0) {
            currentPassport->hgt = fieldToken;
        }
        if (strcmp(fieldKey,"hcl") == 0) {
            currentPassport->hcl = fieldToken;
        }
        if (strcmp(fieldKey,"ecl") == 0) {
            currentPassport->ecl = fieldToken;
        }
        if (strcmp(fieldKey,"pid") == 0) {
            currentPassport->pid = fieldToken;
        }
        if (strcmp(fieldKey,"cid") == 0) {
            currentPassport->cid = fieldToken;
        }
//    }
    
}

char searchArray(struct passport *currentPassport,int *valid, int *recordCount) {
    for (int i = 0; i<currentPassport->fieldCount;i++) {
        if (passport.cid == NULL) {
            printf("Record %d is invalid\n\n",*recordCount);
            return False;
        }
    }
    printf("Record %d is valid\n\n",*recordCount);

    return True;
    // (*valid)++;
}

void checkParams(char *param, char *value) {


}
