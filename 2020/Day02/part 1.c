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
        printf("%d %d %c %s\n",min,max, letter, password);
        int counter = 0;
        for (int i = 0; i<strlen(password);i++) {
            if (password[i] == letter) {
                counter++;
            }
        }

        if (counter <= max && counter >= min) {
            valid++;
        }



    }

    printf("Valid passwords: %d\n",valid);

    return 0;

}