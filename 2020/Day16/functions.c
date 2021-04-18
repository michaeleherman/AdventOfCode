#include "functions.h"

enum inRange {YES, NO};

int valuesArray[ARRAYSIZE] = {0};
int nearbyTixArr[ARRAYSIZE] = {0};
extern int validTix[ARRAYSIZE][FIELDS_COUNT];
extern struct ticketField fields[ARRAYSIZE];


int part1(void){
    
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day16/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    char chunk[CHUNK_SIZE];
    extern int fieldsEnd;
    int invalid = 0;
    
    // first get ticket fields
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (strcmp(chunk,"\n") == 0){
            break;
        }
        char *token;
        char delim[2] = ":";
        token = strtok(chunk,delim);
        strcpy(fields[fieldsEnd].fieldName,token);
        token = strtok(NULL, delim);
        int start1, end1, start2, end2;
        sscanf(token,"%d-%d or %d-%d",&start1,&end1,&start2,&end2);
        fields[fieldsEnd].start1 = start1;
        fields[fieldsEnd].start2 = start2;
        fields[fieldsEnd].end1= end1;
        fields[fieldsEnd].end2 = end2;
        fields[fieldsEnd].position = -1;
        addToArray(start1,end1);
        addToArray(start2,end2);
        ++fieldsEnd;
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
    return validEnd;
    
}


int checkValue(int value){
    if (valuesArray[value] == 1) {
        return YES;
    }
    return NO;
}

void addToArray(int start, int end) {
    for (int i = start;i <= end; i++) {
        valuesArray[i] = 1;
    }
}
