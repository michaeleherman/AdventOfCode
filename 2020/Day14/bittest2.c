#include <stdio.h>
#include <stdlib.h>

#define BITS 36

struct number {
    long long value:36;
};

int main() {

    // char mask[36] = "0X0X1110X1010X1X10010X0011010X100110";
    char mask[36] = "000000000000000000000000000000000001";

    struct number N;

    N.value = 23031023;

    // printf("%llu", (N.value >> 4) & 0x1);
    // exit(0);

    for (int i = 0; i < BITS; i++) {
        // int inverse = 35 -i;

        int bit = (N.value >> i) & 0x1;
        int maskPos = abs(i - BITS+1);
        printf("%d %d %llu original bit %d  - bit 0 %llu - ", i, maskPos,N.value,bit,(N.value >> 0) & 0x1);
        // if ( i % 4 == 0) {
        //     printf(" ");
        // }
        // printf("%d %d ",i,bit);

        if (mask[maskPos] == '1') {
            // printf("found 1 ");
            N.value |= 1ULL << i;
        } else if (mask[maskPos] == '0' ) {
            // printf("found 0 ");
            N.value &= ~(1ULL << i);
        } else {
            // printf("found x %llu\n",N.value & (1 << i));
            
        }
        printf(" changed bit %llu \n",(N.value >> i) & 0x1);
    }
    printf("\n");



    for (int i = 0; i < 36; i++) {
        long long unsigned maskPos = abs (i - BITS + 1);
        long long unsigned bit = (N.value >> maskPos) & 0x1;
        if ( i % 4 == 0) {
            printf(" ");
        }
        printf("%llu",bit);


    }
    printf("\n");
    printf("%llu\n",N.value);



    return 0;
}
