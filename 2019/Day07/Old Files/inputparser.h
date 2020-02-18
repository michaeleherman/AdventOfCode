#ifndef inputparser_h
#define inputparser_h

typedef struct opcodes {
    int *intcodes;
    int size;
} opcodes;


#endif

struct opcodes parse(char *str);
