//    char str[res];
//
//    while (fscanf(filePtr, "%s\n", tmpStr) != EOF) {
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
#include <math.h>

int main(int argc, const char * argv[]) {
    
    //Input file
    //    char fileName[60] = "/Users/Dad/Documents/Code/AdventOfCode/2019/Day03/input.txt";
    //    FILE *filePtr;
    //    filePtr = fopen(fileName,"r");
    char wires[2][40];
    strcpy(wires[0],"R75,D30,R83,U83,L12,D49,R71,U7,L72");
    strcpy(wires[1], "U62,R66,U55,R34,D71,R55,D58,R83");
    char *token;
    int counter = 0;
    int xLength = 0;
    int yLength = 0;
    int distance = 0;
    char direction = '\0';
    char wireArray;
    
    
    
    int wireArraySize = ceil(sizeof wires[0]/3);
    wireArray = (char) malloc( wireArraySize);
        //add rows to wirearray
        if ( wireArray )
        {
          for ( int i = 0; i < wireArraySize; i++ )
              wireArray[i] = malloc( 5 );
        }
    
    token = strtok(wires[0],",");
    
    int maxR = 0;
    int maxL = 0;
    int maxU = 0;
    int maxD = 0;
    
    while ( token != NULL ) {
        //        strcpy(wireArray[counter], token);
        direction=token[0];
        char tmpDistance[4];
        distance=atoi(memcpy(tmpDistance, &token[1], 4));
        
        //Find the max distance for each direction
        if (direction == 'R' && direction > maxR) {
            maxR = direction;
        } else if (direction == 'L' && direction > maxL) {
            maxL = direction;
        } else if (direction == 'U' && direction > maxU) {
            maxU = direction;
        } else {
            if (direction > maxD) {
                maxD = direction;
            }
        }
        
        xLength = maxL + maxR;
        yLength = maxU + maxD;
        
        
        token = strtok(NULL, ",");
        counter++;
        
        
    }
    
    printf("%d, %d, %d, %d, %d, %d\n", maxR, maxL, maxU, maxD, xLength, yLength);
    
    int matrix[xLength][yLength];
    

    
    
    return 0;
}

