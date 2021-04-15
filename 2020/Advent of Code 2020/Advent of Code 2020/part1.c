#include "part1.h"

#define CHUNK_SIZE 250
#define FIELDS_COUNT 3
#define VALUES_COUNT 2
#define ARRAYSIZE 1000

enum inRange {YES, NO};

int valuesArray[ARRAYSIZE] = {0};
int nearbyTixArr[ARRAYSIZE] = {0};
int validTix[ARRAYSIZE][ARRAYSIZE] = {0};


int part1(void){
    
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day16/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    char chunk[CHUNK_SIZE];
    int end = 0;
    int invalid = 0;
    
    // first get ticket fields
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (strcmp(chunk,"\n") == 0){
            break;
        }
        char field[50];
        char range1[50];
        char range2[50];
        sscanf(chunk,"%s %s or %s",field,range1, range2);
        addToArray(range1);
        addToArray(range2);
        ++end;
    }
    
    // now get my ticket
    char myTicket[CHUNK_SIZE];
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (strcmp(chunk,"\n") == 0){
            break;
        }
        if (strstr(chunk,"your ticket")) {
            continue;
        }
        strcpy(myTicket,chunk);
    }
    
    // now get the nearby tickets
    int validEnd = 0;
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (strstr(chunk,"nearby tickets")) {
            continue;
        }
        int position = 0;
        char *token;
        char delim[2] = ",";
        token = strtok(chunk,delim);
        while (token != NULL) {
            int tixNum = atoi(token);
            if ( checkValue(tixNum) == NO) {
                invalid += tixNum;
                break;
            } else {
                validTix[validEnd][position] = tixNum;
                position++;
            }
            token = strtok(NULL,delim);
        }
        
    }
    
    
    // for (int i = 0; i<100; i++) {
    //     printf("%d %d\n",i,valuesArray[i]);
    // }
    
    printf("invalid sum %d\n",invalid);
    return 0;
    
}

void addToArray(char range[50]) {
    int start,end;
    sscanf(range,"%d-%d",&start,&end);
    for (int i = start;i <= end; i++) {
        valuesArray[i] = 1;
    }
}

int checkValue(int value){
    if (valuesArray[value] == 1) {
        return YES;
    }
    return NO;
}

