#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ((BF >> N) & 0x1)

int main(void){

    unsigned int x = 1680;

    for ( int i = 0; i < 31; i++) {
        printf("%d",x >> i & 0x1);
    }
    printf("\n");

    x = 7; 

    for ( int i = 0; i < 31; i++) {
        printf("%d",x >> i & 0x1);
    }
    printf("\n");


    return 0;

}