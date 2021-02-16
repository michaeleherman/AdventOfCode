#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define aLength 26
#define start 97



int main() {

    FILE *fp = fopen("/Users/michael/Code/AdventOfCode/2020/Day06/data.txt", "r");
    if (fp == NULL) {
        perror("error opening file");
        return(-1);
    }

    char chunk[64];
    int answers[start + aLength];
    memset(answers, 0, (start + aLength) *sizeof(int));
    int answerCount = 0;
    int totalAnswers = 0;
    int recordCount = 0;
    int people = 0;

    while (fgets(chunk, sizeof(chunk), fp) != NULL) {
        if (chunk[0] == '\n') {
            recordCount++;
            for (int i = start; i < start + aLength;i++) {
                if (answers[i] == people) {
                    answerCount++;
                }
            }
            totalAnswers = totalAnswers + answerCount;
            printf("Record: %d AnswerCount: %d Totals: %d\n", recordCount, answerCount, totalAnswers);
            answerCount = 0;
            memset(answers, 0, (start + aLength) *sizeof(int));
            people = 0;
            continue;
        }
        chunk[strlen(chunk) -1] = '\0';
        people++;
        for (int i = 0; i < strlen(chunk); i++) {
            int ascii = chunk[i];
            answers[ascii]++;
            // if (answers[ascii] == 0 ) {
            //     answers[ascii] = 1;
            // }
        }
    }
    printf("total: %d\n", totalAnswers);

    return 0;
}
