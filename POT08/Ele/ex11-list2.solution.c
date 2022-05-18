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

   Realizzare la funzione scambia qui sotto riportata che prese in
   ingresso due liste non vuote, ne scambia le code a partire dal
   primo zero in poi (se esiste). Non bisogna creare nuove liste,
   quindi non si puo' usare la funzione list_create(): e' invece
   necessario riusare i nodi esistenti modificando opportunamente i
   puntatori.
*/
void scambia(struct list *a, struct list *b) {
    struct list *tmp;

    /* determiniamo la posizione (indirizzo di memoria) in a e b del
       nodo che contiene il primo zero, oppure dell'ultimo nodo della
       lista se non c'e' un nodo contenente zero. */
    while (a && a->val != 0) {
        a = a->next;
    }

    while (b && b->val != 0) {
        b = b->next;
    }

    if (!a || !b)
        return;

    /* ora siamo nella situazione seguente:

              a--+   a->next--+
                 V            V
                +---+   +----------+
       -> ... ->| 0 |-> |resto di a|
                +---+   +----------+

              b--+   b->next--+
                 V            V
                +---+   +----------+
       -> ... ->| 0 |-> |resto di b|
                +---+   +----------+

     */
    tmp = a->next;
    a->next = b->next;
    b->next = tmp;
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
    if (NULL == L) {
        return 0;
    } else {
        return (1 + list_length(L->next));
    }
}

/* Libera la memoria occupata da tutti i nodi della lista L */
void list_destroy(struct list *L) {
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

/* Restituisce 1 se e solo se L e' la lista vuota, 0
   altrimenti */
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

/* Restituisce 1 se e solo se le due liste sono uguali, 0 in caso
   contrario*/
int list_equal(struct list *l1, struct list *l2) {
    if (is_empty(l1) || is_empty(l2)) {
        return (is_empty(l1) && is_empty(l2));
    } else {
        return ((l1->val == l2->val) && list_equal(l1->next, l2->next));
    }
}

void test(struct list *la, struct list *lb, struct list *expecta,
          struct list *expectb) {
    scambia(la, lb);
    if (list_equal(la, expecta) && list_equal(lb, expectb)) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO\n");
    }
}

int main(void) {
    int a[] = {10, 20, 0, 40, 50};
    struct list *la = list_from_array(a, sizeof(a) / sizeof(a[0]));
    int b[] = {1, 2, 3, 0, 5, 6, 7};
    struct list *lb = list_from_array(b, sizeof(b) / sizeof(b[0]));
    int resa[] = {10, 20, 0, 5, 6, 7};
    struct list *lresa = list_from_array(resa, sizeof(resa) / sizeof(resa[0]));
    int resb[] = {1, 2, 3, 0, 40, 50};
    struct list *lresb = list_from_array(resb, sizeof(resb) / sizeof(resb[0]));

    int c[] = {0};
    struct list *lc = list_from_array(c, sizeof(c) / sizeof(c[0]));
    int d[] = {2};
    struct list *ld = list_from_array(d, sizeof(d) / sizeof(d[0]));
    int resc[] = {0};
    struct list *lresc = list_from_array(resc, sizeof(resc) / sizeof(resc[0]));
    int resd[] = {2};
    struct list *lresd = list_from_array(resd, sizeof(resd) / sizeof(resd[0]));

    int e[] = {10, 20, 30, 0};
    struct list *le = list_from_array(e, sizeof(e) / sizeof(e[0]));
    int f[] = {0, 1, 2};
    struct list *lf = list_from_array(f, sizeof(f) / sizeof(f[0]));
    int rese[] = {10, 20, 30, 0, 1, 2};
    struct list *lrese = list_from_array(rese, sizeof(rese) / sizeof(rese[0]));
    int resf[] = {0};
    struct list *lresf = list_from_array(resf, sizeof(resf) / sizeof(resf[0]));

    int g[] = {10, 20, 30, 0, 60};
    struct list *lg = list_from_array(g, sizeof(g) / sizeof(g[0]));
    int h[] = {1, 2};
    struct list *lh = list_from_array(h, sizeof(h) / sizeof(h[0]));
    int resg[] = {10, 20, 30, 0, 60};
    struct list *lresg = list_from_array(resg, sizeof(resg) / sizeof(resg[0]));
    int resh[] = {1, 2};
    struct list *lresh = list_from_array(resh, sizeof(resh) / sizeof(resh[0]));

    test(la, lb, lresa, lresb);
    test(lc, ld, lresc, lresd);
    test(le, lf, lrese, lresf);
    test(lg, lh, lresg, lresh);

    return 0;
}
