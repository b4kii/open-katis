#include <stdio.h>

int main() {
    int n, h, v, width = 4;
    scanf("%d %d %d", &n, &h, &v);

    int firstPiece, secondPiece, thirdPiece, fourthPiece;

    firstPiece = h * v * width;
    secondPiece = (n - v)  * h * width;
    thirdPiece = (n - h) * v * width;
    fourthPiece = (n - h) * (n - v) * width;

    int max = firstPiece;

    if (secondPiece > max) {
        max = secondPiece;
    }
    if (thirdPiece > max) {
        max = thirdPiece;
    }
    if (fourthPiece > max) {
        max = fourthPiece;
    }

    printf("%d\n", max);
    // printf("%d %d %d %d\n", firstPiece, secondPiece, thirdPiece, fourthPiece);

    return 0;
}
