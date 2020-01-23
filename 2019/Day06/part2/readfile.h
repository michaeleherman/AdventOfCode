#ifndef readfile_planets
#define readfile_planets
typedef struct planets {
    char *planet;
    char *direct;
} s_planets;

typedef struct planetsStruct {
    struct planets *planets;
    int planetsSize;

} r_planets;

#endif

r_planets readFile();