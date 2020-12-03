#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){

    FILE *fp = fopen("/Users/michael/Documents/Code/AdventOfCode/2020/Day01/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    int *expenses = malloc(1*sizeof(int));
    char chunk[128];
    int counter = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {

        int expense = strtol(chunk, NULL, 10);
        expenses[counter] = expense;
        counter++;
        expenses = realloc(expenses, (counter + 1)*sizeof(int));

    }


    for (int first = 0; first < counter-2; first++) {
        for (int second = first + 1; second < counter-1;second++){
                if (expenses[first] + expenses[second] == 2020) {
                printf ("First is %i and second is %i and third is %i and sum is %i\n",expenses[first],expenses[second],expenses[first]*expenses[second]);
            }

        }
    }

    // for (int i = 0; i < counter; i++) {
    //     printf("%i\n",expenses[i]);
    // }

    return 0;

}