
//  main.c
//  AdventOfCode
//
//  Created by Michael Herman on 12/3/19.
//  Copyright © 2019 Michael Herman. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_wire_array.h"
#include "fill_matrix.h"
#include "split_value.h"


int main()
{

    // read the file line by line
    // assign each line to a char*
    // turn strings into arrays
    // calculate matrix size
    // for each item in array, fill matrix

    char wires[2][40];
    strcpy(wires[0], "R75,D30,R83,U83,L12,D49,R71,U7,L72");
    strcpy(wires[1], "U62,R66,U55,R34,D71,R55,D58,R83");

    //Get the wire text strings turned into arrays
    struct wireArrayStruct wireArray0 = getWireArray(wires[0]);
    // struct wireArrayStruct wireArray1 = getWireArray(wires[1]);


    int xAxis = 0;
    int yAxis = 0;
    //get size of matrix
    for (int i = 0; i < wireArray0.counter; i++)
    {
        struct DirDist currValue = splitDirDist(wireArray0.tmpArray[i]);

        if (currValue.direction == 'L' || currValue.direction == 'R') {
            xAxis += currValue.distance;
        } else {
            yAxis += currValue.distance;
        }
    }

    xAxis = xAxis *2;
    yAxis = yAxis *2;

    struct matrixStruct arrayStruct = fillmatrix(xAxis, yAxis, wireArray0);

    for (int i = 0; i<arrayStruct.counter; i++) {
        printf("%d, %d\n", arrayStruct.matrixArray[i][0],arrayStruct.matrixArray[i][1]);
    }


    return 0;
}

