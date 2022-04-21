#include <stdio.h>

#define R 5
#define C 4

int main() {
    int summedPoints[5], points[4];

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            scanf("%d", &points[j]);
            sum += points[j];
        }
        summedPoints[i] = sum;
        // printf("%d %d\n", summedPoints[i], i + 1);
    }

    int max = summedPoints[0];
    int winner = 1;

    for (int i = 1; i < 5; i++) {
        if (summedPoints[i] > max) {
            max = summedPoints[i];
            winner = i + 1;
        }
    }

    printf("%d %d\n", winner, max);

    return 0;
}