#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dna_helix(char *sequence1, char *sequence2);
int is_paired(char c1, char c2);

int main(void) {
    char s1[] = "aGCtAA";
    char s2[] = "TcgAG";
    char expected_result[] = "aT-Gc-Cg-tA";
    char *actual_result = dna_helix(s1, s2);

    // see https://www.cplusplus.com/reference/cstring/strcmp/
    if (strcmp(expected_result, actual_result) != 0) {
        printf("ERROR: something went wrong :(\nactual_result='%s'\n", actual_result);
    } else {
        printf("OK!\n");
    }

    free(actual_result);

    return 0;
}

int is_paired(char c1, char c2) {
    return ((c1 == 'A' || c1 == 'a') && (c2 == 'T' || c2 == 't')) ||
           ((c1 == 'T' || c1 == 't') && (c2 == 'A' || c2 == 'a')) ||
           ((c1 == 'G' || c1 == 'g') && (c2 == 'C' || c2 == 'c')) ||
           ((c1 == 'C' || c1 == 'c') && (c2 == 'G' || c2 == 'g'));
}

char *dna_helix(char *seq1, char *seq2) {
    int dim = 0;
    for (; seq1[dim] != '\0' && seq2[dim] != '\0' && is_paired(seq1[dim], seq2[dim]); dim++);
    char *result = (char *) malloc(3 * dim * sizeof(char));
    for (int i = 0, j = 0; i < dim; i++, j += 3) {
        result[j] = seq1[i];
        result[j + 1] = seq2[i];
        result[j + 2] = '-'; 
    }
    result[3 * dim - 1] = '\0';
    return result;
}