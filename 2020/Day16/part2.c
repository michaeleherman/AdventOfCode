#include "part2.h"

extern _field fields[ARRAYSIZE];

int main(void)
{
    int validEnd = part1();
    // printf("valid end is %d\n", validEnd);

    int i, j, k;
    for (i = 0; i < fieldsEnd; i++)
    {
        for (j = 0; j < FIELDS_COUNT; j++)
        {
            for (k = 0; k < validEnd; k++)
            {
                int value = validTix[k][j];
                if ((value >= fields[i].start1 && value <= fields[i].end1) ||
                    (value >= fields[i].start2 && value <= fields[i].end2))
                {
                    valid = true;
                    fields[i].position[j] = 1;
                }
                else
                {
                    valid = false;
                    fields[i].position[j] = 0;
                    // printf("position %d invalid for %s\n", j, fields[i].fieldName);
                    break;
                }
            }
            if (valid == true)
            {
                // printf("position %d valid for %s\n", j, fields[i].fieldName);
                fields[i].onesCount++;
            }
        }
    }

    // for (int k = 0; k < fieldsEnd; ++k)
    // {
    //     printf("%s,", fields[k].fieldName);
    //     for (int i = 0; i < FIELDS_COUNT; ++i)
    //     {
    //         printf("%2d,", fields[k].position[i]);
    //     }
    //     printf("\n");
    // }

    checkFields();
    for (int i = 0;i<fieldsEnd;i++) {
        printf("%s - %d\n",fields[i].fieldName,fields[i].ticketPos);
    }

    for (int i = 0; i < FIELDS_COUNT; i++) {
        printf("%d ",myTix[i]);
    }
    printf("\n");

    findMySums();

    return 0;
}

void checkFields(){
    for (int i = 0; i < fieldsEnd; i++) {
        if (fields[i].onesCount == 1) {
            for (int j = 0; j < FIELDS_COUNT; j++) {
                if (fields[i].position[j] == 1) {
                    fields[i].ticketPos = j;
                    zeroOutField(j);
                    fields[i].onesCount = -2;
                    i = -1;
                    break;
                }
            }
        }
    }
}

void zeroOutField(int pos) {
    for (int i = 0; i < fieldsEnd; i++) {
        fields[i].onesCount--;
        fields[i].position[pos] = 0;
    }
}

void findMySums(){
    long mySum = 1;
    for (int i = 0; i < fieldsEnd; i++) {
        if (strstr(fields[i].fieldName,"departure")) {
            mySum = mySum * myTix[fields[i].ticketPos];
        }
    }
    printf("Your sum is %ld\n",mySum);
}