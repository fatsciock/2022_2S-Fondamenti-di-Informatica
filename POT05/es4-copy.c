#include <stdio.h>
#include "./utils.h"

void array_cp(double *array, int start_incl, int end_excl, double *result);
double *array_copy(double *array, int start_incl, int end_excl);

int main(void) {
    const int N = rand_int(10, 19);
    const int START = rand_int(0, N/2 - 1);
    const int END = rand_int(N/2, N);
    printf("N=%d, START=%d, END=%d\n", N, START, END);

    double *array = rand_double_array(N, 1, 100);
    print_double_array(array, N, "array=", "\n");

    int amount_of_results = END - START;
    printf("amount_of_results=%d\n", amount_of_results);

    double *result1 = (double *) malloc(amount_of_results * sizeof(double));
    array_cp(array, START, END, result1);
    print_double_array(result1, amount_of_results, "result1=", "\n");
    
    double *result2 = array_copy(array, START, END);
    print_double_array(result2, amount_of_results, "result2=", "\n");

    if (double_array_equals(result1, result2, amount_of_results)) {
        printf("Correct: result1 is equal to result2\n");
    } else {
        printf("ERROR: result1 is different than result2\n");
    }

    free(array);
    free(result1);
    free(result2);
}

void array_cp(double *array, int start_incl, int end_excl, double *result) {
    for (int i = start_incl; i < end_excl; i++) {
        *(result + i - start_incl) = *(array + i);
    }
}

double *array_copy(double *array, int start_incl, int end_excl) {
    double *result = (double *)malloc((end_excl - start_incl) * sizeof(double));
    array_cp(array, start_incl, end_excl, result);
    return result;
}