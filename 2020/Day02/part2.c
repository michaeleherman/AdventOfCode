#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day02/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }


    char chunk[512];
    int counter = 0;
    int min, max, ret;
    char letter;
    char password[100];
    int valid = 0;



    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        ret = sscanf(chunk,"%d-%d %c%*c %s", &min, &max,&letter,password);
 
      
        if (password[min-1] == letter && password[max-1] != letter) {
           valid++;
            printf("Valid: %d %d %c %s\n", min, max, letter, password);
            
        } else if (password[min-1] != letter && password[max-1] == letter) {
            valid++;
             printf("Valid: %d %d %c %s\n", min, max, letter, password);
        } else {
             printf("Invalid: %d %d %c %s\n", min, max, letter, password);
        }



    }

    printf("Valid passwords: %d\n",valid);

    return 0;

}