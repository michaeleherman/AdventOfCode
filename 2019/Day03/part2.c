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
    char wires[2][40];
    strcpy(wires[0],"R75,D30,R83,U83,L12,D49,R71,U7,L72");
    strcpy(wires[1], "U62,R66,U55,R34,D71,R55,D58,R83");
    char *token;
    char **wireArray;
    int counter = 0;
    int rows = 1;
    int cols = 5;
    
    wireArray = malloc( sizeof *wireArray * rows );
    if ( wireArray )
    {
      for ( size_t i = 0; i < rows; i++ )
        wireArray[i] = malloc( sizeof *wireArray[i] * cols );
    }
    
    token = strtok(wires[0], ",");
    
    while ( token != NULL ) {
        strcpy(wireArray[counter], token);
        printf("%s\n", wireArray[counter]);
        token = strtok(NULL, ",");
        counter++;
        
        char **tmp = realloc( wireArray, sizeof *wireArray * (rows + 1) );
        if ( tmp )
        {
          wireArray = tmp;
          for ( size_t i = 0; i < 1; i++ )
          {
             wireArray[rows + i] = malloc( sizeof *wireArray[rows + i] * cols );
          }
        }
        
    }
    

    return 0;
}


