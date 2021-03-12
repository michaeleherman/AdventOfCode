#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define stage 1
#define chunkLength 255



int main() {
    char fileName[25];
    char filePathName[200];
  
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
        if (counter == 0) {
            //            timeStamp = atoi(chunk);
            counter++;
            continue;
        }
       
    }
    
    return 0;
    
}

