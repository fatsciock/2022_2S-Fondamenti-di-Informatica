#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFDIM 1000

char *word_delimiters = "\"&()_;:,.!?'- \n\t\0";

/*
 * La funzione seguente restituisce il numero di occorrenze della parola w
 * nella stringa s.
 * Si controlli la documentazione per:
 *    char *strtok(char *str, const char *delim)
 */
int numero_occorrenze_parola(char *s, char *w) {
    int n = 0;
    char *token;
    if ((token = strtok(s, word_delimiters)) == NULL) {
        return 0;
    }
    if (strcmp(token, w) == 0) {
        n++;
    }
    while ((token = strtok(NULL, word_delimiters)) != NULL) {
        if (strcmp(token, w) == 0) {
            n++;
        }
    }
    return n;
}

/**
 * Definire la funzione seguente, che restituisce il numero di occorrenze
 * della parola w nel file fp (già aperto e chiuso esternamente alla funzione).
 * La funzione deve restituire -1 in caso di errore.
 * Nota: si consideri una parola una sequenza di caratteri delimitata
 * da caratteri diversi da 'a'..'z', 'A'..'Z'; si può assumere che i
 * delimitatori di parole sono quelli contenuti nella variabile globale
 * word_delimiters.
 *
 * Si valuti l'uso di
 *         char *fgets(char *s, int size, FILE *stream)
 * con un buffer di dimensione BUFDIM (si veda costante simbolica in alto). Si
 * guardi inoltre la funzione int numero_occorrenze_parola(char *s, char *w) già
 * fornita.
 */
int conta_occorrenze(FILE *fp, char *w) {
    int n = 0;
    char buff[BUFDIM];
    while (fgets(buff, BUFDIM, fp) != NULL) { // leggi BUFDIM caratteri
        n += numero_occorrenze_parola(buff, w);
    }
    if (ferror(fp)) {
        return -1;
    }
    return n;
}

void mystrtok(char *source, char *target, char *delimiter) {
    int i = 0;
    for (; target[i] && !strchr(delimiter, target[i]); i++) {
        source[i] = target[i];
    }
    source[i] = '\0';
}

int conta_occorrenze2(FILE *fp, char *w) {
    int n = 0;
    char buff[BUFDIM];
    while (fgets(buff, BUFDIM, fp) != NULL) {
        char *p = buff;
        char tmp[BUFDIM] = "";
        while (*p) {
            mystrtok(tmp, p, word_delimiters);
            p = p + strlen(tmp) + 1;
            if (strcmp(tmp, w) == 0) {
                n++;
            }
        }
    }
    if (ferror(fp)) {
        return -1;
    }
    return n;
}

void test(char *s, char *w, int expected) {
    // FILE *fp = tmpfile();
    FILE *fp = fopen("foo.ignore", "w+");

    if (fputs(s, fp) == EOF) {
        perror("Failed put on test creation");
        exit(1);
    }
    rewind(fp);
    int actual = conta_occorrenze(fp, w);
    rewind(fp);
    int actual2 = conta_occorrenze2(fp, w);
    printf("conta_occorrenze()=%d conta_occorrenze2()=%d\n", actual, actual2);
    printf("Expected: %d of '%s' in '%s'.\nActual: %d. \n%s\n---\n", expected,
           w, s, actual, actual != expected ? "TEST FAILURE" : "TEST OK");
    fclose(fp);
}

int main() {
    test("", "", 0);
    test("foo bar", "foo", 1);
    test("foo bar,foo, foo!", "foo", 3);
    test("foo bar,foo, foo!", "bar", 1);
    test("foo bar,foo, foo!", "fo", 0);
    test("foo bar,foo, foo!", "foo,", 0);
}
