//
//  main.c
//  AdventOfCode
//
//  Created by Michael Herman on 12/3/19.
//  Copyright © 2019 Michael Herman. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    //Input file
//    char fileName[60] = "/Users/Dad/Documents/Code/AdventOfCode/2019/Day03/input.txt";
//    FILE *filePtr;
//    filePtr = fopen(fileName,"r");
    char tmpStr[67] = "R75,D30,R83,U83,L12,D49,R71,U7,L72,U62,R66,U55,R34,D71,R55,D58,R83";
    char *token;
    int i = 0;
    
    //Get size of file
//    fseek(filePtr, 0, SEEK_END);
//    long int res = ftell(filePtr);
//    printf("file size is %ld\n",res);
//    rewind(filePtr);
//    char tmpStr[res];
//    char str[res];
//
//    while (fscanf(filePtr, "%s\n", tmpStr) != EOF) {
//        fscanf(filePtr, "%s\n", str);
//        strcat(tmpStr, str);
//    }
    
//    fscanf(filePtr, "%s", tmpStr);
//    printf("%s\n", tmpStr);
//    printf("string length %lu\n", strlen(tmpStr));
//    printf("size of char %lu\n",sizeof(char));
//    printf("memory size needed, maybe: %lu\n", strlen(tmpStr)*sizeof(char)*5);
    
    long arraySize = sizeof(char)*strlen(tmpStr);
    printf("array size should be %li\n", arraySize);
//    char locArray[601][6];
    char locArray[16][6];
//    char tmpArray[arraySize];

    token = strtok(tmpStr, ",");

    while(token != NULL)
    {

        strcpy(locArray[i], token);
        token = strtok(NULL, ",");
        
        i++;

    }

    for (int j=0;j<17;j++) {
        printf("%d, %s\n", j,locArray[j]);
    }
    
    int grid[10][10];
    int incrementer = -50;
    
    for (int k = 0; k<10; k++) {
        for (int l = 0; l < 10; l++) {
            grid[k][l] = incrementer;
            printf("%d\n", grid[k][l]);
            incrementer++;
        }
    }
    
    return 0;
}

