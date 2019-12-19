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

bool checkForDups(int *arr)
{
    int currentDups[10];
    memset(currentDups, 0, 10 * sizeof(int));
    for (int i = 5; i >= 0; i--)
    {
        if (arr[i] == arr[i - 1])
        {
            currentDups[arr[i]] = currentDups[arr[i]] + 1;
        }
    }

    for (int j = 0; j < 10; j++)
    {
        if (currentDups[j] == 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    int startingInt = 367479;
    // int currentInt = 399000;
    // int startingInt = 367789;
    int endInt = 893698;
    int digitArray[6];
    bool dups = false;
    int dupDigit = 0;
    int passwordCount = 0;
    int currentInt = startingInt;
    int priorInt = 0;
    int outOfOrderPos = 99;

    while (currentInt <= endInt)
    {

        parseInt(currentInt, digitArray);

        for (int i = 5; i > 0; i--)
        {

            // Less than case
            if (digitArray[i] < digitArray[i - 1])
            {
                outOfOrderPos = i;
            }
        }

        if (outOfOrderPos != 99) {
        lessThan(digitArray,outOfOrderPos);
        }

        outOfOrderPos = 99;

        dups = checkForDups(digitArray);

        priorInt = restoreInt(digitArray);
        currentInt = priorInt + 1;

        if (dups == true )
        {
            printf("Found a match: %d\n", priorInt);
            passwordCount++;
        }
        else
        {
            printf("Not a match: %d\n", priorInt);
        }
    }
    printf("Total valid passwords: %d\n", passwordCount);
    return 0;
}

// for (int i = 0; i < 6; i++){
//     printf ("%d %d\n", i, counter[i]);
// }
