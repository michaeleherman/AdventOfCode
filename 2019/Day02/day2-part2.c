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
    char str[] = "1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,19,5,23,2,9,23,27,1,5,27,31,1,5,31,35,1,35,13,39,1,39,9,43,1,5,43,47,1,47,6,51,1,51,13,55,1,55,9,59,1,59,13,63,2,63,13,67,1,67,10,71,1,71,6,75,2,10,75,79,2,10,79,83,1,5,83,87,2,6,87,91,1,91,6,95,1,95,13,99,2,99,13,103,1,103,9,107,1,10,107,111,2,111,13,115,1,10,115,119,1,10,119,123,2,13,123,127,2,6,127,131,1,13,131,135,1,135,2,139,1,139,6,0,99,2,0,14,0";
    // int strLength = strlen(str);
    //    char str[] = "1,9,10,3,2,3,11,0,99,30,40,50";
    int *ptr;
    int *tmpPtr;
    
    char *token = strtok(str, ",");
    int counter = 0;
    int i;
    
    ptr = malloc(1*sizeof(int));
    tmpPtr = malloc(0);
    
    
    while (token != NULL) {
        //        printf("Loop counter: %d\n",counter);
        ptr[counter] = atoi(token);
        tmpPtr = realloc(ptr, (counter + 2) * sizeof(int));
        if (tmpPtr != NULL) {
            ptr = tmpPtr;
        } else {
            printf("Memory allocation error");
        }
        
        token = strtok (NULL, ",");
        counter++;
    }
    
    //    19690720
    
    //    for (int item = 0;item<counter;item++) {
    //        printf("Item %d, value %d\n",item, ptr[item]);
    //    }
    //
    for (int noun=0;noun<100;noun++) {
        //        printf("Noun: %d\n", noun);
        for (int verb=0;verb<100;verb++) {
            //            printf("Verb: %d\n", verb);
            int *tmpPtr = malloc(counter * sizeof(int));
            memcpy(tmpPtr, ptr, counter * sizeof(int));
            tmpPtr[1]=noun;
            tmpPtr[2]=verb;
            
            //            for (int item = 0;item<counter;item++) {
            //                printf("Noun %d, Verb %d, Item %d, value %d\n",noun, verb,item, tmpPtr[item]);
            //            }
            
            for (i = 0; i<(counter);i++) {
                if (tmpPtr[i] == 1) {
                    int operandPosition1 = tmpPtr[i+1];
                    int operandPosition2 = tmpPtr[i+2];
                    int storageLocation = tmpPtr[i+3];
//                    printf("1 i: %d noun: %d verb: %d op1: %d op2: %d stor: %d value: %d\n", i, noun, verb, operandPosition1, operandPosition2, storageLocation, tmpPtr[operandPosition1] + tmpPtr[operandPosition2]);
                    tmpPtr[storageLocation] = tmpPtr[operandPosition1] + tmpPtr[operandPosition2];
                } else if (tmpPtr[i] == 2) {
                    int operandPosition1 = tmpPtr[i+1];
                    int operandPosition2 = tmpPtr[i+2];
                    int storageLocation = tmpPtr[i+3];
//                    printf("2 i: %d noun: %d verb: %d op1: %d op2: %d stor: %d value: %d\n", i, noun, verb, operandPosition1, operandPosition2, storageLocation, tmpPtr[operandPosition1] * tmpPtr[operandPosition2]);
                    tmpPtr[storageLocation] = tmpPtr[operandPosition1] * tmpPtr[operandPosition2];
                } else if (tmpPtr[i] == 99) {
                    break;
                }
                
                i = i + 3;
            }
            printf("noun: %d verb: %d loc0: %d\n", noun, verb, tmpPtr[0]);
            if (tmpPtr[0] == 19690720) {
                printf("found combo - noun: %d, verb: %d\n", ptr[1], ptr[2]);
                printf("answer is: %d\n", 100*noun+verb);
                return 0;
            }
        }
    }
    
    return 0;
}

