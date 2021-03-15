#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS 36

int main() {

    // char mask[36] = "0X0X1110X1010X1X10010X0011010X100110";
    char mask[36] = "000000000000000000000000000000000001";
    int binary[36];
    memset(binary, 0, sizeof(int) * 36);
    

    unsigned int N = 23031023;
    unsigned int dividend;


    // printf("%llu", (N.value >> 4) & 0x1);
    // exit(0);

    int i = 0;
    while ( N > 0) {
        binary[i] = N % 2;
        printf ("%d ",N % 2);
        N = N /2;
        i++;
    }
    printf("\n");

    

    for (int i = 35; i>=0;--i) {
        printf("%d ",binary[i]);
    }
    printf("\n");
    return 0;
}