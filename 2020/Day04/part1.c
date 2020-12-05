#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day03/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
   
       
    return 0;

    }