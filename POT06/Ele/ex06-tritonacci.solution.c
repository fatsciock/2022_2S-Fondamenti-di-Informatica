/* tritonacci.c */
#include <stdio.h>
#include <stdlib.h>

/* FUNZIONE DA REALIZZARE
   ======================

   La successione di "tritonacci" e' definita in modo simile alla
   successione di Fibonacci, con la differenza che ogni termine della
   successione di tritonacci e' dato dalla somma dei TRE valori
   precedenti (anziche' due come nella successione di Fibonacci).
   Formalmente, la successione di tritonacci T(1), T(2), T(3),
   ... T(n) ... e' definita come segue:

   T(1) = 1
   T(2) = 1
   T(3) = 1
   T(n) = T(n-1) + T(n-2) + T(n-3) se n>3

   Quindi la successione di tritonacci e' 1, 1, 1, 3, 5, 9, 17, 31,
   57, ...

   Realizzare la funzione tritonacci(n) che restituisce l'n-esimo
   numero di Tritonacci.

   Suggerimento: l'implementazione ricorsiva basata sulla definizione
   e' troppo lenta per completare tutti i test (perche'?). Occorre
   quindi pensare ad una implementazione iterativa piu' efficace.
*/

/* Questa e' una implementazione ricorsiva basata direttamente sulla
   definizione della successione di "tritonacci", che pero' richiede
   troppo tempo gia' per valori moderati di n. Si puo' dimostrare, in
   modo analogo alla successione di Fibonacci, che questa funzione
   richiede tempo esponenziale in n. */
int tritonacci(int n) {
    if (n <= 3) {
        return 1;
    } else {
        return tritonacci(n - 1) + tritonacci(n - 2) + tritonacci(n - 3);
    }
}

/* Questa e' la versione iterativa della funzione precedente. Si
   tratta di una semplice estensione del calcolo iterativo della
   successione di Fibonacci vista a lezione. Usiamo tre variabili t1,
   t2, t3 per memorizzare i tre numeri precedenti della successione di
   Tritonacci, in modo da poter calcolare quello successivo. */
int tritonacci2(int n) {
    if (n <= 3) {
        return 1;
    } else {
        int t1, /* T(n-1) */
            t2, /* T(n-2) */
            t3, /* T(n-3) */
            tn; /* T(n)   */
        int i;
        t1 = t2 = t3 = 1;
        for (i = 4; i <= n; i++) {
            tn = t1 + t2 + t3;
            t3 = t2;
            t2 = t1;
            t1 = tn;
        }
        return tn;
    }
}

/* Questa e' una implementazione un po' piu' diretta della versione
   iterativa precedente. Usiamo un array T[0..n+1] per calcolare gli
   elementi della successione di Tritonacci; per evitare complicazioni
   con gli indici, usiamo solo gli elementi da T[1] a T[n] dell'array,
   e non usiamo T[0]. Si nodi che questa versione e' un po' meno
   efficiente di quella precedente, perche' qui dobbiamo usare un
   array temporaneo di (n+1) elementi, e quindi e' richiesta una
   occupazione di memoria proporzionale a n, mentre nella versione
   precedente no. */
int tritonacci3(int n) {
    if (n <= 3) {
        return 1;
    } else {
        int *T = (int *)malloc((n + 1) * sizeof(int));
        int result, i;
        T[1] = T[2] = T[3] = 1;
        for (i = 4; i <= n; i++) {
            T[i] = T[i - 1] + T[i - 2] + T[i - 3];
        }
        result = T[n];
        free(T); /* liberiamo lo spazio occupato da T, dato che non ci
                    serve piu'. Notare che PRIMA di liberare lo spazio
                    ci siamo salvati nella variabile result il valore
                    di T[n]; infatti una volta fatto free(T), l'array
                    non e' piu' disponibile e tentare di leggerne il
                    contenuto causa un comportamento indefinit. */
        return result;
    }
}

void test(int n, int expect) {
    int v = tritonacci2(n); /* oppure tritonacci(n), oppure tritonacci3(n) */
    printf("tri(%d)=%d -- ", n, v);
    if (v == expect) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: risultato atteso %d\n", expect);
    }
}

int main(void) {
    test(1, 1);
    test(2, 1);
    test(3, 1);
    test(4, 3);
    test(5, 5);
    test(6, 9);
    test(7, 17);
    test(8, 31);
    test(9, 57);
    test(15, 2209);
    test(20, 46499);
    test(30, 20603361);
    test(35, 433695873);
    test(40, 539260895);
    return 0;
}
