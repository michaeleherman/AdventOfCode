#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int charCount(char *chunk);
char *getField(char *chunk);


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
    int fieldCounter = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL){    
            char *currentPassport = malloc(sizeof(char) * 3);
            if (chunk[0] == '\n') {
                fieldCounter = 0;
                printf("Empty line\n\n");
            } else
            {
                // int characterCount = charCount(chunk);
                // printf("character count is %d\n",characterCount);
                char *savePtr;
                char *token = strtok_r(chunk, " ",&savePtr);

                while ( token != NULL) {
                    char *field = getField(token);  
                    strcpy(currentPassport[fieldCounter], field);
                    // currentPassport[fieldCounter] = field;
                    fieldCounter++; 
                    printf("chunk token %s",token);
                    token = strtok_r(NULL, " ",&savePtr);
                }
            }
            currentPassport = realloc(currentPassport,sizeof(char) * (3 + fieldCounter +2));
            
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

char *getField(char *field) {
    char *localSave;
    char *fieldToken = strtok_r(field,":",&localSave);
    return fieldToken;
}