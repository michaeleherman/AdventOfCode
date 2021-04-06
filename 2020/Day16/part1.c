#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define CHUNK_SIZE 250
#define FIELDS_COUNT 3
#define VALUES_COUNT 2

struct field {
    char fieldName[50];
    int startA;
    int endA;
    int startB;
    int endB;
};

struct field fields[FIELDS_COUNT * VALUES_COUNT];

int main(void){

    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day16/test.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    char chunk[CHUNK_SIZE];
    int end = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (end == FIELDS_COUNT) {
            break;
        }
        char field[25];
        int a, b, c, d;
        sscanf(chunk,"%s %d-%d or %d-%d",field,&a,&b,&c,&d);
        field[strlen(field) -1] = '\0';
        strcpy(fields[end].fieldName,field);
        fields[end].startA = a;
        fields[end].endA = b;
        fields[end].startB = c;
        fields[end].endB = d;
        printf ("field - %s %d %d %d %d\n",fields[end].fieldName,fields[end].startA,fields[end].endA,fields[end].startB,fields[end].endB);
        ++end;


    }

    bool process = false;
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (strstr(chunk,"nearby tickets")) {
            process = true;
            continue;
        }

        if (process == true) {

        }

    }
  
    return 0;

}

void test (int code, int end) {
    int i;
    for (i = 0; i < end; i++) {
        if ( code < i ) {}
    }
}