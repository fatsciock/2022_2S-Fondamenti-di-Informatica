#include <stdio.h>

int main(void) {
    int d;
    float f;
    int n = scanf("Numeri: %d\n\n%f", &d, &f);
    printf("Numero di variabili correttamente assegnate: %d\n", n);
    printf("L utente ha inserito d=%d e f=%f\n", d, f);
    printf("Nuova d: ");
    n = scanf("%d\n", &d);
    printf("Numero di variabili correttamente assegnate: %d\n", n);
    n ? printf("L utente ha sovrascritto d con il valore %d\n", d) : 0;
    return 0;
}