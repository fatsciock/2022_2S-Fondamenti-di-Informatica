#include <stdio.h>
#include <stdlib.h>

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
    int lenght = 0;
    for (int i=0; ; i++) {
        if (string[i] == '\0') {
            break;
        } else {
            if (string[i] != element) {
                lenght++;
            }
        }
    }
    char *result = (char *)malloc(++lenght*sizeof(char));
    int i = 0;
    int j = 0;
    do {
        if (string[i] != element) {
            result[j++] = string[i];
        }
    } while(string[i++] != '\0');
    return result;
}