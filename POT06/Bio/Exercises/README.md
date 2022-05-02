# Esame

## Esercizio 1

Completare la funzione `double dev_std(double *x, int n)` in `deviazione_standard.c`.

## Esercizio 2

Indicare l'output del seguente programma

```c
#include <stdio.h>

int main(void) {
    int a = 20, b = 27, c = 31;
    int *ptrA = &a, *ptrB = &b, *ptrC = &c;
    a++;
    b++;
    *ptrC = *ptrA - *ptrB;
    ptrC = ptrA;
    *ptrA = *ptrB + 1;
    printf("a = %d -- b = %d -- c = %d\n", a, b, c);
}
```

## Esercizio 3

Completare la funzione `char *replica(char *s, int n)` in `replica.c`.