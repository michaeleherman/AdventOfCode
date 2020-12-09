#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// #define FOREACH_FRUIT(FRUIT) \
//     FRUIT(apple) \
//     FRUIT(pear) \
//     FRUIT(grape) \
//     FRUIT(banana) \

// #define GENERATE_ENUM(ENUM) ENUM,
// #define GENERATE_STRING(STRING) #STRING,

// enum FRUIT_ENUM {
//     FOREACH_FRUIT(GENERATE_ENUM)
// };

// static const char *FRUIT_STRING[] = {
//     FOREACH_FRUIT(GENERATE_STRING)
// };

enum FRUIT_ENUM {
    apple, orange, grape, banana,
};

static const char *fruitString[] = {
    "apple", "orange", "grape", "banana",
};

int main (void) {

    char *testFruit = "apple";

    printf("enum apple as int: %d\n", apple);
    printf("enum apple as string: %s\n", fruitString[apple]);



    return 0;
}