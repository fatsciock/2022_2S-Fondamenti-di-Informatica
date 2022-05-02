/* replica.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FUNZIONE DA REALIZZARE
   ======================

   Realizzare la funzione replica(s, n) in base alle specifiche
   seguenti. La funzione accetta coem parametri una stringa s e un
   intero n >= 0; la funzione deve restituire una NUOVA stringa
   ottenuta concatenando n copie di s. Ad esempio, replica("ciao", 3)
   ritorna la stringa "ciaociaociao" in cui la parola "ciao" viene
   ripetuta tre volte; replica("ciao", 0) ritorna la stringa vuota "";
   replica("prova", 1) ritorna la stringa "prova". Si faccia
   riferimento ai test per ulteriori esempi.

   Se lo si ritiene utile e' possibile fare uso della funzione
   strlen(); non e' invece consentito usare funzioni come strcat(),
   strcpy() e simili.

   Si rammenta che una funzione che supera i test non e' necessariamente
   corretta.
*/
char *replica(char *s, int n) {
    // TODO
    return '\0';
}

void test(char *s, int n, char *expect) {
    char *r = replica(s, n);
    if (r != NULL && 0 == strcmp(r, expect)) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: risultato atteso \"%s\", risultato ottenuto "
               "\"%s\"\n",
               expect, r);
    }
    free(r);
}

int main(void) {
    test("ciao", 3, "ciaociaociao");
    test("ciao", 0, "");
    test("ciao", 1, "ciao");
    test("fondamenti di informatica ", 2, "fondamenti di informatica fondamenti di informatica ");
    test("fondamenti di informatica ", 0, "");
    test("a", 10, "aaaaaaaaaa");
    test("a", 1, "a");
    test("actg", 5, "actgactgactgactgactg");
    return 0;
}
