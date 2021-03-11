#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define chunkLength 250
#define DELAY(ts) (timeStamp % ts)

enum DISCOVER {NOTFOUND, FOUND};

struct bus {
    int busNo;
    int position;
};

struct bus *buses;

int checkDeparture(int timestamp, struct bus *buses, int pos);
int multiplyBuses(int multiplier[9]);

int main() {
    
    buses = malloc(sizeof(struct bus));
    int end = 0;
    int counter = 0;
    int tokenCount = 0;
    char sep[2] = ",";
    char chunk[chunkLength];
    long long timeStamp = 1;
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day13/data.txt","r");
    
    
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
//        timeStamp = 1;
    int offset = buses[0].busNo;
    int multiplier[end];
    memset(multiplier, 0, sizeof(int) * end);
    multiplier[0] = buses[0].busNo;
    int busMultiplier = 1;
    while (discovered == NOTFOUND){
        for (int i = 0;i < end; i++) {
            long long tmpTs = timeStamp + buses[i].position;
            offset = (tmpTs) % buses[i].busNo;
            printf("timestamp %lld - current bus %d delay %d\n",tmpTs,buses[i].busNo, offset);
            if (offset != 0) {
                break;
            } else {
                if (multiplier[i] == 0) {
                multiplier[i] = buses[i].busNo;
                busMultiplier = multiplyBuses(multiplier);

                }
//                printf("current bus %d current timestamp %lld\n",buses[i].busNo, tmpTs);
                if (i == end - 1) {
                    printf("found it - timestamp %lld\n\n",timeStamp);
                    discovered = FOUND;
                    break;
                }
            }
        }

        if (discovered == FOUND ){
            exit(0);
        } else {
            timeStamp += busMultiplier;
        }

        
    }
    
    
    
    return 0;
    
}

int multiplyBuses(int multiplier[9]) {
    int product = 1;
    for (int i = 0; i < 9; i++) {
        if ( multiplier[i] == 0) {
            break;
        }
        product *= multiplier[i];
    }
    return product;
}



