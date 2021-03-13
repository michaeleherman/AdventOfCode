#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define stage 0
#define chunkLength 255
#define maskLength 36

#define IS_BIT_SET(BF, N) ((BF >> N) & 0x1)
#define SET_BIT(BF, N) BF |= (1<< N);   

struct memAddValue {
    long location;
    long value;
};


void makeMaskArray (char chunk[chunkLength], int maskArray[maskLength]);
void getMemLocation(struct memAddValue *record, char chunk[chunkLength]);

int main() {
    int maskArray[maskLength];
    struct memAddValue *memArray;
    memArray = malloc(sizeof(struct memAddValue));
    long memLocation;
    long maxMemLocation;
    char fileName[25];
    char filePathName[200];
    getcwd(filePathName,sizeof(filePathName));
  
    if ( stage == 0) {
        strcpy(fileName, "/test.txt");

    } else {
        strcpy(fileName, "/data.txt");
    }
    strcat(filePathName,fileName);

    int end = 0;
    int counter = 0;
    char chunk[chunkLength];
    FILE *fp = fopen(filePathName,"r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        chunk[strcspn(chunk, "\n")] = 0;
        if (strstr(chunk,"mask")) {
            makeMaskArray(chunk,maskArray);
        } else {
            struct memAddValue record;
            struct memAddValue *rptr = &record;
            getMemLocation(rptr,chunk);
            memArray[end] = record;
            memArray = realloc(memArray, sizeof(struct memAddValue) * (end + 2));
            end++;
        }
       
    }
    
    return 0;
    
}

void makeMaskArray (char chunk[chunkLength], int maskArray[maskLength]) {
    char tmpChunk[chunkLength];
    strcpy(tmpChunk,strstr(chunk, "= ")+2);
    for(int i = 0; i < maskLength;i++){
        if (tmpChunk[i] == 49 ) {
            maskArray[i] = 1;
        } else if (tmpChunk[i] == 48) {
            maskArray[i] = 0;
        } else {
            maskArray[i] = tmpChunk[i];
        }
    }
}

void getMemLocation(struct memAddValue *record, char chunk[chunkLength]){
    char delim[2] = "[";
    char *token;
    char *ptr;
    token = strtok_r(chunk,delim,&ptr);
    strcpy(delim,"]");
    token = strtok_r(NULL, delim,&ptr);
    record->location = atoi(token);
    strcpy(delim,"=");
    token = strtok_r(NULL, delim, &ptr);
    token = strtok_r(NULL, delim, &ptr);
    record->value = atoi(token);
}

