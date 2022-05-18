/* E1.c */
#include <stdio.h>
#include <stdlib.h>

/* FUNZIONE DA REALIZZARE
   ======================

   Realizzare la funzione monete(c) seguente. La funzione accetta
   come parametro un intero c che e' garantito essere strettamente
   maggiore di zero, e che rappresenta una somma di denaro espressa in
   centesimi di euro. La funzione deve restituire IL MINIMO NUMERO DI
   MONETE necessarie per erogare c centesimi di euro, supponendo di
   disporre unicamente di monete da 1, 2, 5, 10, 20, 50 centesimi. Si
   assuma di avere un numero illimitato di monete di ciascun taglio.

   Alcuni esempi:

   - monete(3) restituisce 2, perche' servono due monete (2 + 1).

   - monete(10) restituisce 1, perche' basta una singola moneta da 10c
     per erogare un importo di 10 centesimi;

   - monete(34) restituisce 4, perche' servono quattro monete
     (20 + 10 + 2 + 2)

   - monete(137) restituisce 6, perche' servono sei monete
     (50 + 50 + 20 + 10 + 5 + 2)

   Per risolvere il problema correttamente e' necessario iniziare
   usando le monete di valore massimo (50 centesimi) fino a quando
   possibile; poi si passa a quelle da 20 centesimi e via via a quelle
   di taglio inferiore fino a quando l'intero importo c e' stato
   erogato.
*/
int monete(int c) {
    // TODO
}

void test(int c, int expect) {
    int v = monete(c);
    printf("c=%5d -- ", c);
    if (v == expect) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: risultato atteso %d, risultato ottenuto %d\n", expect, v);
    }
}

int main(void) {
    test(1, 1);
    test(2, 1);
    test(3, 2);
    test(4, 2);
    test(5, 1);
    test(10, 1);
    test(20, 1);
    test(34, 4);
    test(50, 1);
    test(100, 2);
    test(137, 6);
    test(471, 11);  /* 9*50c + 1*20c + 1*1c */
    test(1679, 37); /* 33*50c + 1*20c + 1*5c + 2*2c */
    return 0;
}
