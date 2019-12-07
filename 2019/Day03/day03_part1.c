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
    
    char fileName[60] = "/Users/Dad/Documents/Code/AdventOfCode/2019/Day03/input.txt";
    FILE *filePtr;
    filePtr = fopen(fileName,"r");
    int wordLength = 4;

    char *token;
    int i;
    char s[1] = ",";
    
    fseek(filePtr, 0, SEEK_END);
    
    // calculating the size of the file
    long int res = ftell(filePtr);
    
    printf("file size is %ld\n",res);
    
    rewind(filePtr);
    char tmpStr[res];
    
    fscanf(filePtr, "%s", tmpStr);
//    printf("%s\n", tmpStr);
//    printf("string length %lu\n", strlen(tmpStr));
    char array[strlen(tmpStr)*sizeof(char)][5];
    char tmpArray[strlen(tmpStr)*sizeof(char)][5];
    
    token = strtok(tmpStr, s);
    
    while(token != NULL)
    {
//        printf("%s\n",token);
        token = strtok(NULL,s);
        array[i] = token;
        
        i++;
        
    }
    
    
    
    
    
    return 0;
}

