#include <stdio.h>

int main() {
    int t, n;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int position[n];
        int min, max;
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &position[j]);
        }

        max = position[0];
        min = position[0];
        for (int k = 0; k < n; k++) {
            if (position[k] > max) 
                max = position[k];
            if (position[k] < min)
                min = position[k];
        }
        printf("%d\n", (max - min) * 2);
    }
    return 0;
}