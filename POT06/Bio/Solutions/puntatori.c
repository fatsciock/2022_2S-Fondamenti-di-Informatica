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
    // a = 29 -- b = 28 -- c = -7
}
