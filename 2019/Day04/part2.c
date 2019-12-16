#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{

    int startInt = 367479;
    int endInt = 893698;
    int validCount = 0;

    int counter[6];

    for (int i = 5; i >= 0; i--)
    {
        counter[i] = startInt % 10;
        startInt = startInt / 10;
    };

    while (true)
    {
        for (int pos = 5; pos >= 0; pos--)
        {
            int currPos = counter[pos];
            int nextPos = counter[pos - 1];

            if (currPos >= nextPos)
            {
                
                continue;
            }
            else if (currPos == 0)
            {
                counter[pos - 1]++;
                continue;
            }
            else if (currPos < nextPos)
            {

                while (pos < 6)
                {
                    counter[pos] = counter[pos - 1];
                    pos++;
                }
            }
            else if ( pos == 0 ) {
                counter[5]++;
            }


            int newInt = 0;
            for (int z = 0; z < 6; z++)
            {
                newInt = 10 * newInt + counter[z];
            }

            printf("int is %d\n", newInt);

            if (newInt >= endInt)
            {
                break;
            } else {
                pos = 5;
                counter[5]++;
            }
        }
        
        break;
    }

    // for (int i = 0; i < 6; i++){
    //     printf ("%d %d\n", i, counter[i]);
    // }

    return 0;
}