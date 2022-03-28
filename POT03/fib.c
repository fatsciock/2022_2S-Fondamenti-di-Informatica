#include <stdio.h>
#include <./utilities.h>

unsigned int fib(unsigned int n);

int main(void) {
    unsigned int n = prompt_non_negative_int();

    printf("fib(%u) = %u\n", n, fib(n));

    return 0;
}

unsigned int fib(unsigned int n) {
    unsigned int previous = 0;
    unsigned int current = 1;
    for (unsigned int i = 0; i < n; i++) {
        unsigned int next = current + previous;
        previous = current;
        current = next;
    }
    return current;
}
