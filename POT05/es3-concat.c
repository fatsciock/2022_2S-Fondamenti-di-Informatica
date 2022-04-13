#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen, strcmp

void string_concat(char *string1, char *string2, char *result);
char *string_concatenate(char *string1, char *string2);

int main(void) {
    char *ciao = "ciao";
    char *mondo = "mondo";

    char ciao_space[sizeof(ciao) + 1];
    string_concat(ciao, " ", ciao_space);

    char *ciao_mondo = string_concatenate(ciao_space, mondo);
    
    char ciao_mondo2[sizeof(ciao) + sizeof(mondo)];
    string_concat(ciao_mondo, "", ciao_mondo2);

    // see https://www.cplusplus.com/reference/cstring/strcmp/
    if (strcmp("ciao mondo", ciao_mondo2) != 0) {
        printf("ERROR: something went wrong :(\nciao_mondo2='%s'\n", ciao_mondo2);
    } else {
        printf("OK!\n");
    }

    free(ciao_mondo);
}

void string_concat(char *string1, char *string2, char *result) {
    int i = 0, j = 0;
    for (; *(string1 + i) != '\0'; i++) {
        *(result + i) = *(string1 + i);
    }
    for (; *(string2 + j) != '\0'; j++) {
        *(result + i + j) = *(string2 + j);
    }
    *(result + i + j) = '\0';
}


char *string_concatenate(char *string1, char *string2) {
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    char *result = (char *)malloc((len1 + len2) * sizeof(char));
    string_concat(string1, string2, result);
    return result;
}