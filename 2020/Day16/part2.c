#include "part2.h"

extern _field fields[ARRAYSIZE];

int main(void)
{
    int validEnd = part1();
    printf("valid end is %d\n", validEnd);

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
                    printf("position %d invalid for %s\n", j, fields[i].fieldName);
                    break;
                }
            }
            if (valid == true)
            {
                printf("position %d valid for %s\n", j, fields[i].fieldName);
            }
        }
    }

    for (int k = 0; k < fieldsEnd; ++k)
    {
        printf("%s,", fields[k].fieldName);
        for (int i = 0; i < FIELDS_COUNT; ++i)
        {
            printf("%2d,", fields[k].position[i]);
        }
        printf("\n");
    }

    return 0;
}

// int checkFields(int field, int value)
// {
//     for (int i = 0; i < fieldsEnd; i++)
//     {
//         printf("Checking field %s for value %d - ", fields[i].fieldName,
//         value); if ((value >= fields[i].start1 && value <= fields[i].end1) ||
//         (value >= fields[i].start2 && value <= fields[i].end2))
//         {
//             valid = true;
//             printf("valid\n");
//         }
//         else
//         {
//             valid = false;
//             printf("invalid\n");
//             break;
//         }
//     }
//     return valid;
// }
