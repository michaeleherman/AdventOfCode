#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int massCalc(int mass);

int main(void) {
    FILE *fp = fopen("data.txt","r");
    
    char chunk[128];

    int mass=0; 
    long long totalMass=0;

//Loop through file
    while(fgets(chunk, sizeof(chunk),  fp)!= NULL) {
        fputs(chunk, stdout);
        mass = strtol(chunk,NULL,10);
        while (mass>0) {
            mass = massCalc(mass);                          //Calculate Mass
            totalMass += mass;                              //Increment total mass
            printf("mass is %d\n", mass);
            printf("Total mass is %lli\n", totalMass);  
        }
    }

    fclose(fp);
    printf("Total mass is %lli\n", totalMass);
}

int massCalc(int mass) {
    int localMass = floor(mass/3)-2;
    if (localMass < 1)
        return 0;
    else
        return localMass;
}