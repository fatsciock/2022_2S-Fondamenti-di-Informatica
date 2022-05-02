#include <stdio.h>
#include <stdlib.h>

double mypow(double basis, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return exponent < 0 ? mypow(basis, exponent + 1) / basis : mypow(basis, exponent - 1) * basis;
    // if (exponent > 0) {
    //     return basis * mypow(basis, exponent - 1);
    // } else if (exponent < 0) {
    //     return mypow(basis, exponent + 1) / basis;
    // } else {
    //     return 1.0;
    // }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s n n\n", argv[0]);
        return -1;
    }
    printf("%f\n", mypow(atof(argv[1]), atoi(argv[2])));
    return 0;
}
