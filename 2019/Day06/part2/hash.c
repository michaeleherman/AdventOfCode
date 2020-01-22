#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char *str) {

    int hash = 13;

    for (int i = 0;i < strlen(str);i++) {
        hash = hash * 31 + str[i];
        printf("%d\n", hash);
    }

    return hash;
}


// char *unhash() {

// }