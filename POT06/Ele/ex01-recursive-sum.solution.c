#include <stdio.h>

int somma(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + somma(n - 1);
    }
}

int somma_due_numeri(int x, int y) {
    if (y == 0) {
        return x;
    } else {
        if (x == 0) {
            return y;
        } else {
            return 1 + somma_due_numeri(x, y - 1);
        }
    }
}

int main(void) {
    int a = 4;
    printf("la somma dei primi %d numeri e' %d\n", a, somma(a));

    int x = 1, y = 10;
    printf("la somma di %d e %d e' %d\n", x, y, somma_due_numeri(x, y));
    return 0;
}
