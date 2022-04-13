#include <stdio.h>
#include "./utils.h"

#define N 3

double *element_wise_product(double *array1, double *array2, int size);

int main(void) {
    double *array1 = rand_double_array(N, 1, 100);
    double *array2 = rand_double_array(N, 1, 100);
    double *result = element_wise_product(array1, array2, N);

    print_double_array(array1, N, "array1 = ", "\n");
    print_double_array(array2, N, "array2 = ", "\n");
    print_double_array(result, N, "Prodotto elemento per elemento = ", "\n");

    free(array1);
    free(array2);
    free(result);

    return 0;
}

double *element_wise_product(double *array1, double *array2, int size) {
    double *result = (double *)malloc(size*sizeof(double));
    for (int i=0; i < size; i++) {
        result[i] = array1[i] * array2[i];
    }
    return result;
}
