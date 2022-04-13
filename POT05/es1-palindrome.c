#include <stdio.h>
#include <string.h>

int is_palindrome(char *string);

int main(void) {
    if (!is_palindrome("abba")) {
        printf("ERROR: 'abba' is palindrome!\n");
    } else if (is_palindrome("ciao")) {
        printf("ERROR: 'ciao' is NOT palindrome!\n");
    } else if (!is_palindrome("abcba")) {
        printf("ERROR: 'abcba' is palindrome!\n");
    } else if (!is_palindrome("")) {
        printf("ERROR: '' is palindrome!\n");
    } else {
        printf("OK!\n");
    }
    return 0;
}

int is_palindrome(char *string) {
    int length = strlen(string);
    for (int i = 0; i <= length / 2; i++) {
        if (*(string + i) != *(string + length - 1 - i)) {
            return 0;
        }
    }
    return 1;
}
