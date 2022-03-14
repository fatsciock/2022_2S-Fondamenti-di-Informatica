#include <stdio.h>

int main (void) {
    float prezzo;
    unsigned int sconto;
    printf("Inserisci il prezzo originale: ");
    scanf ("%f", &prezzo);
    printf("Inserisci lo sconto percentuale: ");
    scanf("%u", &sconto);
    printf("Prezzo originale: %.2f euro\n", prezzo);
    printf("Sconto: %.2f euro\n", prezzo / 100 * sconto);
    printf("Prezzo scontato: %.2f euro\n", prezzo - prezzo / 100 * sconto);
    return 0;
}