typedef struct opcodes {
    int *intcodes;
    int size;
} opcodes;

struct opcodes parse(char *str);