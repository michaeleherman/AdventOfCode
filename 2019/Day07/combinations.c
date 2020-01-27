#include <stdio.h>
#include <stdlib.h>

#define n 5

void shift(int *arr, int size);

void dispArray(int arr[]);

void flip(int *arr, int *current);

void combinations(int *arr, int *pos);

int main()
{
    int comboArray[120][5];
    int *arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    //point to end of array
    int startPos = 4;

    combinations(arr,&startPos);

    startPos = 2;
    flip(arr, &startPos);

    startPos = 4;

    combinations(arr,&startPos);

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

// void shift(int *arr, int size)
// {
//     int shiftedValue = arr[0];
//     for (int i = 0; i < size - 1; i++)
//     {
//         arr[i] = arr[i + 1];
//     }
//     arr[size-1] = shiftedValue;
// }