#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *remove_element(char *string, char element);

int main(void) {
    char *string1 = "Giovanni";
    char *string2 = "Matteo";
    char element = 'i';

    char *result1 = remove_element(string1, element);
    char *result2 = remove_element(string2, element);

    printf("%s senza %c diventa %s\n", string1, element, result1);
    printf("%s senza %c diventa %s\n", string2, element, result2);

    free(result1);
    free(result2);

    return 0;
}

char *remove_element(char *string, char element) {
    int length = strlen(string) + 1;
    char *result = (char *) malloc(length * sizeof(char));
    for (int i = 0, j = 0; i <= length; i++) {
        if (string[i] != element) {
            result[j++] = string[i];
        }
    }
    return result;
}