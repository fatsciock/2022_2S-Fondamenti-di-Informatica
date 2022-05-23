#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Definire la funzione seguente che legge dallo stream `in`
 * e scrive nello stream `out` filtrando via (non stampando) i
 * caratteri che sono inclusi nella stringa `excludes`.
 * Nota
 *    - gli stream `in` e `out` sono già forniti; è il chiamante che si
 *      occuperà di aprirli e chiuderli (la funzione non deve farlo).
 *    - per controllare se un carattere è presente in una stringa si può usare:
 *          char *strchr (char * str, int c);
 *      che restituisce il puntatore alla prima occorrenza di c nella stringa
 *      oppure NULL se non vi sono occorrenze.
 */
void filtra_caratteri(FILE *in, FILE *out, char *excludes) {
    char c;
    while ((c = getc(in)) != EOF) {
        if (strchr(excludes, c) == NULL && putc(c, out) == EOF) {
            perror("Cannot put on out");
            break;
        }
    }
    // ALSO: for(char c; (c = getc(in)) != EOF; strchr(excludes, c) != NULL || putc(c, out));
}

void test(char *s, char *excludes, char *expected) {
    puts("\n*** Test ***\n");
    // FILE *fp = tmpfile(), *fp2 = tmpfile();
    // tmpfile() has a problem on Windows since it creates the temporary file in the root folder
    FILE *fp = fopen("foo.ignore", "w+"), *fp2 = fopen("bar.ignore", "w+");
    
    if (fputs(s, fp) == EOF) {
        perror("Failed put on test creation");
        exit(1);
    }
    rewind(fp);
    filtra_caratteri(fp, fp2, excludes);
    rewind(fp2);
    #define BUFF_SIZE 100
    char buff[BUFF_SIZE] = {0};
    if (fgets(buff, BUFF_SIZE, fp2) == NULL && ferror(fp2)) {
        perror("Failed get on test creation");
        exit(1);
    }
    printf("Input: '%s'. Excludes: '%s'.\nExpected: '%s'. Actual: '%s'.\n%s\n",
           s, excludes, expected, buff, strcmp(expected, buff) != 0 ? "TEST FAILURE" : "TEST OK");
    fclose(fp);
}

int main() {
    test("foo bar", "", "foo bar");
    test("foo bar", " ", "foobar");
    test("foo bar", "o", "f bar");
    test("foo bar", "rob", "f a");
    test("", "rob", "");
}
