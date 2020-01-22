typedef struct planets {
    char *planet;
    char *direct;
} s_planets;

typedef struct planetsStruct {
    struct planets *planets;
    int planetsSize;

} r_planets;

r_planets readFile ();