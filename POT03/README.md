# Exercizi POT: Strutture di Controllo e Funzioni

Giovanni Ciatto

<!-- Nota per tutor POT: consiglio di compilare i sorgenti C d'esempio con `gcc NOME_FILE.c -I. -o NOME_PROGRAMMA` -->


## Esercizio 0: Funzioni d'appoggio

Si costruisca un file `utils.c` contenente le seguenti funzioni d'appoggio, __che DOVRANNO essere ri-usate nel corso dei successivi esercizi, ogni qual volta questo sia possibile__, previo copia-e-incolla:

1. `int prompt_int_greater_than(int lower_bound)`
    - che chiede all'utente di inserire un intero strettamente maggiore di `lower_bound` e lo restituisce al chiamante

1. `int prompt_int_lower_than(int upper_bound)`
    - che chiede all'utente di inserire un intero strettamente minore di `upper_bound` e lo restituisce al chiamante

1. `int prompt_int_in_range(int lower_bound, int `upper_bound)
    - che chiede all'utente di inserire un intero compreso tra `lower_bound` ed `upper_bound` (estremi __esclusi__) e lo restituisce al chiamante

1. `int prompt_int()`
    - che chiede all'utente di inserire un intero _qualsiasi_ e lo restituisce al chiamante

1. `unsigned int prompt_positive_int()`
    - che chiede all'utente di inserire un intero __senza segno__ strettamente positivo e lo restituisce al chiamante

1. `unsigned int prompt_non_negative_int()`
    - che chiede all'utente di inserire un intero __senza segno__ e __non-negativo__ e lo restituisce al chiamante

1. `unsigned int minu(unsigned int a, unsigned int b)`
    - che accetta due interi __senza segno__ `a` e `b` e restituisce solo il __minore__ dei due

1. `int min(int a, int b)`
    - che accetta due interi `a` e `b` e restituisce solo il __minore__ dei due

1. `unsigned int maxu(unsigned int a, unsigned int b)`
    - che accetta due interi __senza segno__ `a` e `b` e restituisce solo il __maggiore__ dei due

1. `int max(int a, int b)`
    - che accetta due interi `a` e `b` e restituisce solo il __maggiore__ dei due

## Esercizio: Fattoriale

Si scriva un programma `fact.c` per il computo del fattoriale di un intero qualsiasi.

L'intero dev'essere fornito dall'utente e non-negativo.

Il computo del fattoriale deve essere svolto mediante apposita funzione.
Signature suggerita:
```c
unsigned int fact(unsigned int n);
```

### Definizione di fattoriale

- `0! = 1`

- `n! = n * (n-1) * (n-2) * ... * 1`

## Esercizio: Disposizioni

Si scriva un programma `dispositions.c` per il computo delle disposizioni di `n` elemeti presi `k`-a-`k`.

Il numero `n` dev'essere un intero strettamente positivo fornito dall'utente.
Il numero `k` dev'essere un intero strettamente positivo minore o uguale a `n`.

Il computo delle disposizioni deve essere svolto mediante apposita funzione.
Signature suggerita:
```c
unsigned int dispositions(unsigned int n, unsigned int k);
```

### Definizione di disposizione

"Disposizione di `n` elementi presi `k`-a-`k` = uno dei possibili modi in cui è possibile ordinare `k` elementi presi da un insieme contenente `n` elementi.

Stando al calcolo combinatorio, dati `n > 0` e `0 < k <= n`, il numero di disposizioni possibili è `n! / (n-k)!`.

#### Esempio

Il numero di disposizioni per 14 elementi presi 2-a-2 è __182__.


## Esercizio: Fibonacci

Si scriva un programma `fib.c` per il computo dell'`n`-esimo elemento della sequenza di Fibonacci un intero qualsiasi.

L'intero dev'essere fornito dall'utente e non-negativo.

Il computo della sequenza di Fibonacci deve essere svolto mediante apposita funzione.
Signature suggerita:
```c
unsigned int fib(unsigned int n);
```

