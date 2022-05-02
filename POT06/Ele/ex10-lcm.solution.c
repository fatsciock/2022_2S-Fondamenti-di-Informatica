#include <stdio.h>
#include <stdlib.h>

int innerlcm(int c, int a, int b) {
    int m = c + b;
    if (m % a == 0 && m % b == 0) {
        return m;
    } else {
        return innerlcm(m, a, b);
    }
}

int lcm(int a, int b) {
    return innerlcm(b, a, b);
}

int main(int argc, char *argv[]) {
    printf("Got %d, should be 20\n", lcm(20, 10));
    printf("Got %d, should be 55\n", lcm(11, 5));
    printf("Got %d, should be 1800\n", lcm(360, 300));
    return 0;
}
