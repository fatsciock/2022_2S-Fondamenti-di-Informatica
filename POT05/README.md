# Esercizi su array e puntatori

Per ogni esercizio bisogna realizzare, oltre alle funzioni richieste, anche un `main` che ne esemplifichi il corretto funzionamento.

Nel caso in cui si decida di utilizzare come base di partenza le impalcature degli esercizi fornite dal docente, è opportuno:

- modificare i file `.c` forniti, senza crearne di nuovi

- compilare con il comando `gcc NOME_FILE.c -I. -o NOME_PROGRAMMA` e poi eseguire con `./NOME_PROGRAMMA`
    * essenziale è l'uso dell'opzione `-I.` che permette ai programmi di sfruttare le funzionalità fornite nel file `utils.h`, di cui siete invitati a prendere visione


## Esercizio 1: Palindromi

Si realizzi una funzione
```c
int is_palindrome(char *string)
```
che accetta un puntatore a char `string`.
La funzione deve restituire un intero che rappresenta il risultato booleano della valutazione della stringa: falso se `string` non è palindroma, vero altrimenti.

> È possibile usare la funzione `strlen` sita in `<string.h>`.

## Esercizio 2: Pari

### 2.a

Si realizzi la funzione
```c
void find_even(int *array, int size, int *result)
```
che accetta un puntatore di interi `array`, la sua dimensione e il puntatore alla posizione di memoria in cui depositare i risultati: `result`, che deve contenere solo gli elementi di indice pari di `array` (compreso l'elemento con indice 0).

### 2.b

Si realizzi la funzione
```c
int *get_even(int *array, int size)
```
che accetta un puntatore di interi `array` e la sua dimensione.
La funzione deve restituire un puntatore all'area di memoria allocata per un nuovo array che dovrà contenere solo gli elementi di indice pari di `array` (compreso l'elemento con indice 0).


> La funzione deve allocare la memoria per contenere i risultati.

> Si può riusare la funzione ottenuta al passo 2.a.

## Esercizio 3: Concatenazione

### 3.a

Si realizzi la funzione
```c
void string_concat(char *string1, char *string2, char *result)
```
che accetta due puntatori a carattere `string1` e `string2`, e il puntatore alla posizione di memoria in cui depositare i risultati: `result` che deve contenente la concatenazione delle due stringhe `string1` e `string2`.

### 3.b

Si realizzi la funzione
```c
char *string_concatenate(char *string1, char *string2)
```
che accetta due puntatori a carattere `string1` e `string2`.
La funzione deve restituire un puntatore all'area di memoria allocata per il nuovo array che deve contenente la concatenazione delle due stringhe `string1` e `string2`.

## Esercizio 4: Copia

### 4.a

Si realizzi la funzione
```c
void array_cp(double *array, int start, int end, double *result)
```
che accetta un puntatore a double `array`, due interi `start` e `end`, e il puntatore alla posizione di memoria in cui depositare i risultati: `result` che deve contenente la copia di `array` dall'indice `start` (incluso) all'indice `end` (escluso).

### 4.b

Si realizzi la funzione
```c
double *array_copy(double *array, int start, int end)
```
che accetta un puntatore a double `array`, due interi `start` e `end`.
La funzione deve restituire un puntatore all'area di memoria allocata per il nuovo array che deve contenente la copia di `array` dall'indice `start` (incluso) all'indice `end` (escluso).

## Esercizio 5: Rimuovi elemento

Si realizzi una funzione
```c
char *remove_element(char *string, char element)
```
che accetta un puntatore a caratteri `string` e un carattere `element`.
La funzione deve restituire un puntatore all'area di memoria allocata per il nuovo array che deve contenente gli stessi elementi di `string` ma non gli elementi uguali a `element`.

## Esercizio 6: Prodotto elemento per elemento

Si realizzi una funzione 
```c
double *element_wise_product(double *array1, double **array2, int size);
```
che, dato un array reale `array1` con dimensione `size` ed un altro array reale `array2` con stessa dimensione, computi il __prodotto elemento per elemento__ e lo restituisca.

## Esercizio 7: N multipli di M

### 7.a

Si realizzi una funzione
```c
void find_n_of_m(int n, int m, int *result)
```
che accetta due interi positivi `n` ed `m` e il puntatore alla posizione di memoria in cui depositare i risultati: `result`, che deve contenere tutti gli interi da `0` ad `n` divisibili per `m`.

