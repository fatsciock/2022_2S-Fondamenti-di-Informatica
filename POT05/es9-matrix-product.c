#include <stdio.h>
#include <stdlib.h>

#define M 3
#define N 2
#define P 4

double *matrix_product(double *m1, double *m2, int m, int n, int p);
void print_matrix(double *matrix, int m, int n);

int main(void) {
    double matrix1[] = {
        1, 2,
        3, 4,
        5, 6
    };
    print_matrix(matrix1, M, N);

    printf("x\n");

    double matrix2[] = {
        1, 2, 3, 4,
        5, 6, 7, 8
    };
    print_matrix(matrix2, N, P);

    printf("=\n");

    double *product = matrix_product(matrix1, matrix2, M, N, P);
    print_matrix(product, M, P);

    free(product);
}

double *matrix_product(double *m1, double *m2, int m, int n, int p) {
    double *result = (double *) malloc(m * p * sizeof(double));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i * p + j] += m1[i * n + k] * m2[k * p + j];
            }
        }
    }
    return result;
}

void print_matrix(double *matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        printf("%g", matrix[i * n]);
        for (int j = 1; j < n; j++) {
            printf(", %g", matrix[i * n + j]);
        }
        printf("\n");
    }
}
