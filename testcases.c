#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define R 5
#define C 4

void testsForDinner() {
    int matrix[R][C];

    FILE *ptr;

    ptr = fopen("./tests.txt", "a");

    if (ptr == NULL) {
        printf("Error!");
        exit(1);
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            matrix[i][j] = rand() % 5 + 1;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fprintf(ptr, "%d ", matrix[i][j]);
        }
        fprintf(ptr, "\n", matrix[i]);
    }

    fprintf(ptr, "--------------\n", matrix);
    fclose(ptr);
}

int main() {
    srand((unsigned) time(NULL));
    for (int i = 0; i < 10; i++) {
        testsForDinner();
    }
}