> È lecito creare ulteriori funzioni d'appoggio nel caso in cui lo si ritenga necessario.

### 7.b

Si realizzi una funzione
```c
int *get_n_of_m(int n, int m)
```
che accetta due interi positivi `n` ed `m`.
La funzione deve restituire un puntatore a interi contenente tutti gli interi da `0` ad `n` divisibili per `m`.


## Esercizio 8: Lynch-Bell

### 8.a

Si realizzi una funzione
```c
void find_lynch_bell(int start, int end, int *result)
```
che accetta due interi positivi `start` ed `end` e il puntatore alla posizione di memoria in cui depositare i risultati: `result` che deve contenente i numeri di Lynch-Bell compresi tra `start` (incluso) e `end` (escluso).

> Assicurarsi che `start` < `end`.

### 8.b

Si realizzi una funzione
```c
int *get_lynch_bell(int start, int end)
```
che accetta due interi positivi `start` ed `end`.
La funzione deve restituire un puntatore a interi contenente i numeri di Lynch-Bell compresi tra `start` (incluso) e `end` (escluso).
Assicurarsi che `start` < `end`.

## Esercizio 9: Prodotto matriciale

Si realizzi una funzione 
```c
double *matrix_product(double *m1, double *m2, int m, int n, int p);
```
che, data una matrice reale `m1` con dimensioni `m*n` ed un'altra matrice reale `m2` con dimensioni `n*p`, computi il __prodotto matriciale__ (righe per colonne) tra `m1` ed `m2` e lo restituisca.

> La matrice risultante avrà dimensioni `m*p`

## Esercizio 10: DNA

Si realizzi la funzione
```c
char *dna_helix(char *sequence1, char *sequence2)
```
che accetta due puntatori a caratteri `sequence1` e `sequence2` che rappresentano due sequenze di basi azotate: `'A'`, `'C'`, `'G'`, `'T'`.
La funzione deve restituire un puntatore all'area di memoria allocata per un nuovo array di caratteri, contenente una stringa costruita come segue:

- se `sequence1` contiene `'A'` in posizione `i`-esima e `sequence2` contiene `'T'` allo stesso indice, inserire `"AT"`

- se `sequence1` contiene `'T'` in posizione `i`-esima e `sequence2` contiene `'A'` allo stesso indice, inserire `"TA"`

- se `sequence1` contiene `'C'` in posizione `i`-esima e `sequence2` contiene `'G'` allo stesso indice, inserire `"CG"`

- se `sequence1` contiene `'G'` in posizione `i`-esima e `sequence2` contiene `'C'` allo stesso indice, inserire `"GC"`

Le sotto-stringhe di 2 caratteri (`"AT"`, `"TA"`, `"CG"`, e `"GC"`), devono apparrire nel risultato separate da `'-'`, e fintanto ci sia un accoppiamento valido per formare una doppia elica di DNA.
In altre parole, si continuano a considerare solo coppie di basi azotate che rientrano nei 4 casi riportati, e, non appena c'è un caso che non rientra in quelli indicati, si termina l'analisi delle sequenze e restituisce il nuovo array contenente solo le sequenze corrette.

Le basi azotate possono apparire sia in maiuscolo che in minuscolo.

> Esempio:
>
> - sequence1 = `"aGCtAA"`
>
> - sequence2 = `"TcgAG"`
>
> - il puntatore restituito dalla funzione deve puntare all'area di memoria contenente la stringa `"aT-Gc-Cg-tA"`

## Esercizio 11: legge dei grandi numeri

Si realizzi la funzione
```c
int *k_toss(int k)
```
che accetta un intero `k`.
La funzione deve generare randomicamente `k` interi che rappresentano il risultato di un lancio di moneta (0 testa, 1 croce con stessa probabilità).
Successivamente calcolare la media delle `n` medie  (con `n`>`10.000`) del risultato della chiamata della funzione `k_toss` (con `k`>`10.000`)—chiamare `n` volte `k_toss`.

> Si presti attenzione alla quantità di memoria allocata, e si eviti in ogni momento di allocare più memoria del necessario.

## Esercizio 12: Ordinamento

Si realizzi la funzione
```c
double *sort_double(double *array, int size)
```
che accetta un puntatore a double `array` e la sua dimensione `size`.
La funzione deve restituire un puntatore all'area di memoria allocata per un nuovo array che deve contenere gli elementi di `array` ordinati dal minore al maggiore.

> Si consiglia l'uso della funzione `array_copy`.