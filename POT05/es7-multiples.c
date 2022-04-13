#include <stdlib.h>
#include <./utils.h>

int count_of_m(int n, int m);
void find_n_of_m(int n, int m, int *results);
int *get_n_of_m(int n, int m);

int main(void) {
    const int N = rand_int(500, 1000);
    const int M = rand_int(10, 20);
    printf("N=%d, M=%d\n", N, M);

    int amount_of_results = count_of_m(N, M);
    printf("amount_of_results=%d\n", amount_of_results);

    int *result1 = (int *)malloc(amount_of_results * sizeof(int));
    find_n_of_m(N, M, result1);
    print_int_array(result1, amount_of_results, "result1=", "\n");
    
    int *result2 = get_n_of_m(N, M);
    print_int_array(result2, amount_of_results, "result2=", "\n");

    if (int_array_equals(result1, result2, amount_of_results)) {
        printf("Correct: result1 is equal to result2\n");
    } else {
        printf("ERROR: result1 is different than result2\n");
    }

    free(result1);
    free(result2);
}


int count_of_m(int n, int m) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (i % m == 0) {
            count++;
        }
    }
    return count;
}

void find_n_of_m(int n, int m, int *results) {
    for (int i = 1; i < n; i++) {
        if (i % m == 0) {
            *results = i;
            results++;
        }
    }
}

int *get_n_of_m(int n, int m) {
    int size = count_of_m(n, m);
    int *result = (int *)malloc(size * sizeof(int));
    find_n_of_m(n, m, result);
    return result;
}