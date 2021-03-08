#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define chunkLength 250
#define DELAY(ts) (timeStamp % ts)

enum DISCOVER {NOTFOUND, FOUND};

struct bus {
    int busNo;
    int position;
};

struct bus *buses;

int checkDeparture(int timestamp, struct bus *buses, int pos);
int mul_inv(int a, int b);
int chinese_remainder(int *n, int *a, int len);

int main() {
    
    buses = malloc(sizeof(struct bus));
    int end = 0;
    int counter = 0;
    int tokenCount = 0;
    char sep[2] = ",";
    char chunk[chunkLength];
    long long timeStamp = 1;
    FILE *fp = fopen("/Users/michael.herman/Code/AdventOfCode/2020/Day13/data.txt","r");
    
    
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }
    
    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        chunk[strcspn(chunk, "\n")] = 0;
        if (counter == 0) {
            //            timeStamp = atoi(chunk);
            counter++;
            continue;
        }
        char *token = strtok(chunk,sep);
        
        
        while (token != NULL) {
            if (strcmp(token,"x") != 0) {
                buses[end].busNo = atoi(token);
                buses[end].position = tokenCount;
                buses = realloc(buses,sizeof(struct bus) * (end + 2));
                end++;
            }
            tokenCount++;
            token = strtok(NULL,sep);
        }
    }
    int discovered = NOTFOUND;
    timeStamp = 100000000000000;
    int offset = buses[0].busNo;
    while (discovered == NOTFOUND){
        for (int i = 0;i < end; i++) {
            long long tmpTs = timeStamp + buses[i].position;
//            int offset = (tmpTs) % buses[i].busNo;
            printf("timestamp %lld - current bus %d delay %d\n",tmpTs,buses[i].busNo, offset);
            if (offset != 0) {
                break;
            } else {

//                printf("current bus %d current timestamp %lld\n",buses[i].busNo, tmpTs);
                if (i == end - 1) {
                    printf("found it - timestamp %lld\n\n",timeStamp);
                    discovered = FOUND;
                    break;
                }
            }
        }

        if (discovered == FOUND ){
            exit(0);
        } else {
            timeStamp++;
        }

        
    }
    
    
    
    return 0;
    
}

int mul_inv(int a, int b)
{
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}
 
int chinese_remainder(int *n, int *a, int len)
{
    int p, i, prod = 1, sum = 0;
 
    for (i = 0; i < len; i++) prod *= n[i];
 
    for (i = 0; i < len; i++) {
        p = prod / n[i];
        sum += a[i] * mul_inv(p, n[i]) * p;
    }
 
    return sum % prod;
}


//t = (buses[i].busNo - buses[i].position) % buses[i].busno]


//def chinese_remainder(n, a):
//    sum = 0
//    prod = reduce(lambda a, b: a*b, n)
//    for n_i, a_i in zip(n, a):
//        p = prod // n_i
//        sum += a_i * mul_inv(p, n_i) * p
//    return sum % prod
//
//
//def mul_inv(a, b):
//    b0 = b
//    x0, x1 = 0, 1
//    if b == 1: return 1
//    while a > 1:
//        q = a // b
//        a, b = b, a%b
//        x0, x1 = x1 - q * x0, x0
//    if x1 < 0: x1 += b0
//    return x1
