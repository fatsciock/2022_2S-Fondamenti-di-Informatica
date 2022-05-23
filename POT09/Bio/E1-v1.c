#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int array_equals(int a[], int b[], int size);
void print_array(int *a, int size);

/*
Realizzare la funzione f qui sotto riportata, che dato in ingresso un array di
interi crea e torna un NUOVO array simile all'input, ma in cui l'ultima
occorrenza dell'elemento più grande e di quello più piccolo vengono scambiati
fra loro.

Come riferimento si consideri che l'esecuzione del test
(eseguita dal metodo main) deve riportare il risultato true.
*/

int *f(int *a, int size) {
    int *r = (int *)malloc(sizeof(int) * size);

    int i;
    int min = a[0];
    int max = a[0];
    int pos_min = 0;
    int pos_max = 0;

    for (i = 0; i < size; i++) {
        r[i] = a[i];
        if (a[i] >= max) {
            max = a[i];
            pos_max = i;
        }
        if (a[i] <= min) {
            min = a[i];
            pos_min = i;
        }
    }

    int tmp = r[pos_max];
    r[pos_max] = r[pos_min];
    r[pos_min] = tmp;

    print_array(a, size);
    print_array(r, size);
    return r;
}

int test() {
    int i0[] = {10, 20, 30, 40, 50};
    int o0[] = {50, 20, 30, 40, 10};
    int i1[] = {10, 10, 10, 20, 30, 30, 30};
    int o1[] = {10, 10, 30, 20, 30, 30, 10};
    int i2[] = {30, 30, 10, 20, 30, 10, 10};
    int o2[] = {30, 30, 10, 20, 10, 10, 30};
    int i3[] = {10, 20, 30};
    int o3[] = {30, 20, 10};
    int i4[] = {10, 20};
    int o4[] = {20, 10};
    return array_equals(f(i0, 5), o0, 5) && array_equals(f(i1, 7), o1, 7) &&
           array_equals(f(i2, 7), o2, 7) && array_equals(f(i3, 3), o3, 3) &&
           array_equals(f(i4, 2), o4, 2);
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
