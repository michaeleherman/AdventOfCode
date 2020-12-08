#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int charCount(char *chunk);
void getField(char *chunk,char *passport[8],int fieldCount);


int main(void){

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day04/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    char *codes[8]= {
        "byr","iyr","eyr","hgt","hcl","ecl","pid","cid"
    };

    char chunk[256];
    int fieldCount = 0;
    char *currentPassport[8];
    memset(&currentPassport[0], 0, sizeof(currentPassport));

    while (fgets(chunk, sizeof(chunk), fp) != NULL){
            if (chunk[0] == '\n') {
                fieldCount = 0;
                memset(&currentPassport[0], 0, sizeof(currentPassport));
                fieldCount = 0;
                printf("Empty line\n\n");
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
                    printf("chunk token %s",token);
                    token = strtok_r(NULL, " ",&savePtr);
                }
            }
            
        }

   
       
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
    // memcpy(&passport[fieldCount],fieldToken,strlen(fieldToken));
    passport[fieldCount] = strdup(fieldToken);
//    strcpy(passport[fieldCount],fieldToken);

    // passport[fieldCount] = *fieldToken;

}
