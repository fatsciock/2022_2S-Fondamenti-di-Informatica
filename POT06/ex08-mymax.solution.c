#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int mymax(int a[], int n) {
    if (n == 1) {
        return a[0];
    } else {
        // return MAX(mymax(a, n - 1), a[n - 1]);
        int c = mymax(a, n - 1);
        if (a[n - 1] >= c) {
            return a[n - 1];
        } else {
            return c;
        }
    }
}

int main(int argc, char *argv[]) {
    int a[] = {1, 1, 1};
    printf("Got %d, should be 1\n", mymax(a, sizeof(a) / sizeof(int)));

    int b[] = {1, 2, 2, 2, 2, 3};
    printf("Got %d, should be 3\n", mymax(b, sizeof(b) / sizeof(int)));

    int c[] = {1, 2, 3, 2, 3, 1, 1, 2};
    printf("Got %d, should be 3\n", mymax(c, sizeof(c) / sizeof(int)));

    int d[] = {3, 1, 2, 1, 2};
    printf("Got %d, should be 3\n", mymax(d, sizeof(d) / sizeof(int)));
    return 0;
}
