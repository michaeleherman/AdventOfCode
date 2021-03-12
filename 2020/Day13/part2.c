#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define chunkLength 250
#define DELAY(ts) (timeStamp % ts)
#define stage 1

enum DISCOVER {NOTFOUND, FOUND};

struct bus {
    int busNo;
    int position;
};

struct bus *buses;

int checkDeparture(int timestamp, struct bus *buses, int pos);
long long int multiplyBuses(int multiplier[9]);

int main() {
    char fileName[25];
    char filePathName[200];
    printf("%s",getcwd(filePathName,sizeof(filePathName)));

    if ( stage == 0) {
        strcpy(fileName, "/test.txt");

    } else {
        strcpy(fileName, "/data.txt");
    }
    strcat(filePathName,fileName);

    buses = malloc(sizeof(struct bus));
    int end = 0;
    int counter = 0;
    int tokenCount = 0;
    char sep[2] = ",";
    char chunk[chunkLength];
    long long timeStamp = 1;
    FILE *fp = fopen(filePathName,"r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        chunk[strcspn(chunk, "\n")] = 0;
        if (counter == 0) {
            //            timeStamp = atoi(chunk);
            counter++;
            continue;
        }
        char *token = strtok(chunk,sep);
        
        
        while (token != NULL) {
            if (strcmp(token,"x") != 0) {
                buses[end].busNo = atoi(token);
                buses[end].position = tokenCount;
                buses = realloc(buses,sizeof(struct bus) * (end + 2));
                end++;
            }
            tokenCount++;
            token = strtok(NULL,sep);
        }
    }
    int discovered = NOTFOUND;
    timeStamp = 100000000000000;
    //    timeStamp = 1;
    long long offset = buses[0].busNo;
    int multiplier[end];
    memset(multiplier, 0, sizeof(int) * end);
    multiplier[0] = buses[0].busNo;
    long long busMultiplier = 1;
    while (discovered == NOTFOUND){
        // printf("%lld ",timeStamp);
        for (int i = 0;i < end; i++) {
            long long tmpTs = timeStamp + buses[i].position;
            offset = (tmpTs) % buses[i].busNo;
            // printf("timestamp %lld - current bus %d delay %d\n",tmpTs,buses[i].busNo, offset);
            // printf("%d\t%lld\t",buses[i].busNo,timeStamp%buses[i].busNo);
            if (offset != 0) {
                break;
            } else {
                printf("%lld\t%d\t%lld\n",timeStamp,buses[i].busNo,timeStamp%buses[i].busNo);
                if (multiplier[i] == 0) {
                multiplier[i] = buses[i].busNo;
                }
                busMultiplier = multiplyBuses(multiplier);
//                printf("current bus %d current timestamp %lld\n",buses[i].busNo, tmpTs);
                if (i == end - 1) {
                    printf("found it - timestamp %lld\n\n",timeStamp);
                    discovered = FOUND;
                    break;
                }
            }
        }
        // printf("\n");

        if (discovered == FOUND ){
            exit(0);
        } else {
            timeStamp += busMultiplier;
        }

        
    }
    
    
    
    return 0;
    
}

long long int multiplyBuses(int multiplier[9]) {
    long long product = 1;
    for (int i = 0; i < 9; i++) {
        if ( multiplier[i] == 0) {
            break;
        }
        product *= multiplier[i];
    }
    return product;
}



