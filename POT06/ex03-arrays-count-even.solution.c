/* somma_pari.c */
#include <stdio.h>

/**
 * evens(a[], size) restituisce il numero di valori pari presenti
 * nell'array a[] di lunghezza size>=0. Se l'array e' vuoto il
 * risultato e' zero. La soluzione e' ricorsiva e basata sullo schema
 * seguente:
 *
 *                  / 0                    se size <= 0;
 * evens(a, size) = | 1 + evens(a, size-1) se a[size-1] e' pari;
 *                  \ evens(a, size-1)     se a[size-1] e' dispari;
 *
 * Si noti che ad ogni chiamata viene "consumato" l'ultimo elemento di
 * a[] e la ricorsione avviene sull'array composto dai primi (size-1)
 * elementi.  naturalmente altri schemi erano ugualmente possibili, ad
 * esempio consumando il primo elemento anziche' l'ultimo.
 */
int evens(int a[], int size) {
    if (size <= 0) {
        return 0; /* caso base: array vuoto */
    } else {
        if (a[size - 1] % 2 == 0) {
            return 1 + evens(a, size - 1);
        } else {
            return evens(a, size - 1);
        }
    }
}

int main(void) {
    int x[] = {10, 20, 30, 40, 50};
    int y[] = {1, 3, 5, 9, 11};
    int z[] = {1, 2, 3, 4, 5, 6};

    printf("in x ci sono %d numeri pari \n", evens(x, 5));
    printf("in y ci sono %d numeri pari \n", evens(y, 5));
    printf("in z ci sono %d numeri pari \n", evens(z, 6));

    return 0;
}
