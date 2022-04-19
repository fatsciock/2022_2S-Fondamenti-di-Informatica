#include <stdio.h>
#include <stdlib.h>
#include "./utils.h"

#define N 10
#define MIN 0
#define MAX 100

double *sort_double(double *array, int size);
void sort_double_array_in_place(double *array, int size);
int min_double(double *array, int size, int start_index);
double *remove_element(double *array, int size, double element);
void array_cp(double *array, int start_incl, int end_excl, double *result);
double *array_copy(double *array, int start_incl, int end_excl);

int main(void) {
    double *array = rand_double_array(N, MIN, MAX);

    print_double_array(array, N, "Array di partenza: ", "\n");

    double *result = sort_double(array, N);

    print_double_array(result, N, "Array ordinato: ", "\n");

    free(array);
    free(result);

    return 0;
}

int min_double(double *array, int size, int start_index) {
    int min_index = start_index;
    double min = array[start_index];

    for (int i = start_index; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
            min_index = i;
        }
    }

    return min_index;
}

void sort_double_array_in_place(double *array, int size) {
    for (int i = 0; i < size; i++) {
        int min_index = min_double(array, size, i);
        double tmp = array[min_index];
        array[min_index] = array[i];
        array[i] = tmp;
    }
}

double *sort_double(double *array, int size) {
    double *result = array_copy(array, 0, size);
    sort_double_array_in_place(result, size);
    return result;
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
