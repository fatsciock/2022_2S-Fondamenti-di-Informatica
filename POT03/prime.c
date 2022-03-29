#include <stdio.h>
#include <./utilities.h>

#define TRUE 1
#define FALSE 0

unsigned int is_prime(unsigned int n);

int main(void) {
    unsigned int n = prompt_positive_int();

    if (is_prime(n)) {
        printf("prime\n");
    } else {
        printf("not prime\n");
    }

    return 0;
}

unsigned int is_prime(unsigned int n) {
    for (unsigned int i = 2; i < n; i++) {
        if (n % i == 0) {
            return FALSE;
        }
    }
    return TRUE;
}
