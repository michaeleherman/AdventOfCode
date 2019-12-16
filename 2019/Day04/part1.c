#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

int main()
{

    int startInt = 367479;
    int endInt = 893698;
    int validCount = 0;

    for (int i = startInt; i <= endInt; i++)
    {
        int intArray[6];
        memset(intArray, 0, 6);
        bool lesserValue = false;
        bool dupValue = false;
        
        int tmpInt = i;
        // printf("Value is: %d\n", i);
        //Split digit into array
        for (int j = 5; j >= 0; j--)
        {
            intArray[j] = tmpInt % 10;
            tmpInt = tmpInt / 10;

            // printf("counter %d digit %d\n", j, intArray[j]);
        }

        for (int k = 1; k < 6; k++)
        {
            int kMinusOne = intArray[k-1];
            int currK = intArray[k];
            if (kMinusOne > currK && lesserValue !=true )
            {
                lesserValue = true;
                // printf("%d is less than %d\n", intArray[k], intArray[k-1]);
                break;
            }

            if (kMinusOne == currK && dupValue == false ) {
                dupValue = true;
            } 
        

            
        }

        if (lesserValue != true && dupValue == true) {
            // printf("Valid value is %d\n", i);
            validCount++;

        }

    }
    printf("Count of valid is %d\n", validCount);
    return 0;
}