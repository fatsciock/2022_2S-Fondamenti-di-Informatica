#include <stdio.h>
#include <stdlib.h>

int array_equals(int *a, int *b, int n);
void print_array(int *a, int n);

/*
  FUNZIONE DA REALIZZARE
  ======================

  Realizzare la funzione f qui sotto riportata, che dato un array di
  interi a[] di lunghezza n>2 che contiene sempre almeno due 0,
  restituisce un **nuovo** array contenente i valori di a[] tranne
  quelli compresi fra il primo e secondo 0 (estremi inclusi).  Si
  garantisce che il risultato conterrà sempre almeno un elemento
  (quindi non dovrà mai essere restituito l'array vuoto). Si faccia
  riferimento ai test per alcuni esempi. Si presti attenzione ad
  allocare lo spazio di memoria corretto per l'array risultato (quindi
  non bisogna allocate più spazio di quello effettivamente
  richiesto).
*/
int *f(int *a, int n) {
    int i, j, p, s, newsize;
    int *b;
    /* p indichera' la posizione (indice) del primo zero; s indichera'
       la posizione (indice) del secondo zero. newsize indica la
       dimensione (numero di elementi) del risultato. */

    for (p = 0; p < n && a[p] != 0; p++)
        ; /* corpo vuoto */
    /* qui p indica la posizione del primo zero */

    for (s = p + 1; s < n && a[s] != 0; s++)
        ; /* corpo vuoto */
    /* qui s indica la posizione del secondo zero */

    newsize = n - (s - p + 1);
    b = (int *)malloc(sizeof(int) * newsize);

    j = 0; /* indice nell'array b[] */
    /* copiamo i valori a[0..p-1] in b[]; notare che incrementiamo
       l'indice j "a mano" all'interno del "for" */
    for (i = 0; i < p; i++) {
        b[j] = a[i];
        j++;
    }
    /* copiamo i valori a[s+1..size-1] in b[] */
    for (i = s + 1; i < n; i++) {
        b[j] = a[i];
        j++;
    }
    /* print_array(b, newsize); */
    return b;
}

int array_equals(int *a, int *b, int n) {
    if (a == NULL) {
        return 0;
    } else {
        int i;
        for (i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                return 0;
            }
        }
        return 1;
    }
}

void print_array(int *a, int n) {
    printf("[");
    if (a == NULL) {
        printf("NULL");
    } else {
        int i;
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
    }
    printf("]");
}

void test(int in[], int n, int expect[], int m) {
    int *result = f(in, n);
    if (array_equals(result, expect, m)) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO\n");
    }
}

int main(void) {
    int in1[] = {10, 20, 30, 0, 40, 50, 0, 60, 70};
    int out1[] = {10, 20, 30, 60, 70};

    int in2[] = {10, 20, 30, 0, 0, 60, 70, 80, 90};
    int out2[] = {10, 20, 30, 60, 70, 80, 90};

    int in3[] = {0, 20, 0, 30, 0, 60, 70, 80, 90};
    int out3[] = {30, 0, 60, 70, 80, 90};

    int in4[] = {60, 0, 70, 0, 0};
    int out4[] = {60, 0};

    test(in1, sizeof(in1) / sizeof(in1[0]), out1, sizeof(out1) / sizeof(out1[0]));
    test(in2, sizeof(in2) / sizeof(in2[0]), out2, sizeof(out2) / sizeof(out2[0]));
    test(in3, sizeof(in3) / sizeof(in3[0]), out3, sizeof(out3) / sizeof(out3[0]));
    test(in4, sizeof(in4) / sizeof(in4[0]), out4, sizeof(out4) / sizeof(out4[0]));

    return 0;
}
