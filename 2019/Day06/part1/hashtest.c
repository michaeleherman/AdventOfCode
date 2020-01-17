
#include <stdio.h>
#include <stdlib.h>

unsigned long hash(const char *str, unsigned int length);

int main() {

    char * planet = "ABCD";
    long value = hash(planet,5);

    printf("value is: %lu",value);

    return 0;
}


unsigned long hash(const char* str, unsigned int length)
{
   unsigned int hash = 5381;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = ((hash << 5) + hash) + (*str);
   }

   return hash;
}