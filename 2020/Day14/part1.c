#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define stage 1
#define chunkLength 255
#define maskLength 36

#define IS_BIT_SET(BF, N) ((BF >> N) & 0x1)
#define SET_BIT(BF, N) BF |= (1<< N);   

struct memAddValue {
    long location;
    uint64_t value:36;
};



void makeMaskArray (char chunk[chunkLength], int maskArray[maskLength]);
void getMemLocation(struct memAddValue *record, char chunk[chunkLength]);
void evaluate(struct memAddValue *record);
void sumIt (long long *memArr, long long maxMemLocation);

int maskArray[maskLength];
struct memAddValue *memArray;
long long *memArr;

int main() {


    memArray = malloc(sizeof(struct memAddValue));
    memArr = malloc(sizeof(long long));
    long maxMemLocation = 0;
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
            // memArray[end] = record;
            // memArray = realloc(memArray, sizeof(struct memAddValue) * (end + 2));
            if (record.location > maxMemLocation) {
                memArr = realloc(memArr, sizeof(long long) * (record.location + 2));
                long long oldMax = maxMemLocation;
                maxMemLocation = record.location;
                for (int i = oldMax; i<maxMemLocation; i++) {
                    memArr[i] = 0;
                }
            }
            memArr[record.location] = record.value;
            evaluate(rptr);
        }
       
    }
    sumIt(memArr,maxMemLocation);
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
    // sscanf(record->value,"%d",atoi(token));
    record->value = atoi(token);
}

void evaluate(struct memAddValue *record) {
    // printf("%ld %lld\n",record->location,record->value);
    for (int j = 0; j < maskLength;j++) {
        if ( maskArray[j] == 0 || maskArray[j] == 1) {
            printf("%d ",maskArray[j]);
        } else {
            printf("%c ",maskArray[j]);
        }
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < maskLength; i++) {
        int inverse = 35 -i;
        int bit = record->value & (1 << inverse);
        printf("%d ",bit);
        if (maskArray[i] == 1) {
            memArr[record->location] |= 1 << inverse;
        } else if (maskArray[i] == 0) {
            memArr[record->location] |= 0 << inverse;
        } else {
            continue;
        }
        // printf("tmp %lu\n",tmpValue);
    }
    printf("\n");
    printf("record value %llu\n",memArr[record->location]);
}

void sumIt (long long *memArr, long long maxMemLocation) {
    long long sum = 0;
    for (long long i = 0; i <= maxMemLocation; i++) {
        printf("memArr %lld is %lld\n",i,memArr[i]);
        sum += memArr[i];
    }
    printf("final sum is: %lld\n",sum);
}


