#include <stdio.h>

int main(void) {
    int n;
    printf("Inserisci un numero intero: ");
    scanf("%d", &n);
    int av = n >= 0 ? n : -n;
    printf("Valore assoluto: %d\n", av);
    printf("Nota: %u ; %d\n", n, (unsigned int)n);
    return 0;
}