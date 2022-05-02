#include <stdlib.h>
#include "./utils.h"

void find_even(int *array, int size, int *result);
int *get_even(int *array, int size);

int main(void) {
    const int N = rand_int(100, 200);
    printf("N=%d\n", N);

    int *array = rand_int_array(N, 1, 100);
    print_int_array(array, N, "array=", "\n");

    int amount_of_results = N / 2 + N % 2;
    printf("amount_of_results=%d\n", amount_of_results);

    int *result1 = (int *)malloc(amount_of_results * sizeof(int));
    find_even(array, N, result1);
    print_int_array(result1, amount_of_results, "result1=", "\n");
    
    int *result2 = get_even(array, N);
    print_int_array(result2, amount_of_results, "result2=", "\n");

    if (int_array_equals(result1, result2, amount_of_results)) {
        printf("Correct: result1 is equal to result2\n");
    } else {
        printf("ERROR: result1 is different than result2\n");
    }

    free(array);
    free(result1);
    free(result2);
}

void find_even(int *array, int size, int *result) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            *result = *(array + i);
            /* *result = array[i]; */
            result++;
        }
    }
}

int *get_even(int *array, int size) {
    int n = size / 2 + size % 2;
    int *result = (int *)malloc(n * sizeof(int));
    find_even(array, size, result);
    return result;
}