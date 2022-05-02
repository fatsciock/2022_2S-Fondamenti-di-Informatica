/* palindrome.c */
#include <stdio.h>
#include <stdlib.h>

void print_array(const int v[], int n);

/* Funzione ricorsiva che riempie opportunamente la porzione di array
   a[i..j] compresa tra gli indici i e j inclusi */
void palindrome_ric(int a[], int i, int j) {
    if (i > j) {
        return; /* caso base: array vuoto */
    } else {
        const int v = (j - i) / 2;
        a[i] = v;
        a[j] = v;
        palindrome_ric(a, i + 1, j - 1);
    }
}

/* Un punto non banale della funzione precedente consiste nel calcolo
   del valore da scivere in a[i] e a[j], in modo che al termine della
   ricorsione l'array contenga {n, n-1, n-2, ..., 1, 0, 1, ... n-2,
   n-1, n}.  Se non si riesce a scoprire che il valore scritto in a[i]
   e a[j] e' proprio (j-i)/2, si puo' ricorrere ad una versione
   leggermente diversa della funzione, in cui si passa come ulteriore
   parametro il valore v da scrivere. Ad ogni chiamata ricorsiva verso
   "l'interno", il valore da scrivere diminuisce di uno.

   Per provare questa versione e' necessario modificare la funzione
   palindrome() riportata sotto (quella che innesca la ricorsione)
   sostituendo alla riga:

   palindrome_ric(r, 0, 2*n);

   la riga:

   palindrome_ric2(r, 0, 2*n, n);
*/
void palindrome_ric2(int a[], int i, int j, int v) {
    if (i > j) {
        return; /* caso base: array vuoto */
    } else {
        a[i] = v;
        a[j] = v;
        palindrome_ric2(a, i + 1, j - 1, v - 1);
    }
}

/* Funzione non ricorsiva che invoca la ricorsione */
int *palindrome(int n) {
    int *r = (int *)malloc((2 * n + 1) * sizeof(int));
    /* Se si vuole usare la funzione palindrome_ric2() occorre modificare
       la riga seguente come:

       palindrome_ric2(r, 0, 2*n, n);
    */
    palindrome_ric(r, 0, 2 * n);
    return r;
}

/**
 ** Non dovrebbe essere necessario modificare il codice che segue
 **/

/* Stampa il contenuto di v[] */
void print_array(const int v[], int n) {
    int i;
    printf("{");
    for (i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("}");
}

int main(void) {
    const int n = 7;
    int *r = palindrome(n);
    print_array(r, 2 * n + 1);
    printf("\n");
    free(r);
    return 0;
}
