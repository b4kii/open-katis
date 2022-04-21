#include <stdio.h>

int main() {
    int money = 0, copper = 0, silver = 0, gold = 0;
    int copperBp = 1, silverBp = 2, goldBp = 3;
    scanf("%d %d %d", &gold, &silver, &copper);
     
    if (copper + silver + gold <= 5) {
        money = (copperBp * copper) + (silverBp * silver) + (goldBp * gold); 
        if (money >= 0 && money <= 1) {
            printf("Copper\n");
        }
        if (money == 2) {
            printf("Estate or Copper\n") ;
        }
        if (money >= 3 && money <= 4) {
            printf("Estate or Silver\n");
        }
        if (money == 5) {
            printf("Duchy or Silver\n");
        }
        if (money >= 6 && money <= 7) {
            printf("Duchy or Gold\n");
        }
        if (money >= 8) {
            printf("Province or Gold\n");
        }
    }

    return 0;
}
