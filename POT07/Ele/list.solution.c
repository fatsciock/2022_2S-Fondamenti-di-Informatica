/* list.c : struttura dati lista */

/* Scopo di questa esercitazine e' la realizzazione delle funzioni
   segnate con [TODO] */

#include <stdio.h>
#include <stdlib.h>

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

/* Stampa i valori contenuti nei nodi di L; la lista puo' essere
   vuota. */
void list_print(struct list *L) {
    struct list *p = L;
    printf("[");
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("]\n");
}

/* Restituisce 1 se e solo se L e' la lista vuota, 0 altrimenti */
int is_empty(struct list *L) { return (L == NULL); }

/* [TODO] Restituisce una NUOVA lista con n nodi contenente i valori
   0, 1, ..., n-1 (il primo nodo della lista contiene 0, il secondo 1
   e cosi' via). Se n == 0 restituisce NULL.  SUGGERIMENTO: si puo'
   usare una soluzione ricorsiva o iterativa; nel caso di soluzione
   ricorsiva è probabilmente utile appoggiarsi ad una funzione
   ausiliaria ricorsiva:

   struct list *list_create_n_ric(int v, int n)

   che crea una lista di lunghezza n i cui nodi contengono rispettivamente
   i valori v, v+1, v+2, ... (v+n-1)
*/
struct list *list_create_n(int n) {
    /* versione iterativa; si noti come la lista viene creata a partire
       dalla fine */
    struct list *L = NULL;
    while (n > 0) {
        n--;
        L = list_create(n, L);
    }
    return L;
}

/* [TODO] restituisce un puntatore ad un nodo della lista L il cui
   campo val abbia valore k; se k non compare nella lista, restituisce
   NULL */
struct list *list_search(struct list *L, int k) {
    /* versione ricorsiva. Si presti attenzione al caso base: se
       L==NULL la seconda parte dell'"or" logico NON viene valutata,
       in quanto la condizione e' vera; e' un bene che sia cosi',
       perche' se L == NULL, la valutazione dell'espressione L->val
       causa un errore a tempo di esecuzione perche' si sta cercando
       di dereferenziare un puntatore NULL. */
    if (L == NULL || L->val == k) {
        return L;
    } else {
        return list_search(L->next, k);
    }
}

/* Versione iterativa della funzione precedente */
struct list *list_search_iter(struct list *L, int k) {
    struct list *result = L;
    while (result != NULL) {
        if (result->val == k) {
            return result;
        }
        result = result->next;
    }
    /* se arriviamo qui significa che il valore k non e' stato
       trovato */
    return NULL;
}

/* [TODO] realizzare la funzione nth_element che restituisca il
   puntatore all'n-esimo nodo della lista (n=0 e' il primo nodo, n=1
   il secondo nodo, ecc.). Se tale elemento non esiste, ad es. perche'
   la lista non ha abbastanza nodi, restituisce NULL.

   SUGGERIMENTO: si puo' adottare una soluzione iteratia o ricorsiva.
   Nel caso di una soluzione ricorsiva, i casi base sono (L==NULL)
   oppure (n==0)...
*/
struct list *nth_element(struct list *L, int n) {
    /* versione ricorsiva, basata sul ragionamento seguente:

       - se la lista L e' vuota, non esiste l'n-esimo elemento, a
         prescindere dal valore di n; ritorna quindi L (cioe' NULL);

       - altrimenti, se n == 0 ritorna un puntatore al primo nodo
         della lista;

       - altrimenti, l'n-esimo elemento di L e' l'(n-1)-esimo elemento
         di L->next, cioe' della sottolista che inizia dal secondo
         elemento di L.
    */
    if (L == NULL || n == 0) {
        return L;
    } else {
        return nth_element(L->next, n - 1);
    }
}

/* Versione iterativa della funzione precedente */
struct list *nth_element_iter(struct list *L, int n) {
    struct list *result = L;
    /* Occorre prestare attenzione al fatto che n potrebbe essere
       maggiore del numero di elementi effettivamente precenti nella
       lista.  Di conseguenza la condizione del "while" deve essere
       tale da uscire dal ciclo non appena p diventi NULL */
    while ((n > 0) && (result != NULL)) {
        result = result->next;
        n--;
    }
    return result;
}

