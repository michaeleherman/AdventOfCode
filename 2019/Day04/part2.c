#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void lessThan(int *arr, int position)
{

    while (position < 6)
    {
        arr[position] = arr[position - 1];
        position++;
    }
}

void parseInt(int currentInt, int *arr)
{
    for (int i = 5; i >= 0; i--)
    {
        arr[i] = currentInt % 10;
        currentInt = currentInt / 10;
    };
}

int restoreInt(int *arr)
{
    int tmpInt = 0;
    for (int i = 0; i < 6; i++)
    {
        tmpInt = 10 * tmpInt + arr[i];
    }

    return tmpInt;
}

int main()
{

    int currentInt = 367479;
    // int currentInt = 399000;
    int endInt = 893698;
    int digitArray[6];

    while (currentInt <= endInt)
    {

        parseInt(currentInt, digitArray);

        for (int i = 5; i > 0; i--)
        {

            // Less than case
            if (digitArray[i] < digitArray[i - 1])
            {
                lessThan(digitArray, i);
            }

            if (digitArray[i] == )

        }

        currentInt = restoreInt(digitArray);
    }
    return 0;
}

// for (int i = 0; i < 6; i++){
//     printf ("%d %d\n", i, counter[i]);
// }