### Definizione di sequenza di Fibonacci

- `fib(0) = 1`

- `fib(1) = 1`

- `fib(n) = fib(n-1) + fib(n-2)`

## Esercizio: Massimo comun divisore, MCD (greatest common divisor, GCD)

Si scriva un programma `gcd.c` per il computo dell'MCD tra due numeri interi.

Gli interi devono essere strettamente positivi e forniti dall'utente.

Il computo del MCD deve essere svolto mediante apposita funzione.
Signature suggerita:
```c
unsigned int gcd(unsigned int n, unsigned int m);
```

### Algoritmo di Euclide per il computo del MCD

Si veda <https://www.robertobigoni.it/Matematica/euclide/euclide.html> per la spiegazione

Segue formulazione dell'algoritmo:
```
gcd(x, y) = gcd(x % y, y)    se x >= y
          | gcd(x, y % x)    se x < y
          | x                se y == 1
          | y                se x == 1
```

## Esercizio: Riconoscitore di numeri primi

Si scriva un programma `prime.c` per riconoscimento dei numeri primi.
Dato un numero intero, detto programma deve stampare `"prime"` o `"non-prime"` opportunamente.

L'intero deve essere strettamente positivo e fornito dall'utente.

Il controllo sul fatto che un numero sia o meno primo deve essere svolto mediante apposita funzione.
Signature suggerita:
```c
unsigned int is_prime(unsigned int n);
```

Detta funzione deve resitutire un numero diverso da 0 (possibilmente, 1) nel caso in cui il numero fornito come argomento sia primo, o 0 altrimenti.

### Definizione di numero primo

Un numero è primo se è divisibile solo per se stesso e per uno.
Quindi, un numero primo NON è divisibile per nessun numero tra 1 e se stesso (estremi esclusi).

## Esercizio: Classificatore di caratteri

Si scriva un programma `char-classifier.c` per la classificazione dei caratteri.
Dato un carattere qualsiasi, detto programma deve stampare:

- `"Character %d is a non-printable"` se il carattere non è stampabile (si veda sotto per definizione)

- `"'%c' is a blank character"` se il carattere è uno spazio bianco (`' '`)

- `"'%c' is a digit"` se il carattere è un numero da `'0'` a `'9'`

- `"'%c' is a lowercase letter"` se il carattere è una lettera minuscola da `'a'` a `'z'`

- `"'%c' is an uppercase letter"` se il carattere è una lettera maiuscola da `'A'` a `'Z'`

- `"'%c' is a symbolic character"` se il carattere è un simbolo di punteggiatura, una parentesi o un simbolo stampabile di altro genere

Il carattere dev'essere fornito dall'utente.

La classificazione del carattere dev'essere svolta mediante apposita funzione
Signature suggerita:
```c
int classify(char c):
```

Detta funzione deve restituire:
- `0` se il carattere è non stampabile (si veda sotto per definizione)
- `1` se il carattere è uno spazio bianco (`' '`)
- `2` se il carattere è un simbolo di punteggiatura, una parentesi o un simbolo stampabile di altro genere
- `3` se il carattere è un numero da `'0'` a `'9'` 
- `4` se il carattere è una lettera maiuscola da `'A'` a `'Z'`
- `5` se il carattere è una lettera minuscola da `'a'` a `'z'` 

Si suggerisce di impiegare delle costanti con dei nomi intellegibili.

### Definizione caratteri stampabili

Si faccia riferimento a questa pagina: <https://it.wikipedia.org/wiki/ASCII#Tabella_dei_caratteri>

Si noti che i caratteri aventi valore decimale da `0` a `31` o `127` __non sono stampabili__, ergo tentare di visualizzarli con `printf("%c", $character)` potrebbe dare luogo a visualizzazioni diverse da ciò che ci si potrebbe aspettare. 
Si usi piuttosto `printf("%d", $character)` per stampare il valore decimale corrispondente al carattere, che, essendo un numero, è sicuramente visualizzabile.

## Esercizio: Gradiente

