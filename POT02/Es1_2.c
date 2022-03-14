#include <stdio.h>

int main (void){
    int secondi;
    printf("Inserisci numero di secondi: ");
    scanf("%d", &secondi);
    int hh = secondi / 3600;
    int mm = (secondi % 3600) / 60;
    int ss = (secondi % 3600) % 60;
    printf ("%02d:%02d:%02d\n", hh, mm, ss); // domanda: cosa fa %02d? come saperlo?
    return 0;
}