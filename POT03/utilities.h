#include <stdio.h>

int prompt_int_greater_than(int lower_bound) {
    int n;
    do {
        printf("Insert an integer greather than %d:\n> ", lower_bound);
        scanf("%d", &n);
    } while (n <= lower_bound);
    return n;
}

int prompt_int_lower_than(int upper_bound) {
    int n;
    do {
        printf("Insert an integer lower than %d:\n> ", upper_bound);
        scanf("%d", &n);
    } while (n >= upper_bound);
    return n;
}

int prompt_int_in_range(int lower_bound, int upper_bound) {
    int n;
    do {
        printf("Insert an integer from the range ]%d, %d[:\n> ", lower_bound, upper_bound);
        scanf("%d", &n);
    } while (n <= lower_bound || n >= upper_bound);
    return n;
}

int prompt_int() {
    int n;
    printf("Insert any integer:\n> ");
    scanf("%d", &n);
    return n;
}

unsigned int prompt_positive_int() {
    return (unsigned int) prompt_int_greater_than(0);
}

unsigned int prompt_non_negative_int() {
    return (unsigned int) prompt_int_greater_than(-1);
}

unsigned int minu(unsigned int a, unsigned int b) {
    return a >= b ? b : a;
}

int min(int a, int b) {
    return a >= b ? b : a;
}

unsigned int maxu(unsigned int a, unsigned int b) {
    return a >= b ? a : b;
}

int max(int a, int b) {
    return a >= b ? a : b;
}
