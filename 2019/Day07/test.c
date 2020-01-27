#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int c[5] = {0,0,0,0,0};
    int i = 1;
    int k,p;

    printf("i modulo 2 is %d\n", i % 2);

    if (i%2 && c[i] == true){
        printf("i is %d\n",i);
    } else {
        printf("not true");
    }
}