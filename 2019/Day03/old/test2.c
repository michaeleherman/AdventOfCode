#include "get_wire_array.h"


int main()
{
    char wire[] = "R75,D30,R83,U83,L12,D49,R71,U7,L72";
    struct wireArrayStruct wireArray;

    wireArray = getWireArray(wire);

    printf("test back from function\n");

    for (int i = 0; i < wireArray.counter; i++)
    {
        printf("returned values %d, %s\n", i, wireArray.tmpArray[i]);
    }
}



