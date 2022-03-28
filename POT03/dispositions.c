#include <stdio.h>
#include <./utilities.h>

unsigned int fact(unsigned int n);
unsigned int dispositions(unsigned int n, unsigned int k);

int main(void) {
    unsigned int n = prompt_positive_int();
    unsigned int k = prompt_int_in_range(0, n + 1);

    printf("%u! / (%u - %u)! = %u\n", n, n, k, dispositions(n, k));

    return 0;
}

unsigned int dispositions(unsigned int n, unsigned int k) {
    unsigned int x = 1;
    for (unsigned int i = n; i > n - k; i--) {
        x *= i;
    }
    return x;
}

// dispositions(14, 2) = 182
