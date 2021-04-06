#include <stdio.h>
#include <stdio.h>
#include <time.h>



const size_t TURNS = 30000000;
unsigned int seen[TURNS];

const unsigned int game[] = {7,12,1,0,16,2};
const size_t gamesize = sizeof(game) / sizeof(unsigned int);

clock_t start, end;
double cpu_time_used;

int main() {
    start = clock();
    unsigned i, j, lastnum = game[gamesize - 1];
    
    for (int i = 0; i < TURNS; i++) {
        seen[i] = 0;
    }
    
    i = 1;
    while (i < gamesize) {
        seen[game[i - 1]] = i;
        ++i;
    }
    
    while (i < TURNS) {
        j = seen[lastnum];
        seen[lastnum] = i;
        lastnum = j ? i - j : 0;
        ++i;
    }
    
    printf("lastnum %u\n", lastnum);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("execution time %f\n",cpu_time_used);
    return 0;
}