/* [TODO] crea e restituisce il puntatore ad una nuova lista con n
   nodi, in cui il nodo i-esimo contiene il valore v[i] (il nodo 0 è
   il primo nodo della lista). SUGGERIMENTO: e' possibile realizzare
   una soluzione ricorsiva oppure iterativa. */
struct list *list_from_array(int v[], int n) {
    /* versione ricorsiva */
    if (n == 0) {
        return NULL;
    } else {
        return list_create(v[0], list_from_array(v + 1, n - 1));
    }
}

/* Versione iterativa della funzione precedente. Si noti come la lista
   venga create a ritroso. */
struct list *list_from_array_iter(int v[], int n) {
    struct list *result = NULL;
    while (n > 0) {
        n--;
        result = list_create(v[n], result);
    }
    return result;
}

/* Concatena L2 in coda a L1 e ritorna il puntatore all'inizio della
   nuova lista. Questa funzione non crea nuovi nodi, ma modifica L1 e
   L2. Al termine di questa funzione le vecchie liste non vanno piu'
   utilizzate, perche' il contenuto dei loro nodi (in particolare, dei
   puntatori al nodo successivo) possono essere cambiati. */
struct list *list_concat(struct list *L1, struct list *L2) {
    if (NULL == L1) {
        return L2;
    } else {
        if (NULL == L2) {
            return L1;
        } else {
            L1->next = list_concat(L1->next, L2);
            return L1;
        }
    }
}

/* Versione iterativa della funzione precedente: modifica il campo
   next dell'ultimo nodo di L1 per farlo puntare ad L2; il caso
   particolare in cui L1 e' la lista vuota deve essere gestito
   separatamente, dato che in questo caso non c'e' un ultimo nodo di
   L1 */
struct list *list_concat_iter(struct list *L1, struct list *L2) {
    if (NULL == L1) {
        return L2;
    } else {
        struct list *p = L1;
        /* trova l'ultimo nodo di L, che e' quello per cui p->next ==
           NULL */
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = L2;
        return L1;
    }
}

/* [TODO] Data una lista L (anche vuota), ritorna il puntatore
   all'inizio di una NUOVA lista contenente gli stessi valori di L. In
   altre parole, questa funzione deve creare un duplicato della lista
   L. La lista L non deve essere modificata. */
struct list *list_duplicate(struct list *L) {
    if (L == NULL) {
        return NULL;
    } else {
        return list_create(L->val, list_duplicate(L->next));
    }
}

struct list *list_duplicate_NO_RIC(struct list *L) {
    int n = list_length(L);
    int *tmp = (int*)malloc(n * sizeof(int));
    struct list *res = NULL;
    for(int i=0; i<n; i++) {
        tmp[i] = L->val;
        L = L->next;
    }
    return list_from_array(tmp, n);
}

/* [TODO] Restituisce 1 se e solo se le liste L1 e L2 hanno la stessa
   lunghezza, e contengono gli stessi valori nello stesso
   ordine. Questa funzione non deve modificare ne' L1 ne' L2. */
int list_equal(struct list *L1, struct list *L2) {
    if ((L1 == NULL) || (L2 == NULL)) {
        /* Se siamo qui significa che almeno una tra L1 e L2 e' vuota
           (possono esserlo entrambe). Allora le liste sono uguali se
           e solo se sono ENTRAMBE vuote */
        return ((L1 == NULL) && (L2 == NULL));
    } else {
        if (L1->val != L2->val) {
            return 0;
        } else {
            return list_equal(L1->next, L2->next);
        }
    }
}

