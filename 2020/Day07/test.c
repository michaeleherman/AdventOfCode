#include <stdio.h>
#include <stdlib.h>
#include <string.h>




struct bag {
    char kind[64];
    int count;
    struct bag *next;
};


int main() {

    char chunk[200] = "shiny gold bags contain 3 wavy gold bags, 2 plaid chartreuse bags, 2 shiny lime bags, 5 dull indigo bags.";
    char inside[200];

    struct bag head;
    
    strcpy(inside,strstr(chunk,"contain")+strlen("contain "));

    char *token;
    char delim[2] = ",";
    token = strtok(inside,delim);
    char tmp1[25], tmp2[25]
    sscanf(token,"%d %s %s",)

    while (token != NULL) {
        printf("token - %s\n", token);
        token = strtok(NULL,delim);
    }



    return 0;
}

