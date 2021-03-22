#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS 36

int main() {

    // char mask[36] = "0X0X1110X1010X1X10010X0011010X100110";
    char mask[36] = "00000000000000000000000000000000X0XX";
    int binary[36];
    memset(binary, 0, sizeof(int) * 36);
    int maskArr[36];
    int xPos[36];
    memset(xPos, -1,sizeof(int) * 36);


    for (int i = 0;i < 36; i++) {
        if (mask[i] == '1') {
            maskArr[i] = 1;
        } else if (mask[i] == '0') {
            maskArr[i] = 0;
        } else {
            xPos[i] = 0;
            maskArr[i] = mask[i];
        }
    }

    for (int i = 0; i < 36; i++) {
        printf("%d ",xPos[i]);
    }
    printf("\n");



    for (int i = 0; i < 36; i++) {
        printf("%d",maskArr[i]);
    }
    printf("\n");
    return 0;
}