#include <stdio.h>
#include <./utilities.h>

unsigned int gcd(unsigned int n, unsigned int m);

int main(void) {
    unsigned int n = prompt_positive_int();
    unsigned int m = prompt_positive_int();

    printf("gcd(%u, %u) = %u\n", n, m, gcd(n, m));

    return 0;
}

unsigned int gcd(unsigned int n, unsigned int m) {
    unsigned int greatest = maxu(n, m);
    unsigned int smallest = minu(n, m);
    while (smallest > 0) {
        unsigned int remainder = greatest % smallest;
        greatest = smallest;
        smallest = remainder;
    }
    return greatest;
}
