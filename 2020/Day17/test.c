#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int ***test;
    int x = 3;
    int y = 2;
    int z = 3;
    int value = 1;
    test = (int ***) malloc(x * sizeof(int**));
    for (int i = 0; i < x;i++ ) {
        test[i] = (int**) malloc(sizeof(int*) * y);
        for (int j = 0; j < y;j++) {
            test[i][j] = (int*) malloc(sizeof(int) * z);
            for (int k = 0; k < z;k++) {
                test[i][j][k] = value;
                value++;
            }
        }
    }


    for (int i = 0; i < x;i++) {
        for (int j = 0; j < y;j++) {
            for (int k = 0; k < z;k++) {
                printf("%d-%d-%d %d\n   ",i, j, k,test[i][j][k]);
            }
        }
    }

    return 0;
}