#include <stdio.h>
#include <stdlib.h>

void print_int_array(int *array, int size, char *prefix, char *suffix) {
    printf(prefix);
    printf("%d", *array);
    for (int *current = array + 1; current < array + size; current++) {
        printf(", %d", *current);
    }
    printf(suffix);
}

void print_double_array(double *array, int size, char *prefix, char *suffix) {
    printf(prefix);
    printf("%g", *array);
    for (double *current = array + 1; current < array + size; current++) {
        printf(", %g", *current);
    }
    printf(suffix);
}

int int_array_equals(int *array1, int *array2, int size) {
    for (int *x = array1, *y = array2; x < array1 + size && y < array2 + size; x++, y++) {
        if (*x != *y) {
            return 0;
        }
    }
    return 1;
}

int double_array_equals(double *array1, double *array2, int size) {
    for (double *x = array1, *y = array2; x < array1 + size && y < array2 + size; x++, y++) {
        if (*x != *y) {
            return 0;
        }
    }
    return 1;
}

int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
} 

double rand_double(int min, int max) {
    return (double)rand_int(min * 1000, max * 1000) / 1000.0;
} 

int *rand_int_array(int size, int min, int max) {
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        *(array + i) = rand_int(min, max);
    }
    return array;
} 

double *rand_double_array(int size, int min, int max) {
    double *array = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        *(array + i) = rand_double(min, max);
    }
    return array;
} 
