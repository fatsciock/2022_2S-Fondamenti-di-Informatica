#include <stdio.h>

int main(void) {
    int a[] = {10, 20, 3};
    int *c = &a[2];
    *(a + 1) = *c;
    c--;
    *c = 40;
    ++c;
    *c = 1;
    printf("a[0] = %d -- a[1] = %d -- a[2] = %d\n", a[0], a[1], a[2]);
}
