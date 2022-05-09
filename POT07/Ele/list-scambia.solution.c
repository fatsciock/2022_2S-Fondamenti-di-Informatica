/* list-scambia.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    int val;
    struct list *next;
};

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
    printf("]\n");
}

/* Restituisce 1 se e solo se L e' la lista vuota, 0
   altrimenti */
int is_empty(struct list *L) { return (L == NULL); }

/* Crea e restituisce il puntatore ad una nuova lista con n
   nodi, in cui il nodo i-esimo contiene il valore v[i] (il nodo 0 �
   il primo nodo della lista). */
struct list *list_from_array(int v[], int n) {
    if (n > 0) {
        return list_create(v[0], list_from_array(v + 1, n - 1));
    } else {
        return NULL;
    }
}

/* Restituisce 1 se le due liste sono uguali, 0 altrimenti; questa
   soluzione e' un po' piu' compatta di quella proposta
   all'esercitazione precedente. */
int list_equal(struct list *l1, struct list *l2) {
    if (is_empty(l1) || is_empty(l2)) {
        return (is_empty(l1) && is_empty(l2));
    } else {
        /* se siamo qui significa che ENTRAMBE le liste NON sono vuote */
        return ((l1->val == l2->val) && list_equal(l1->next, l2->next));
    }
}

/* REalizzare la funzione scambia(la, lb) in base alla specifica
   seguente. Se 'la' e 'lb' hanno almeno due nodi ciascuna, scambia
   gli ultimi elementi di la e lb; in altre parole, l'ultimo nodo di
   la diventa l'ultimo nodo di lb, e viceversa. Se una delle liste ha
   meno di due elementi, non fa nulla. La funzione NON DEVE creare
   nuovi nodi, ma deve modificare opportunamente i puntatori 'next'
   dei nodi esistenti. */
void scambia(struct list *la, struct list *lb) {
    if (list_length(la) > 1 && list_length(lb) > 1) {
        struct list *temp;

        /* Calcoliamo l'indirizzo di memoria del penultimo elemento di
           la; per fare questo modifichiamo il puntatore la seguendo i
           nodi fino all'ultimo */
        while ((la->next)->next != NULL) {
            la = la->next;
        }

        /* Stessa cosa per lb */
        while ((lb->next)->next != NULL) {
            lb = lb->next;
        }

        /* A questo punto la punta al penultimo elemento della prima
           lista, e lb punta al penultimo elemento della seconda
           lista. Scambiamo tra loro la->next con lb->next e abbiamo
           terminato */
        temp = la->next;
        la->next = lb->next;
        lb->next = temp;
    }
}

/* Versione ricorsiva della funzione precedente. In questo caso la
   versione ricorsiva non � molto migliore di quella iterativa, nel
   senso che non � pi� semplice da realizzare. Inoltre, la versione
   proposta qui non � efficiente perch� ad ogni chiamata ricorsiva si
   calcolano le lunghezze di la e lb mediante la funzione
   list_length(), che richiede tempo proporzionale al numero di nodi
   nelle liste. Ci� viene fatto per TUTTE le chiamate ricorsive.  E'
   possibile determinare in tempo costante se le liste hanno almeno
   due nodi usando una condizione un po' pi� complessa che viene
   lasciata come esercizio.
*/
void scambia_ric(struct list *la, struct list *lb) {
    const int lun_a = list_length(la);
    const int lun_b = list_length(lb);
    if (lun_a >= 2 && lun_b >= 2) {
        if (lun_a > 2) {
            scambia(la->next, lb);
        } else {
            if (lun_b > 2) {
                scambia(la, lb->next);
            } else {
                /* se siamo qui significa che lun_a == lun_b, ed
                   entrambe le lunghezze sono 2 */
                struct list *tmp = la->next;
                la->next = lb->next;
                lb->next = tmp;
            }
        }
    }
    /* Se una delle liste ha meno di 2 nodi non si fa niente */
}

int test(void) {
    int a[] = {10, 20, 30, 40, 50};
    struct list *la = list_from_array(a, sizeof(a) / sizeof(a[0]));

    int b[] = {1, 2, 3, 4, 5, 6, 7};
    struct list *lb = list_from_array(b, sizeof(b) / sizeof(b[0]));

    int resa[] = {10, 20, 30, 40, 7};
    struct list *lresa = list_from_array(resa, sizeof(resa) / sizeof(resa[0]));

    int resb[] = {1, 2, 3, 4, 5, 6, 50};
    struct list *lresb = list_from_array(resb, sizeof(resb) / sizeof(resb[0]));

    int c[] = {1, 2, 3};
    struct list *lc = list_from_array(c, sizeof(c) / sizeof(c[0]));

    int d[] = {4};
    struct list *ld = list_from_array(d, sizeof(d) / sizeof(d[0]));

    int resc[] = {1, 2, 3};
    struct list *lresc = list_from_array(resc, sizeof(resc) / sizeof(resc[0]));

    int resd[] = {4};
    struct list *lresd = list_from_array(resd, sizeof(resd) / sizeof(resd[0]));

    scambia(la, lb);
    scambia(lc, ld); /* Qui non deve accadere nulla */

    return list_equal(la, lresa) && list_equal(lb, lresb) &&
           list_equal(lc, lresc) && list_equal(ld, lresd);
}

int main(void) {
    printf("%s\n", test() ? "Test OK" : "Test FAILED");
    return 0;
}
