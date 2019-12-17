#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int makeNewInt(int *intArray)
{
    int tmpInt = 0;
    for (int x = 0; x < 6; x++)
    {

        tmpInt = 10 * tmpInt + intArray[x];
    }

    return tmpInt;
}

int backFill(int *intArray, int startPos)
{

    for (int i = startPos; i < 6; i++)
    {

        intArray[i] = intArray[startPos - 1];
    }

    return 0;
}

int *splitInt(int tmpInt)
{
    static int tmpArray[6];
    for (int j = 5; j >= 0; j--)
    {
        tmpArray[j] = tmpInt % 10;
        tmpInt = tmpInt / 10;
    }

    return tmpArray;
}

int main()
{

    int startInt = 367479;
    int endInt = 893698;
    // int startInt = 444550;
    // int endInt = 444556;
    int validCount = 0;
    clock_t start, end;

    start = clock();

    while (startInt <= endInt)
    {
        bool lesserValue = false;
        int dupValueCount = 0;
        int dupValue;
        int dupGroupExists = 0;
        int newInt = 0;

        // printf("Value is: %d\n", i);
        //Split digit into array

        int *intArray = splitInt(startInt);

        for (int k = 5; k > 0; k--)
        {
            int kMinusOne = intArray[k - 1];
            int currK = intArray[k];

            if (currK < kMinusOne)
            {
                *intArray = backFill(intArray, k);
                startInt = makeNewInt(intArray);
                break;
            }

            if (currK > kMinusOne)
            {
                continue;
            }

            if (currK == kMinusOne)
            {
                if (dupValueCount == 0)
                {
                    dupValueCount++;
                    dupGroupExists = 1;
                    dupValue = kMinusOne;
                }
                else if (dupValueCount == 1 && kMinusOne == dupValue)
                {
                    dupGroupExists = 0;
                }
            }
        }

        if (lesserValue != true && dupGroupExists == 1)
        {
            printf("Valid value is %d\n", startInt);
            validCount++;
        }

        if (newInt == 0)
        {
            startInt++;
        }
    }

    end = clock();

    printf("Count of valid is %d\n", validCount);

    // Calculating total time taken by the program.
    double time_taken = (end - start);
    printf("start: %ld end: %ld Time taken: %f\n seconds", start, end, time_taken / CLOCKS_PER_SEC);
    return 0;
}