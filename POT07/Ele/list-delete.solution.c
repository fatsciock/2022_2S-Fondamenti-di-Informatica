/* list-delete.c

   ATTENZIONE: sono state fatte alcune modifiche rispetto alla
   versione pubblicata durante l'esercitazione.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    int val;
    struct list *next;
};

/* Crea (mediante malloc()) e restituisce un puntatore ad un nuovo
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

/* restituisce 1 se e solo se le due liste sono uguali, 0 altrimenti */
int list_equal(struct list *l1, struct list *l2) {
    if (is_empty(l1) && is_empty(l2)) {
        return 1;
    }
    if (!is_empty(l1) && !is_empty(l2) && l1->val == l2->val) {
        return list_equal(l1->next, l2->next);
    }
    return 0;
}

/* Data una lista e un intero k, cancella dalla lista (liberando anche
   la memoria con la \texttt{free()} ) tutti i nodi che contengono k,
   se ce ne sono. La funzione restituisce un puntatore all'inizio
   della lista eventualmente modificata. Si presti attenzione al fatto
   che il programma NON deve creare una nuova lista, ma deve
   modificare quella passata come parametro. Si suggerisce di adottare
   un approccio ricorsivo, perche' in questo caso produce la soluzione
   piu' semplice. */
struct list *list_delete_k(struct list *L, int k) {
    /* Spiegazione: la lista ottenuta rimuovendo tutte le occorrenze
       di k da L �:

       1. la lista vuota, se L � vuota;

       2. oppure:

       2.a la lista ottenuta rimuovendo da L->next tutte le occorrenze
       di k, se il primo elemento di L contiene k;

       2.b la lista ottenuta concatenando al primo elemento di L ci�
       che si ottiene rimuovendo k dal resto di L;
    */
    if (L == NULL) {
        /* caso 1. */
        return NULL;
    } else {
        if (L->val == k) {
            /* caso 2.a */
            struct list *next = L->next;
            free(L);
            return list_delete_k(next, k);
        } else {
            /* caso 2.b */
            L->next = list_delete_k(L->next, k);
            return L;
        }
    }
}

/**
 * Versione iterativa della funzione precedente. Come si pu� notare,
 * questa versione � molto pi� complessa da realizzare rispetto a
 * quella ricorsiva, per cui � facile sbagliare. Si faccia riferimento
 * ai commenti nel codice per capirne il funzionamento.
 */
struct list *list_delete_k_iter(struct list *L, int k) {
    /*
      - 'cur' indica il nodo corrente della lista; se il nodo corrente
        contiene il valore k, verr� rimosso dalla lista, altrimenti
        verr� lasciato inalterato e si passa al nodo successivo.

      - 'prev' � il nodo precedente a quello corrente. Ci serve per
        poter rimuovere il nodo 'cur' dalla lista (vedi oltre)

      - 'result' � il risultato, cioe' il puntatore al primo nodo che
        contiene un valore diverso da k della lista (se esiste,
        altrimenti vale NULL).
    */

