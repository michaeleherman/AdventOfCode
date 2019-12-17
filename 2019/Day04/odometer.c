#include <stdlib.h>
#include <stdio.h>

int main()
{

    int odo[6];
    int mileage = 0;
    int pos = 0;

    for (int i = 0; i < 6; i++)
    {
        odo[i] = 0;
    }

    odo[pos] = (odo[pos] + 1) % 10;

    while (mileage < 100)
    {
        pos = 5;

   

        odo[pos] = (odo[pos] + 1) % 10;

        mileage = odo[5] + (odo[4] * 10) + (odo[3] * 100);

        printf("Mileage is: %d\n", mileage);
    }
}