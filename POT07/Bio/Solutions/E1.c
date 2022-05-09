#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int array_equals(int a[], int b[], int size);
void print_array(int *a, int size);

/*
  Realizzare la funzione f qui sotto riportata, che dato in ingresso un intero N
  restituisce in uscita un array senza ripetizioni così costruito:

  [N,0,N-1,1,N-2,2,...]

  Come riferimento si consideri che l'esecuzione del test
  (eseguita dal metodo main) deve riportare il risultato true.
*/

int *f(int n) {
    int *r = (int *)malloc(sizeof(int) * (n + 1));
    int i;
    for (i = 0; i <= n; i += 2) {
        r[i] = n - i / 2;
        r[i + 1] = i / 2;
    }
    print_array(r, n + 1);
    return r;
}

int test() {
    int o0[] = {0};
    int o1[] = {1, 0};
    int o5[] = {5, 0, 4, 1, 3, 2};
    int o6[] = {6, 0, 5, 1, 4, 2, 3};
    int o11[] = {11, 0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};

    return array_equals(f(0), o0, 1) && array_equals(f(1), o1, 2) &&
           array_equals(f(5), o5, 6) && array_equals(f(6), o6, 7) &&
           array_equals(f(11), o11, 12);
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
    printf("\n");
}
