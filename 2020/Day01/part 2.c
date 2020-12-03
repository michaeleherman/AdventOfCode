#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(void){

    clock_t start, end;

    start = clock();

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

    int iterations = 0;

    // for (int first = 0; first < counter-2; first++) {
    //     iterations++;
    //     for (int second = first + 1; second < counter-1;second++){
    //         iterations++;
    //         for (int third = second + 1; third < counter; third++){
    //             iterations++;
    //             if (expenses[first] + expenses[second] + expenses[third] == 2020) {
    //             printf ("First is %i and second is %i and third is %i and sum is %i\n",expenses[first],expenses[second],expenses[third],expenses[first]*expenses[second]*expenses[third]);
    //             }
    //         }

    //     }
    // }

    // //     for (int i = 0; i < counter; i++) {
    // //     printf("%i\n",expenses[i]);
    // // }

    // printf("Iterations for loop: %i\n",iterations);


    int arrSize = counter;
    iterations = 0;

    for (int i = 0; i < arrSize-2;i++) {
        int l = i + 1;
        int r = arrSize - 1;
        iterations++;
        while (l < r) {
            iterations++;
            int val1 = expenses[i];
            int val2 = expenses[l];
            int val3 = expenses[r];

            if (val1 + val2 + val3 < 2020) {
                // printf("i is %i l is %i and r is %i Sum is less %i\n",val1,val2,val3,val1 + val2 + val3);
                l++;
            } else if (val1 + val2 + val3 > 2020)
            {
                // printf("i is %i l is %i and r is %i Sum is greater %i\n",val1,val2,val3,val1 + val2 + val3);
                r--;
            } else if (val1 + val2 + val3 == 2020) {
                printf("Found triplet %i %i %i\n",val1, val2,val3);
                printf("Iterations for while: %i\n",iterations);
                end = clock();

                double time_taken = (end - start);
                printf("start: %ld end: %ld Time taken: %f\n", start, end, time_taken);
                printf("clocks per second: %d", CLOCKS_PER_SEC);

                return 0;
            }
            
        }
    }




    return 0;

}