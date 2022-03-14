#include <stdio.h>

int main(void) {
    int mese;
    printf("Si inserisca un mese (1 -12): ");
    scanf("%d", &mese);
    printf("Il mese indicato ha %d giorni.\n",
        mese == 2 ? 28 : 
        mese == 4 || mese == 6 || mese == 9 || mese == 11 ? 30 : 31);
    return 0;
}