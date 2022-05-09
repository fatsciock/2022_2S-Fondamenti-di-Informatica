/* E3.c */
#include <stdio.h>
#include <stdlib.h>

struct list {
    int val;
    struct list *next;
};

/* Dichiarazione di alcune delle funzioni viste a lezione; le funzioni
   sono definite sotto (non devono essere implementate), e possono
   essere usate se serve. */
struct list *list_create(int v, struct list *t);
int list_length(struct list *L);
void list_destroy(struct list *L);
int is_empty(struct list *L);
void list_print(struct list *L);
struct list *list_from_array(int v[], int n);

/* FUNZIONE DA REALIZZARE
   ======================

   Realizzare la funzione lista_uguale(L) seguente. La funzione
   accetta come parametro un puntatore ad una lista L, che potrebbe
   anche essere vuota. La funzione deve restituire 1 se e solo se
   tutti i nodi di L (campo val) eccetto l'ultimo contengono lo stesso valore, 0
   altrimenti. Nel caso di lista vuota o di lista con un solo elemento, la
   funzione deve restituire 1.

   Ad esempio, se L = (30, 30, 30, 30, 1), la funzione restituisce 1; se
   L = (21, 21, 3, 21, 3, 4) oppure L = (30, 30, 30, 30, 30) la funzione
   restituisce 0. Si faccia riferimenti ai test per ulteriori esempi.
*/
int lista_uguale(struct list *L) {
    if (L == NULL || L->next == NULL) {
        return 1;
    }
    for (; L->next->next != NULL; L = L->next) {
        if (L->val != L->next->val) {
            return 0;
        }
    }
    if (L->val == L->next->val) {
        return 0;
    }
    return 1;
}

/**
 ** Le funzioni seguenti sono gia' implementate e si possono usare se serve
 **/

/* Crea (mediante malloc() ) e restituisce un puntatore ad un nuovo
   nodo di una lista; il nodo contiene il valore v e punta a t come
   elemento successivo. Il chiamante e' responsabile per deallocare
   mediante free() o simili la zona di memoria restituita da questa
   funzione, quando non piu' utilizzata */
struct list *list_create(int v, struct list *t) {
    struct list *r = (struct list *)malloc(sizeof(struct list));
    r->val = v;
    r->next = t;
    return r;
}

/* Restituisce la lunghezza (numero di nodi) della lista L; se L e' la
   lista vuota, restituisce 0 */
int list_length(struct list *L) {
    /* Versione ricorsiva */
    if (NULL == L) {
        return 0;
    } else {
        return (1 + list_length(L->next));
    }
}

/* Libera la memoria occupata da tutti i nodi della lista L */
void list_destroy(struct list *L) {
    /* versione ricorsiva */
    if (L != NULL) {
        list_destroy(L->next);
        L->next = NULL; /* non necessario... */
        free(L);
    }
}

/* Restituisce 1 se e solo se L e' la lista vuota, 0 altrimenti */
int is_empty(struct list *L) { return (NULL == L); }

/* Stampa il contenuto della lista L */
void list_print(struct list *L) {
    printf("(");
    while (L != NULL) {
        printf("%d ", L->val);
        L = L->next;
    }
    printf(")");
}

/* Costruisce una lista il cui contenuto e' quello di v[] */
struct list *list_from_array(int v[], int n) {
    if (0 == n) {
        return NULL;
    } else {
        return list_create(v[0], list_from_array(v + 1, n - 1));
    }
}

void test(struct list *L, int expect) {
    int v = lista_uguale(L);
    if (v == expect) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO sulla lista ");
        list_print(L);
        printf(" -- risultato atteso %d, risultato ottenuto %d\n", expect, v);
    }
}

int main(void) {
    struct list *L1 = NULL;
    struct list *L2 = list_create(31, NULL);
    struct list *L3 = list_create(31, list_create(1, NULL));

    int v4[] = {31, 31, 31, 31, 31, 30};
    struct list *L4 = list_from_array(v4, sizeof(v4) / sizeof(int));

    int v5[] = {31, 31, 31, 31, 31, 31, 31, 31};
    struct list *L5 = list_from_array(v5, sizeof(v5) / sizeof(int));

    int v6[] = {31, 47, 47, 47, 47, 47, 47, 47, 47, 47};
    struct list *L6 = list_from_array(v6, sizeof(v6) / sizeof(int));

    test(L1, 1);
    test(L2, 1);
    test(L3, 1);
    test(L4, 1);
    test(L5, 0);
    test(L6, 0);

    list_destroy(L1);
    list_destroy(L2);
    list_destroy(L3);
    list_destroy(L4);
    list_destroy(L5);
    list_destroy(L6);

    return 0;
}