Si scriva un programma `gradient.c` capace di rappresentare figure come quella sottostante.

Dato un numero `n` il programma stampa `n` righe, ognuna contentemente `n` caratteri.
Il `j`-esimo carattere della riga `i`-esima deve rappresentare il quadrato della norma euclida del vettore `(j, i)` sito in un piano avente l'asse delle ordinate invertito (dall'alto verso il basso).

Essendo `max = 2 * n * n` il valore massimo che il quadrato della norma `x = i*i + j*j` del vettore `(j, i)` può assumere in questo scenario, la rappresentazione creata dal programma per il `j`-esimo carattere della riga `i`-esima deve essere:
- `'.'` se `x < (max / 4)`
- `'o'` se `x < (max / 2)
- `'O'` se `x < (3 * max / 4)`
- `'X'` altrimenti

Si consiglia di realizzare una funzione apposita per il calcolo del quadrato della norma, ed un'altra funzione per il calcolo della sua rappresentazione sotto forma di carattere.

### Esempio di rappresentazione

Per `n` pari a `50`:
```
....................................oooooooooooooo
....................................oooooooooooooo
....................................oooooooooooooo
....................................oooooooooooooo
....................................oooooooooooooo
...................................ooooooooooooooo
...................................ooooooooooooooo
...................................ooooooooooooooo
...................................ooooooooooooooo
...................................ooooooooooooooo
..................................oooooooooooooooO
..................................oooooooooooooooO
..................................oooooooooooooooO
.................................ooooooooooooooooO
.................................oooooooooooooooOO
.................................oooooooooooooooOO
................................ooooooooooooooooOO
...............................oooooooooooooooooOO
...............................ooooooooooooooooOOO
..............................oooooooooooooooooOOO
..............................ooooooooooooooooOOOO
.............................oooooooooooooooooOOOO
............................oooooooooooooooooOOOOO
...........................ooooooooooooooooooOOOOO
..........................ooooooooooooooooooOOOOOO
.........................oooooooooooooooooooOOOOOO
........................oooooooooooooooooooOOOOOOO
.......................ooooooooooooooooooooOOOOOOO
......................ooooooooooooooooooooOOOOOOOO
.....................ooooooooooooooooooooOOOOOOOOO
...................oooooooooooooooooooooOOOOOOOOOO
.................oooooooooooooooooooooooOOOOOOOOOO
................oooooooooooooooooooooooOOOOOOOOOOO
.............oooooooooooooooooooooooooOOOOOOOOOOOO
..........oooooooooooooooooooooooooooOOOOOOOOOOOOO
.....oooooooooooooooooooooooooooooooOOOOOOOOOOOOOO
oooooooooooooooooooooooooooooooooooOOOOOOOOOOOOOOO
ooooooooooooooooooooooooooooooooooOOOOOOOOOOOOOOOX
oooooooooooooooooooooooooooooooooOOOOOOOOOOOOOOOOX
ooooooooooooooooooooooooooooooooOOOOOOOOOOOOOOOOXX
ooooooooooooooooooooooooooooooOOOOOOOOOOOOOOOOOXXX
oooooooooooooooooooooooooooooOOOOOOOOOOOOOOOOOXXXX
ooooooooooooooooooooooooooooOOOOOOOOOOOOOOOOOXXXXX
ooooooooooooooooooooooooooOOOOOOOOOOOOOOOOOOXXXXXX
ooooooooooooooooooooooooOOOOOOOOOOOOOOOOOOOXXXXXXX
ooooooooooooooooooooooOOOOOOOOOOOOOOOOOOOOXXXXXXXX
ooooooooooooooooooooOOOOOOOOOOOOOOOOOOOOOXXXXXXXXX
ooooooooooooooooooOOOOOOOOOOOOOOOOOOOOOOXXXXXXXXXX
ooooooooooooooOOOOOOOOOOOOOOOOOOOOOOOOOXXXXXXXXXXX
ooooooooooOOOOOOOOOOOOOOOOOOOOOOOOOOOXXXXXXXXXXXXX
```