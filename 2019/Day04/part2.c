#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{

    // int startInt = 367479;
    int startInt = 399000;
    int endInt = 893698;
    int validCount = 0;
    int newInt = startInt;

    int counter[6];

    for (int i = 5; i >= 0; i--)
    {
        counter[i] = startInt % 10;
        startInt = startInt / 10;
    };

    while (newInt <= endInt)
    {
        for (int pos = 5; pos >= 0; pos--)
        {
            int currPos = counter[pos];
            int nextPos = counter[pos - 1];

            if (pos == 0)
            {
                counter[5] = (counter[5] + 1) % 10;
                for (int i = 5; i >= 0; i--)
                {
                    if (counter[i] == 0)
                    {
                        counter[i - 1] = (counter[i - 1] + 1) % 10;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (currPos >= nextPos)
            {

                continue;
            }
            // else if (currPos == 0)
            // {
            //     counter[pos - 1] = counter[pos - 1] % 10;
            //     continue;
            // }
            else if (currPos < nextPos)
            {

                while (pos < 6)
                {
                    counter[pos] = counter[pos - 1];
                    pos++;
                }
            }

            newInt = 0;
            for (int z = 0; z < 6; z++)
            {

                newInt = 10 * newInt + counter[z];
            }
            if (newInt == endInt)
            {
                break;
            }
            printf("int is %d\n", newInt);
        }

        // if (newInt >= endInt)
        // {
        //     break;
        // }
    }

    return 0;
}

// for (int i = 0; i < 6; i++){
//     printf ("%d %d\n", i, counter[i]);
// }