    struct list *result = NULL;
    struct list *prev = NULL, *cur = L;
    while (cur != NULL) {
        if (cur->val == k) {
            /* Dobbiamo rimuovere il nodo corrente 'cur'. Se il nodo
               precedente ('prev') � diverso da NULL, significa che
               siamo nella situazione seguente:

               prev      cur     succ
                 |        |        |
                 V        V        V
               +---+    +---+    +---+
               |   +--->+   +--->+   +
               +---+    +---+    +---+

            */
            struct list *succ = cur->next;
            free(cur);
            /* Dopo aver deallocato il nodo 'cur', la situazione diventa:

               prev      cur     succ
                 |        |        |
                 V        V        V
               +---+    +---+    +---+
               |   +--->+///|    |   +
               +---+    +---+    +---+
            */
            if (prev != NULL) {
                prev->next = succ;
                /* Dopo aver eseguito l'istruzione prev->next = succ
                   la situazione diventa:

                  prev      cur     succ
                    |        |        |
                    V        V        V
                  +---+    +---+    +---+
                  |   +-+  |///|  +>+   +
                  +---+ |  +---+  | +---+
                        +---------+

                  Nota: questa istruzione deve essere eseguita solo se
                  il predecessore 'prev' esiste; se 'prev' vale NULL,
                  non esiste precedessore del nodo corrente, quindi
                  non c'� nulla da fare.
                */
            }
            /* Facciamo avanzare il nodo corrente (quello che abbiamo
               appena cancellato) al successivo. Si noti che qui non
               possiamo scrivere cur = cur->next, perch� 'cur' � stato
               deallocato mediante la free() e il suo contenuto �
               indefinito. Fortunatamente ci eravamo salvati
               l'indirizzo del nodo successivo nella variabile
               'succ' */
            cur = succ;
        } else {
            /* Se siamo qui significa che il nodo corrente NON
               contiene il valore k.

               Il risultato � il puntatore al primo nodo che non
               contiene k. Se la variabile 'result' vale NULL,
               significa che questo nodo � il primo nodo che non
               contiene k che abbiamo incontrato, e diventa quindi il
               risultato */
            if (result == NULL) {
                result = cur;
            }
            /* Il nodo precedente diventa quello corrente... */
            prev = cur;
            /* ...e il nodo corrente viene fatto avanzare al
               successivo */
            cur = cur->next;
        }
    }
    return result;
}

/* Altra soluzione iterativa, diversa dalla precedente e probabilmente
   pi� leggibile. La funzione list_delete_k_iter2() sotto fa uso di
   una funzione ausiliaria remove_front(L, k) che data una lista L
   (che pu� anche essere vuota), rimuove tutti i nodi contenenti k che
   si trovano _all'inizio di L_. La funzione ritorna il puntatore al
   primo nodo della lista che NON contiene k, oppure NULL se la lista
   finisce. */
struct list *remove_front(struct list *L, int k) {
    while (L != NULL && L->val == k) {
        struct list *succ = L->next;
        free(L);
        L = succ;
    }
    return L;
}

struct list *list_delete_k_iter2(struct list *L, int k) {
    /* Il risultato restituito da questa funzione � il primo nodo di L
       che non contiene k, che � esattamente quanto viene restituito
       dalla funzione ausiliaria remove_front(L, k) */
    struct list *result = remove_front(L, k);
    L = result;
    while (L != NULL) {
        /* Rimuoviamo dalla sottolista che inizia da L->next tutte le
           occorrenze iniziali di k; L->next punta quindi al primo
           nodo successivo che NON contiene k, oppure alla fine della
           lista */
        L->next = remove_front(L->next, k);
        L = L->next;
    }
    return result;
}

int test(void) {
    int a[] = {10, 20, 30, 10, 15, 21, 40, 10};
    struct list *la = list_from_array(a, sizeof(a) / sizeof(a[0]));
    int resa[] = {20, 30, 15, 21, 40};
    struct list *lresa = list_from_array(resa, sizeof(resa) / sizeof(resa[0]));

    int b[] = {1, 2, 2, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1};
    struct list *lb = list_from_array(b, sizeof(b) / sizeof(b[0]));
    int resb[] = {1, 3, 4, 5, 6, 7, 6, 5, 4, 3, 1};
    struct list *lresb = list_from_array(resb, sizeof(resb) / sizeof(resb[0]));

    int c[] = {100, 200, 300};
    struct list *lc = list_from_array(c, sizeof(c) / sizeof(c[0]));
    int resc[] = {100, 200, 300};
    struct list *lresc = list_from_array(resc, sizeof(resc) / sizeof(resc[0]));

    int d[] = {100, 100, 100};
    struct list *ld = list_from_array(d, sizeof(d) / sizeof(d[0]));
    struct list *lresd = NULL;

    return list_equal(list_delete_k(la, 10), lresa) &&
           list_equal(list_delete_k(lb, 2), lresb) &&
           list_equal(list_delete_k(lc, 10), lresc) &&
           list_equal(list_delete_k(ld, 100), lresd) &&
           list_equal(list_delete_k(NULL, 10), NULL);
}

int main(void) {
    printf("Test: %s\n", test() ? "Test OK" : "Test FAILED");
    return 0;
}
