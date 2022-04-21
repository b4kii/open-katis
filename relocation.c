#include <stdio.h>

int main () {
    int companiesCount = 0, requestsCount = 0, request = 0, req1 = 0, req2 = 0, count = 0;

    scanf("%d %d", &companiesCount, &requestsCount);

    int locations[companiesCount];
    int output[companiesCount];

    for (int i = 1; i <= companiesCount; i++) {
        scanf("%d", &locations[i]);
    }

    for (int i = 0; i < requestsCount; i++) {
        scanf("%d %d %d", &request, &req1, &req2);
        switch(request) {
        case 1:
            locations[req1] = req2;
            break;
        case 2:
            output[count] = locations[req1] - locations[req2];
            if (output[count] < 0) 
                output[count] *= (-1);
            count++;
            break;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", output[i]);
    }

    return 0;
}