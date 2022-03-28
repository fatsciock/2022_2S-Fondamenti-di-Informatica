#include <stdio.h>

// see https://it.wikipedia.org/wiki/ASCII#Tabella_dei_caratteri

#define NON_PRINTABLE 0
#define BLANK 1
#define SYMBOL 2
#define DIGIT 3
#define UPPERCASE 4
#define LOWERCASE 5

int classify(char c);

int main(void) {
    char character;

    // see https://man7.org/linux/man-pages/man3/scanf.3.html#RETURN_VALUE
    while (scanf("%c", &character) > 0) {
        int type = classify(character);
        switch (type) {
        case NON_PRINTABLE:
            printf("Character %d is a non-printable\n", (int) character);
            break;
        case BLANK:
            printf("'%c' is a blank character\n", character);
            break;
        case DIGIT:
            printf("'%c' is a digit\n", character);
            break;
        case LOWERCASE:
            printf("'%c' is a lowercase letter\n", character);
            break;
        case UPPERCASE:
            printf("'%c' is an uppercase letter\n", character);
            break;
        default:
            printf("'%c' is a symbolic character\n", character);
            break;
        }
    }

    return 0;
}

int classify(char c) {
    if (c < 32 || c >= 127) {
        return NON_PRINTABLE;
    } else if (c == ' ') {
        return BLANK;
    } else if (c >= '0' && c <= '9') {
        return DIGIT;
    } else if (c >= 'A' && c <= 'Z') {
        return UPPERCASE;
    } else if (c >= 'a' && c <= 'z') {
        return LOWERCASE;
    } else {
        return SYMBOL;
    }
}
