#include <stdlib.h>
#include "./utils.h"

int is_lynch_bell(int x);
int count_lynch_bell(int start, int end);
void find_lynch_bell(int start, int end, int *results);
int *get_lynch_bell(int start, int end);

int main(void) {
    const int START = rand_int(500, 1000);
    const int END = rand_int(2000, 3000);
    printf("START=%d, END=%d\n", START, END);

    int amount_of_results = count_lynch_bell(START, END);
    printf("amount_of_results=%d\n", amount_of_results);

    int *result1 = (int *)malloc(amount_of_results * sizeof(int));
    find_lynch_bell(START, END, result1);
    print_int_array(result1, amount_of_results, "result1=", "\n");
    
    int *result2 = get_lynch_bell(START, END);
    print_int_array(result2, amount_of_results, "result2=", "\n");

    if (int_array_equals(result1, result2, amount_of_results)) {
        printf("Correct: result1 is equal to result2\n");
    } else {
        printf("ERROR: result1 is different than result2\n");
    }

    free(result1);
    free(result2);
}


int is_lynch_bell(int x) {
    const int original = x;
    for (; x > 0; x /= 10) {
        int digit = x % 10;
        if (digit != 0 && (original % digit != 0)) {
            return 0; // false
        }
    }
    return 1; // true
}

int count_lynch_bell(int start, int end) {
    int count = 0;
    for (int i = start; i < end; i++) {
        if (is_lynch_bell(i)) {
            count++;
        }
    }
    return count;
}

void find_lynch_bell(int start, int end, int *results) {
    for (int i = start; i < end; i++) {
        if (is_lynch_bell(i)) {
            *results = i;
            results++;
        }
    }
}

int *get_lynch_bell(int start, int end) {
    int size = count_lynch_bell(start, end);
    int *result = (int *)malloc(size * sizeof(int));
    find_lynch_bell(start, end, result);
    return result;
}