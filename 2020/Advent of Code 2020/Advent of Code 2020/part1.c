#include "part1.h"

enum inRange {YES, NO};

int valuesArray[ARRAYSIZE] = {0};
int nearbyTixArr[ARRAYSIZE] = {0};
extern int validTix[ARRAYSIZE][FIELDS_COUNT];


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
        sscanf(chunk,"%s %d-%d or %d-%d",fields[end].fieldName,&fields[end].start1,&fields[end].end1,&fields[end].start2,&fields[end].end2);
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
    bool invalidValue = false;
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
                invalidValue = true;
                invalid += tixNum;
                break;
            } else {
                validTix[validEnd][position] = tixNum;
                position++;
            }
            token = strtok(NULL,delim);
        }
        if (invalidValue == false){
            validEnd++;
        } else {
            invalidValue = false;
        }
    }
    
    
    // for (int i = 0; i<100; i++) {
    //     printf("%d %d\n",i,valuesArray[i]);
    // }
    
//
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

