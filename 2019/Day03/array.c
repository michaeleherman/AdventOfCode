#include <math.h>

int main(int argc, const char *argv[])
{
    int **array;
    
    array = malloc(sizeof(int));
    
    for (int i = 0; i < 5; i++) {
        array[i] = malloc(5 * sizeof(int));
        for (int j = 0; j < 5; j++) {
            array[j] = malloc(5 * sizeof(int));
            array[i][j] = (i * 20) + (j*3);
            printf("%d, %d %d\n",i,j,array[i][j]);
        }
    }
    

    
    return 0;
}

