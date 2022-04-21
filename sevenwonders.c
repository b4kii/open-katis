#include <stdio.h>

int main () {
    char input[50];
    scanf("%s", input);

    int i = 0, count_t = 0, count_c = 0, count_g = 0, score, set = 0;
    while (input[i]) {
        switch (input[i]) {
            case 'T':
                count_t++;
                break;
            case 'C':
                count_c++;
                break;
            case 'G':
                count_g++;
                break;
        }
        i++;
    }
    
    int t = count_t;
    int c = count_c;
    int g = count_g;
    while (t > 0 && c > 0 && g > 0) {
        set++;
        t--;
        c--;
        g--;
    }
    if (set > 0) {
        set *= 7;
    }
    score = (count_t * count_t) + (count_c * count_c) + (count_g * count_g) + set;
    printf("%d", score);

    return 0;
}
