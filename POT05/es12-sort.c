#include <stdio.h>
#include <stdlib.h>
#include <./utils.h>

#define N 10
#define MIN 0
#define MAX 100

double *sort_double(double *array, int size);
double min_double(double *array, int size);
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

double *sort_double(double *array, int size) {
    double *result = (double *)malloc(size*sizeof(double));
    double *copy = array_copy(array, 0, size);
    for (int i=0; i<size; i++) {
        double min = min_double(copy, size - i);
        result[i] = min;
        double *new_copy = remove_element(copy, size-i, min);
        
        free(copy);
        copy = new_copy;
        free(new_copy);
    }

    free(copy);
    return result;

}

double min_double(double *array, int size) {
    double result = INT64_MAX;
    for (int i=0; i < size; i++) {
        if (result > array[i]){
            result = array[i];
        }
    }
    return result;
}

double *remove_element(double *array, int size, double element) {
    double *result = (double *)malloc((size-1)*sizeof(double));
    int found = 0;
    for (int i=0; i<size; i++){
        if (found == 0 && array[i] == element) {
            found = 1;
        } else {
            result[i-found] =array[i];
        }
    }
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