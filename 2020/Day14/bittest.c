#include <stdlib.h>
#include <stdio.h>

int main() {

    uint8_t a = 0x1;
    uint8_t b = 0x3;

    printf("%d %d\n",a,b);

    // for (int i = 7;i >= 0; i--) {
    //     // ((BF >> N) & 0x1)
    //     int bit = ((a >> i) & 0x1);
    //     printf("%d",bit);
    // }
    // printf("\n");
    // for (int i = 7;i >= 0; i--) {
    //     // ((BF >> N) & 0x1)
    //     int bit = ((b >> i) & 0x1);
    //     printf("%d",bit);
    // }
    printf("\n");
    for (int j = 0;j < 4;j++) {
        b = + ~ b;
        printf("%d - %d - ",j,b);
        for (int i = 7;i >= 0; i--) {
        // ((BF >> N) & 0x1)
        int bit = ((b >> i) & 0x1);
        printf("%d",bit);
         }
         printf("\n");
    }
    return 0;

}