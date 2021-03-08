#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define chunkLength 250
#define DELAY(ts) (ts - (timeStamp % ts))


int main() {
    int *schedule;
    schedule = malloc(sizeof(int));
    int counter = 0;
    int timeStamp = 0;
    int tokenCount = 0;
    char sep[2] = ",";
    char chunk[chunkLength];
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day13/data.txt","r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        chunk[strcspn(chunk, "\n")] = 0;
        if (counter == 0) {
            timeStamp = atoi(chunk);
            counter++;
            continue;
        }
        char *token = strtok(chunk,sep);

        
        while (token != NULL) {
            if (strcmp(token,"x") != 0) {
                schedule[tokenCount] = atoi(token);
                tokenCount++;
                schedule = realloc(schedule, sizeof(int) * (tokenCount + 1));
            } 
            token = strtok(NULL,sep);
        }
    }
    
    int bus = DELAY(timeStamp);
    for (int i = 0; i < tokenCount -1; i++){
//        printf("delay i %d delay bus %d\n",DELAY(schedule[i]),DELAY(bus));
        if (DELAY(schedule[i]) < DELAY(bus)) {
            bus = schedule[i];
        }
    }
    
    printf("wait time is %d\n", DELAY(bus) * bus);
    return 0;
    
}

