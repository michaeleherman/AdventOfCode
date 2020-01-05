#include <stdio.h>
#include <stdlib.h>

typedef struct planet {
    char  *planet;
    struct planet *child;
} planet;

int main () {

    planet *head = NULL;
    head = malloc(sizeof(planet));
    head->planet = "COM";
    head->child = malloc(sizeof(planet));
    head->child->planet = "B";
    head->child->child = NULL;
    head->child->child = malloc(sizeof(planet));
    head->child->child->planet = "C";
    head->child->child->child = NULL;

    printf("head mem loc: %p\n", &head);
    printf("child mem loc: %p\n", &head->child);

    planet *current = head;
    while (current != NULL) {
        printf("%s\n", current->planet);
        current = current->child;
    }



    return 0;
}