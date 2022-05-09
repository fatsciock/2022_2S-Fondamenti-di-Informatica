#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int array_equals(int a[], int b[], int size);
void print_array(int *a, int size);

/*
 Realizzare la funzione f qui sotto riportata, che presi in ingresso due
 stringhe 'a' e 'b', riconosce se 'a' contiene da sinistra a destra
 occorrenze di tutti gli elementi di 'b' nell'ordine in cui compaiono in b
 (ossia prima b[0], poi b[1], etc..).

 Come riferimento si consideri che l'esecuzione del test
 (eseguita dal metodo main) deve riportare il risultato true.
*/

int f(char *a, char *b) {
    int i, j;
    for (i = 0, j = 0; a[i] && b[j]; i++) {
        if (a[i] == b[j]) {
            j++;
        }
    }
    return !b[j];
}

int test() {
    return f("prova", "pva") && f("prova", "prova") && f("prova", "r") &&
           f("prova", "pa") && f("prova", "") && !f("", "r") &&
           !f("prova", "ppv") && !f("prova", "roz") && !f("prova", "provare");
}

int main() {
    printf("%s\n", test() ? "true" : "false");
    return 0;
}

int array_equals(int a[], int b[], int size) {
    for (; size--;)
        if (a[size] != b[size])
            return FALSE;
    return TRUE;
}

void print_array(int *a, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("/n");
}
