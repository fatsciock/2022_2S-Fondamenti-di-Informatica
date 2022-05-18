#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    int val;
    struct list *next;
};

struct list *list_create(int v, struct list *t);
int list_length(struct list *L);
void list_destroy(struct list *L);
void list_print(struct list *L);
int is_empty(struct list *L);
struct list *list_from_array(int v[], int n);
int list_equal(struct list *l1, struct list *l2);

/*
   FUNZIONE DA REALIZZARE
   ======================

   Si realizzi la funzione sottostante che presa in ingresso una lista
   che contiene almeno uno zero, e detta "i" la posizione del primo
   zero (si assuma non sia il primo elemento della lista), modifica il
   contenuto della lista ponendo a zero tutti gli elementi
   dall'(i-1)-esimo fino all'ultimo, cioe' dalla posizione
   _precedente_ il primo zero fino alla fine della lista.
*/
void f(struct list *l) {
    struct list *l1 = l;

    /* determiniamo il puntatore l1 al nodo di l che _precede_ il
       primo nodo della lista che vale zero. Si noti che il test
       l1->next!=NULL non sarebbe strettamente necessario, perche' e'
       garantito che in l sia sempre presente almeno un nodo
       contenente zero; e' comunque una buona idea metterlo lo stesso,
       in modo da avere la garanzia che (l1->next)->val non possa mai
       dereferenziare un puntatore NULL. */
    while (l1->next != NULL && ((l1->next)->val != 0)) {
        l1 = l1->next;
    }

    if (l1 && !l1->next)
        return;

    /* ora azzeriamo il contenuto di tutti i nodi da l1 fino alla fine
       della lista */
    while (l1 != NULL) {
        l1->val = 0;
        l1 = l1->next;
    }
}

/* Crea (mediante malloc() ) e restituisce un puntatore ad un nuovo
   nodo di una lista; il nodo contiene il valore v e punta a t come
   elemento successivo. Il chiamante e' responsabile per deallocare
   mediante free() o simili il blocco di memoria restituita da questa
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

/* Stampa i valori contenuti nei nodi di L; si puo' avere L ==
   NULL. */
void list_print(struct list *L) {
    printf("[");
    while (L != NULL) {
        printf("%d ", L->val);
        L = L->next;
    }
    printf("]");
}

/* Restituisce 1 se e solo se L e' la lista vuota, 0 altrimenti */
int is_empty(struct list *L) { return (L == NULL); }

/* Crea e restituisce il puntatore ad una nuova lista con n
   nodi, in cui il nodo i-esimo contiene il valore v[i] (il nodo 0 �
   il primo nodo della lista). */
struct list *list_from_array(int v[], int n) {
    if (n == 0) {
        return NULL;
    } else {
        return list_create(v[0], list_from_array(v + 1, n - 1));
    }
}

/* La funzione restituisce 1 se e solo se le due liste sono uguali, 0
   in caso contrario*/
int list_equal(struct list *l1, struct list *l2) {
    if (is_empty(l1) || is_empty(l2)) {
        return (is_empty(l1) && is_empty(l2));
    } else {
        return ((l1->val == l2->val) && list_equal(l1->next, l2->next));
    }
}

void test(struct list *l, struct list *expect) {
    f(l);
    if (list_equal(l, expect)) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: risultato atteso ");
        list_print(expect);
        printf(", risultato ottenuto ");
        list_print(l);
        printf("\n");
    }
}

int main(void) {
    int a[] = {10, 20, 30, 0, 40, 50};
    struct list *la = list_from_array(a, sizeof(a) / sizeof(a[0]));
    int resa[] = {10, 20, 0, 0, 0, 0};
    struct list *lresa = list_from_array(resa, sizeof(resa) / sizeof(resa[0]));

    int b[] = {10, 20, 30, 40, 0};
    struct list *lb = list_from_array(b, sizeof(b) / sizeof(b[0]));
    int resb[] = {10, 20, 30, 0, 0};
    struct list *lresb = list_from_array(resb, sizeof(resb) / sizeof(resb[0]));

    int c[] = {10, 0, 30, 40, 50};
    struct list *lc = list_from_array(c, sizeof(c) / sizeof(c[0]));
    int resc[] = {0, 0, 0, 0, 0};
    struct list *lresc = list_from_array(resc, sizeof(resc) / sizeof(resc[0]));

    int d[] = {10, 0};
    struct list *ld = list_from_array(d, sizeof(d) / sizeof(d[0]));
    int resd[] = {0, 0};
    struct list *lresd = list_from_array(resd, sizeof(resd) / sizeof(resd[0]));

    int e[] = {10};
    struct list *le = list_from_array(e, sizeof(e) / sizeof(d[0]));
    int rese[] = {10};
    struct list *lrese = list_from_array(rese, sizeof(rese) / sizeof(resd[0]));

    test(la, lresa);
    test(lb, lresb);
    test(lc, lresc);
    test(ld, lresd);
    test(le, lrese);

    return 0;
}
