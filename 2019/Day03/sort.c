#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int **arr, int n)
{
    int x, y, z, i;
    for (x = 0; x < n - 1; x++)
    {
        for (y = 0; y < n - 1; y++)
        {
            if (arr[y][0] > arr[y + 1][0])
                    if (arr[y][1] > arr[y + 1][1])
                    {
                        swap(&arr[y][0], &arr[y + 1][0]);
                        swap(&arr[y][1], &arr[y + 1][1]);
                    }
                
        }
    }
}