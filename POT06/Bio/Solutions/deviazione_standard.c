/* compito 1 -- deviazione_standard.c */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* FUNZIONE DA REALIZZARE
   ======================

   La deviazione standard di un insieme di n>=2 valori x[0], x[1],
   ... x[n-1] si calcola come:
        _____________________________________________
       /
      / (x[0] - x_mean)^2 + ... + (x[n-1] - x_mean)^2
  \  /  ---------------------------------------------
   \/                    n - 1

   dove x_mean e' la media aritmetica dei valori x[], e "^" indica
   l'elevamento a potenza (ricordiamo che in C non esiste un operatore
   predefinito per l'elevamento a potenza). La media aritmetica e' la
   somma dei valori di x[], divisa per n. Per calcolare la radice
   quadrata di un valore v di tipo double si puo' usare la funzione

   double sqrt( double v )

   definita in math.h (gia' incluso in questo file).

   Realizzare la funzione dev_std(x, n) che dato un array x[] di
   double di lunghezza n, restituisce la deviazione standard dei
   valori in x[] calcolata mediante la formula sopra. Si garantisce
   che si avra' sempre n>=2.

   Prestare attenzione al fatto che i test inclusi in questo programma
   non possono essere affidabili al 100%, in quanto il risultato della
   funzione dipende dall'ordine con cui si eseguono le operazioni in
   virgola mobile. Potrebbe quindi accadere (ma ritengo sia molto
   improbabile) che una funzione corretta non superi i test. In ogni
   caso tutti i programmi consegnati vengono sempre controllati
   "manualmente" dai docenti, proprio per individuare situazioni del
   genere.
*/
double dev_std(double *x, int n) {
    double x_mean, x_sum = 0.0, sumsq = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        x_sum += x[i];
    }
    x_mean = x_sum / n;
    for (i = 0; i < n; i++) {
        sumsq += (x[i] - x_mean) * (x[i] - x_mean);
    }
    return sqrt(sumsq / (n - 1));
}

void test(double *x, int n, double expect) {
    /* Si controlla che il risultato atteso e quello ottenuto
       differiscano, in valore assoluto, per meno di epsilon; in caso
       contrario si segnala errore */
    const double epsilon = 1e-3;
    double r = dev_std(x, n);
    if (fabs(r - expect) < epsilon) {
        printf("Test OK\n");
    } else {
        printf("Test FALLITO: risultato atteso %f, risultato ottenuto %f\n", expect, r);
    }
}

int main(void) {
    double x1[] = {1.0, 1.0, 1.0, 1.0, 1.0};
    double x2[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    double x3[] = {-1.0, 1.0, -1.0, 1.0, -1.0, 1.0};
    double x4[] = {727.7, 1086.5, 1091.0, 1361.3, 1490.5, 1956.1};

    printf("=== Inizio test ===\n");
    test(x1, sizeof(x1) / sizeof(double), 0.0);
    test(x2, sizeof(x2) / sizeof(double), 1.8708);
    test(x3, sizeof(x3) / sizeof(double), 1.0954);
    test(x4, sizeof(x4) / sizeof(double), 420.9625);
    printf("=== Fine test ===\n");
    return 0;
}
