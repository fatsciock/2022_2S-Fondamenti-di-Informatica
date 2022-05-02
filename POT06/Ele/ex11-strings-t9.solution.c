/* t9.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Realizzare una funzione t9() secondo le specifiche seguenti. La
 * funzione accetta in input una stringa s composta esclusivamente
 * dalle lettere minuscole 'a'..'z'. La funzione restituisce un
 * puntatore ad una nuova stringa, allocata con malloc(), avente la
 * stessa lunghezza di s. Tale stringa deve essere composta dai
 * caratteri '2'..'9' in modo tale che ad ogni lettera di s
 * corrisponda un carattere numerico secondo la codifica seguente:
 *
 * abc -> 2
 * def -> 3
 * ghi -> 4
 * jkl -> 5
 * mno -> 6
 * pqrs -> 7
 * tuv -> 8
 * wxyz -> 9
 *
 * Quindi i caratteri 'a', 'b' e 'c' vengono rappresentati da un
 * singolo carattere '2', i caratteri 'd', 'e', 'f' da un singolo
 * carattere '3' e cosi' via. La codifica sopra e' quella utilizzata
 * dal t9 dei vecchi cellulari. Se lo si reputa utile, si puo' fare
 * uso delle funzioni definite nell'header file <string.h>, gia'
 * incluso nel programma; l'unica funzione che potrebbe risultare
 * utile e' strlen(s), che restituisce la lunghezza di una stringa s.
 */
char *t9(char *s) {
    /* Questa soluzione sfrutta l'idea di costruire una "tabella" di
     * conversione lettera->numero, come abbiamo visto a lezoine in
     * altri esempi sull'uso degli array. La tabella in questione e'
     * l'array t9enc, e contiene una stringa di 26 elementi. t9enc[0]
     * e' la codifica T9 della lettera 'a', t9enc[1] e' la codifica T9
     * della lettera 'b', ... t9enc[25] e' la codifica T9 della
     * lettera 'z'. Per ottenere la codifica di una lettera il cui
     * codice ASCII e' memorizzato in una variabile x, scriveremo
     * quindi t9enc[x - 'a'] (infatti il codice ASCII di 'a' non e'
     * zero, quindi t9enc['a'] causerebbe un accesso out-of-bound
     * nell'array t9enc
     */
    char *t9enc = "22233344455566677778889999";
    char *r = (char *)malloc(strlen(s) + 1);
    int i;
    for (i = 0; i < strlen(s); i++) {
        r[i] = t9enc[s[i] - 'a'];
    }
    r[i] = 0; /* la stringa r deve essere terminata col terminatore 0, come
                 tutte le stringhe in C */
    return r;
}

/**
 ** Non dovrebbe essere necessario modificare la parte seguente
 **/
void test(char *str, char *expect) {
    char *result = t9(str);
    if ((result != NULL) && (strcmp(result, expect) == 0)) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: str=%s, risultato atteso=%s, risultato ottenuto=%s\n", str, expect, result);
    }
    free(result);
}

int main(void) {
    test("informatica", "46367628422");
    test("finfa", "34632");
    test("ciao", "2426");
    return 0;
}
