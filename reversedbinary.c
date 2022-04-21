#include <stdio.h>

void mein(int number) {
    int mod, binary[32], result, multi = 1;
    int i = 0;
    while (number) {
        mod = number % 2;
        binary[i] = mod;
        number /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        result += binary[j] * multi;
        multi *= 2;
    }
    printf("Moje: %d ", result);
}

void internet(int number) {
    int result = 0;
    if (number != 0) {
        while (number != 0) {
            result = (result << 1) + (number & 1);
            number >>= 1;
        }
    }
    printf("Internet: %d\n", result);

}

int main() {

    int number;
    scanf("%d", &number);
    printf("%d", number);
    return 0;
}
