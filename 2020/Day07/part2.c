#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define myBag "shiny gold"
#define lines 600
#define chunkSize 512
#define bagSize 64

struct chunksStruct {
    char chunksArray[lines][chunkSize];
    int end;
    int priorBagCount;
    int totalBagsHeld;
};

int recurse(char chunk[chunkSize]);
char * extractExteriorBag(char chunk[64]);
int splitBags(char insideBags[chunkSize]);

char chunk[chunkSize];
struct chunksStruct chunks;
int branchTotal;

int depth;
int lastBagCount;
int multiplier[10];
char bagChain[10][64];


int main() {
    chunks.end = 0;
    chunks.totalBagsHeld = 0;
    depth = 0;
    lastBagCount = 0;
    multiplier[0] = 1;
    
    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day07/data.txt","r");


    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }


    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (chunk[strlen(chunk) -1]== '\n') {
            chunk[strlen(chunk) -1] = '\0';
        }
       
        strcpy(chunks.chunksArray[chunks.end],chunk);
        chunks.end++;
    


    }
    
    recurse(myBag);
    

//    for (int i = 0; i < chunks.end; i++) {
//        printf("%s\n",chunks.chunksArray[i]);
//    }
//
//    printf("Number of bags is: %d\n", chunks.end);
    printf("THe number you are looking for is: %d\n", branchTotal);


        

return 0;
            
}

int recurse(char bag[bagSize]){
//    printf("recursing for %s\n",bag);
    for (int i = 0; i < chunks.end; i++) {
        char exteriorBag[bagSize];
        char insideBags[chunkSize];
        strcpy(exteriorBag, extractExteriorBag(chunks.chunksArray[i]));
        strcpy(bagChain[depth],exteriorBag);
//        for (int j = 0; j <= depth; j++) {
//            printf("%d      ", depth);
//            printf("%s ", exteriorBag);
//        }
        if (strcmp(exteriorBag, bag) == 0) {
            strcpy(insideBags,strstr(chunks.chunksArray[i],"contain"));
            if (strcmp(insideBags,"contain no other bags.") == 0){
                chunks.priorBagCount = 0;
//                printf("returning from recursion of %s\n", exteriorBag);
                return 0;
            }
            splitBags(insideBags);
        }
    }
    multiplier[depth] = 0;
    multiplier[0] = 1;
    depth--;
    return 0;
}

char * extractExteriorBag(char chunk[64]){
    static char exteriorBag[bagSize],tmp1[25], tmp2[25];
    sscanf(chunk,"%s %s", tmp1, tmp2);
    sprintf(exteriorBag, "%s %s",tmp1,tmp2);
    return exteriorBag;
}

int splitBags(char insideBags[chunkSize]){
    depth++;
    int counter = 0;
    struct bagStruct {
        char bag[64];
        int count;
    };
    
    struct bagStruct bagArr[10];
    
    char *token;
    const char delim[2] = ",";
    token = strtok(insideBags, delim);
    
    int heldBags;
    char bag[bagSize], tmp1[bagSize], tmp2[bagSize];
    sscanf(insideBags,"%*s %d %s %s",&heldBags,tmp1,tmp2);
    sprintf(bag,"%s %s", tmp1, tmp2);
    strcpy(bagArr[counter].bag,bag);
    bagArr[counter].count = heldBags;
    counter++;


    while ( token != NULL ) {
        token = strtok(NULL, delim);
        if ( token == NULL ) {
            break;
        }
        
        sscanf(token,"%d %s %s",&heldBags,tmp1,tmp2);
        sprintf(bag,"%s %s", tmp1, tmp2);

        strcpy(bagArr[counter].bag,bag);
        
        bagArr[counter].count = heldBags;
        counter++;
    }
    

    

    for (int i = 0; i < counter; i++) {

        multiplier[depth] = multiplier[depth-1] * bagArr[i].count;

        if (depth == 1 && i == 0) {
            branchTotal = bagArr[i].count + branchTotal;
        } else {
            branchTotal = branchTotal + (multiplier[depth]);
        }

//        printf("processing bag %s\n",bagArr[i].bag);
        lastBagCount = multiplier[i-1] + multiplier[i];
        recurse(bagArr[i].bag);
    }

    strcpy(bagChain[depth]," ");


    
    return 0;
}
