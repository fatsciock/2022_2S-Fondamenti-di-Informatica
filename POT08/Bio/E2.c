#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int array_equals(int a[], int b[], int size);
void print_array(int *a, int size);

/*
Realizzare la funzione f qui sotto riportata, che dati in ingresso una stringa
s, un array di caratteri c e la sua dimensione n, crea e torna in uscita una
nuova stringa ottenuta da s sostituendo ogni carattere presente in c con il
carattere '0'.

Come riferimento si consideri che l'esecuzione del test
(eseguita dal metodo main) deve riportare il risultato true.
*/

char *f(char *s, char c[], int n) {
    // TODO
}

int test() {
    // Test 1
    char s1[] = "Onorarono";
    char c1[] = {'o', 'r'};
    int n1 = 2;
    char o1[] = "On00a00n0";
    // Test 2
    char s2[] = "Onorarono";
    char c2[] = {'o'};
    int n2 = 1;
    char o2[] = "On0rar0n0";
    // Test 3
    char s3[] = "Onorarono";
    char c3[] = {'O', 'r', 'n'};
    int n3 = 3;
    char o3[] = "00o0a0o0o";
    // Test 4
    char s4[] = "aaabbccc";
    char c4[] = {'a', 'c', 'd'};
    int n4 = 2;
    char o4[] = "000bb000";

    return strcmp(f(s1, c1, n1), o1) == 0 && // strcmp restituisce 0 se le due stringhe sono uguali
           strcmp(f(s2, c2, n2), o2) == 0 &&
           strcmp(f(s3, c3, n3), o3) == 0 && strcmp(f(s4, c4, n4), o4) == 0;
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
