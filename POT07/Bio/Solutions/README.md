# Esame

## Esercizio 1

Completare la funzione `int *f(int n)` in `E1.c`.

## Esercizio 2

Completare la funzione `int *f(int n)` in `E2.c`.

## Esercizio 3 (9 CFU)

Completare la funzione `int lista_uguale(struct list *L)` in `E3.c`.

## Esercizio 4

Indicare l'output del seguente programma.

```c
#include <stdio.h>

int main(void) {
    int a[] = {10, 20, 3};
    int *c = &a[2];
    *(a + 1) = *c;
    c--;
    *c = 40;
    ++c;
    *c = 1;
    printf("a[0] = %d -- a[1] = %d -- a[2] = %d\n", a[0], a[1], a[2]);
}
```