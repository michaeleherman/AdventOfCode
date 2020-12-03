#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

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

    qsort(expenses, counter, sizeof(int), cmpfunc);


    // for (int first = 0; first < counter-2; first++) {
    //     for (int second = first + 1; second < counter-1;second++){
    //         for (int third = second + 1; third < counter; third++){
    //             if (expenses[first] + expenses[second] + expenses[third] == 2020) {
    //             printf ("First is %i and second is %i and third is %i and sum is %i\n",expenses[first],expenses[second],expenses[third],expenses[first]*expenses[second]*expenses[third]);
    //             }
    //         }

    //     }
    // }

    int n = counter-1;
    int i = 0;
    int sum = 0;

    while (sum != 2020) {
        int val1 = expenses[i];
        int val2 = expenses[i+1];
        int val3 = expenses[n];

        if (val1 + val2 + val3 < 2020) {
            i++;
        } else if (val1 + val2 + val3 > 2020)
        {
            n--;
        } else if (val1 + val2 + val3 == 2020) {
            printf("Found triplet %i %i %i\n",val1, val2,val3);
            break;
        }
        
    }

    // for (int i = 0; i < counter; i++) {
    //     printf("%i\n",expenses[i]);
    // }

    return 0;

}