/* [TODO] Data una lista L (anche vuota), ritorna un puntatore al
   primo nodo della lista ottenuta "rovesciando" L (l'ultimo nodo di L
   diventa il primo della nuova lista; il penultimo diventa il
   secondo, e cosi' via). Questa funzione non deve creare nuovi nodi,
   ma deve "riarrangiare" quelli di L. Dopo aver invocato questa
   funzione il puntatore all'inizio della vecchia lista L non deve
   essere utilizzato.

   SUGGERIMENTO: lasciare questa funzione per ultima, perche' non e'
   semplice come sembra. Consiglio di risolverla in modo iterativo.
*/
struct list *list_reverse(struct list *L) {
    /* L1 e' la lista originale, L2 la lista rovesciata */
    struct list *L1 = L, *L2 = NULL, *p;
    while (L1 != NULL) {
        p = L1;
        L1 = L1->next;
        p->next = L2;
        L2 = p;
    }
    return L2;
}

int main(void) {
    struct list *L1 = NULL, *L2 = NULL, *L3 = NULL, *L4 = NULL, *L5 = NULL;
    struct list *p;

    int val1[] = {1, 1, 2, 3, 5, 8, 13};
    int val2[] = {21, 34, 55};
    int i;
    const int n = 5;

    /*
     * crea la lista (0, 1, 2, 3, 4); test delle funzioni
     * list_create_n() e list_print()
     */
    L1 = list_create_n(n);
    printf("Lista L1: ");
    list_print(L1);
    printf("\n");

    /*
     * test della funzione list_search
     */
    printf("Cerchiamo il valore 2 in L1: ");
    p = list_search(L1, 2);
    if ((p != NULL) && (p->val == 2)) {
        printf("Ok, trovato!\n");
    } else {
        printf("ERRORE\n");
        return -1;
    }

    printf("Cerchiamo il valore %d in L1 (che non esiste): ", n);
    p = list_search(L1, n);
    if (p == NULL) {
        printf("Ok, non trovato!\n");
    } else {
        printf("ERRORE: restituito un nodo diverso da NULL\n");
        return -1;
    }

    /*
     * test della funzione nth_element()
     */
    for (i = 0; i < n; i++) {
        p = nth_element(L1, i);
        if ((p != NULL) && (p->val == i)) {
            printf("OK: nth_element(L1,%d) == %d\n", i, p->val);
        } else {
            printf("ERRORE: nth_element(L1,%d) ritorna ", i);
            if (p == NULL) {
                printf("NULL ");
            } else {
                printf("%d ", p->val);
            }
            printf(" anziche' %d\n", i);
            return -1;
        }
    }
    p = nth_element(L1, n);
    if (p == NULL) {
        printf("OK: nth_element(L1,%d) == NULL\n", n);
    } else {
        printf("ERRORE: nth_element(L1,%d) != NULL\n", n);
        return -1;
    }

    /*
     * Test della funzione list_from_array()
     */
    L2 = list_from_array(val1, 7);
    L3 = list_from_array(val2, 3);
    printf("L2 ha %d elementi (devono essere 7): ", list_length(L2));
    list_print(L2);
    printf("\nL3 ha %d elementi (devono essere 3): ", list_length(L3));
    list_print(L3);
    printf("\n");

    /*
     * Test della funzione list_concat()
     */
    L4 = list_concat(L2, L3);
    printf("L4 ha %d elementi (devono essere 10): ", list_length(L4));
    list_print(L4);
    printf("\n");

    /*
     * Test delle funzioni list_duplicate() e list_equal()
     */
    printf("Duplico L1 in L5\n");
    L5 = list_duplicate_NO_RIC(L1);
    printf("Lunghezza L5: %d\n", list_length(L5));
    printf("Lista L1: ");
    list_print(L1);
    printf("Lista L5: ");
    list_print(L5);
    if (list_equal(L1, L5) == 1) {
        printf("Ok: L1 e L5 sono uguali\n");
    } else {
        printf("ERRORE: L1 e L5 differiscono\n");
    }

    /*
     * Test della funzione list_reverse()
     */
    printf("Rovescio la lista L4: ");
    L4 = list_reverse(L4);
    list_print(L4);
    printf("\n");

    printf("Distruggo L1\n");
    list_destroy(L1);
    /* L2 e L3 non vanno distrutte, perche' sono confluite in L4 */
    printf("Distruggo L4\n");
    list_destroy(L4);
    printf("Distruggo L5\n");
    list_destroy(L5);

    return 0;
}
