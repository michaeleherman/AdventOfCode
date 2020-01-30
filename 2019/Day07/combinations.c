
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define n 5

void shift(int *arr, int size);

void dispArray(int arr[]);

void flip(int *arr, int *current);

void combinations(int *arr, int *pos);

void permutator(int *arr, int length);



int other()
{
    
    int array[] = {0, 1, 2, 3, 4};
    
    permutator(array,5);
    
    return 0;
}

void dispArray(int *arr)
{
    int counter = 0;
    
    while (counter < 5)
    {
        printf("%d ", arr[counter]);
        counter++;
    }
    printf("\n");
}

void flip(int *arr, int *current)
{
    int next = *current - 1;
    int tmp1 = arr[*current];
    int tmp2 = arr[next];
    //flip the array values
    arr[*current] = tmp2;
    arr[next] = tmp1;
    //move pointer to one less than arr-1
    *current -= 1;
    next -= 1;
}

void combinations(int *arr, int *pos)
{
    // int startpos = n - 1;
    int current = *pos;
    int next = current - 1;
    
    for (int loop = 0; loop < 3; loop++)
    {
        dispArray(arr);
        //store current array and one less
        flip(arr, &current);
        dispArray(arr);
        flip(arr, &current);
        current = *pos;
    }
}

// const permutator = (permutation) => {
//     var length = permutation.length,
//         result = [permutation.slice()],
//         c = new Array(length).fill(0),
//         i = 1, k, p;
//     while (i < length) {
//         if (c[i] < i) {
//             k = i % 2 && c[i];
//             p = permutation[i];
//             permutation[i] = permutation[k];
//             permutation[k] = p;
//             ++c[i];
//             i = 1;
//             result.push(permutation.slice());
//         } else {
//             c[i] = 0;
//             ++i;
//         }
//     }
//     return result;
// }

struct comboStruct permutator(int *arr, int length)
{
    combo c_results;
    int result[120][5];
    int cSize = 5;
    int c[cSize];
    memset(c, 0, sizeof(c[0]) * cSize);
    int i = 1;
    int k, p;
    int resultCount = 1;
    memcpy(result[0], arr, sizeof(int)*cSize);
    
    while (i < length)
    {
        if (c[i] < i)
        {
            if (i % 2 == 0)
            {
                k = i % 2;
            }
            else
            {
                k = c[i];
            }
            p = arr[i];
            arr[i] = arr[k];
            arr[k] = p;
            ++c[i];
            i = 1;
            memcpy(result[resultCount], arr, sizeof(int)*cSize);
            resultCount++;
        } else {
            c[i] = 0;
            ++i;
        }
        
        
    }
    
    
}
