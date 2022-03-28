#include <stdio.h>
#include <./utilities.h>

unsigned int fact(unsigned int n);

int main(void) {
    unsigned int n = prompt_non_negative_int();

    printf("fact(%u) = %u\n", n, fact(n));

    return 0;
}

unsigned int fact(unsigned int n) {
    unsigned int x = 1;
    for (unsigned int i = 1; i <= n; i++) {
        x *= i;
    }
    return x;
}
