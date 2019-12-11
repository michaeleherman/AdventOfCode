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

#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)))

int main(int argc, const char * argv[]) {
    
    //Input file
    //    char fileName[60] = "/Users/Dad/Documents/Code/AdventOfCode/2019/Day03/input.txt";
    //    FILE *filePtr;
    //    filePtr = fopen(fileName,"r");
    char wires[2][40];
    strcpy(wires[0],"R75,D30,R83,U83,L12,D49,R71,U7,L72");
    strcpy(wires[1], "U62,R66,U55,R34,D71,R55,D58,R83");
//    char *token;
//    int counter = 0;
//    int xLength = 0;
//    int yLength = 0;
//    int distance = 0;
//    char direction = '\0';
    char *wireArray;
    
    wireArray = malloc(5);
    static const char *wire0[] = {"R75", "D30", "R83", "U83", "L12", "D49", "R71", "U7", "L72"};
    
    for (int i = 0; i<NUM_ELEM(wire0);i++) {
        printf("%s\n", wire0[i]);
    }
    
//    for (int i = 0; i< 4;i++) {
//        wireArray[i] = *(char *) malloc(4);
//        strcpy(&wireArray[i],list[i]);
//        wireArray = realloc(wireArray, 8);
//        printf("%s\n", &wireArray[i]);
//
//    }
//
    
}

