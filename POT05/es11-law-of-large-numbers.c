#include "./utils.h"

#define K 10000
#define N 10000

int *k_toss(int k);
double mean_of_int_array(int *array, int size);

int main(void) {

    double mean_of_means = 0;
    for (int i=0; i<N; i++) {
        int *tosses = k_toss(K);
        mean_of_means += mean_of_int_array(tosses, K);
        free(tosses);
    }
    mean_of_means /= N;

    printf("Mean of %d means of %d tosses of a coin is: %lf", N, K, mean_of_means);

    return 0;
}

int *k_toss(int k) {
    int *result = rand_int_array(k, 0, 1);
    return result;
}

double mean_of_int_array(int *array, int size) {
    double mean = 0;
    for (int i=0; i< size; i++) {
        mean += array[i];
    }
    return mean / size;
}