#include <stdio.h>
#include <./utilities.h>

#define UNIT 1600

unsigned int squared_norm(unsigned int x, unsigned int y);
char to_char(unsigned int x, unsigned int unit);
unsigned int unit(unsigned int n);

int main(void) {
    unsigned int n = prompt_positive_int();

    const unsigned int u = unit(n);

    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            printf("%c", to_char(squared_norm(j, i), u));
        }
        printf("\n");
    }
}

unsigned int squared_norm(unsigned int x, unsigned int y) {
    return x*x + y*y;
}

char to_char(unsigned int x, unsigned int unit) {
    if (x < unit) {
        return '.';
    } else if (x < 2 * unit) {
        return 'o';
    } else if (x < 3 * unit) {
        return 'O';
    } else {
        return 'X';
    }
}

unsigned int unit(unsigned int n) {
    return n * n / 2;  
}
