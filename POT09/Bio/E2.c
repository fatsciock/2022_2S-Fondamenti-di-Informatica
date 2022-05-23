/* 1_pangramma.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FUNZIONE DA REALIZZARE
   ======================

   Un pangramma e' una frase in cui ognuna delle 26 lettere minuscole
   dell'alfabeto inglese compare almeno una volta (eventuali spazi,
   numeri e altri segni di punteggiatura devono essere ignorati). Ad
   esempio, le frasi seguenti sono dei pangrammi:

   "pack my box with five dozen liquor jugs."

   "jackdaws love my big sphinx of quartz."

   "the five boxing wizards jump quickly."

   Realizzare la funzione pangramma() riportata sotto. La funzione
   accetta in input una stringa s, e restituisce 1 se e solo se s e'
   un pangramma, cioe' ognuna delle 26 lettere minuscole dell'alfabeto
   inglese compare almeno una volta, 0 altrimenti. Si garantisce che
   in s non siano mai presenti lettere maiuscole; pssono pero' essere
   presenti spazi, numeri e altri segni di punteggiatura, che devono
   essere ignorati.

   Se lo si ritiene utile e' possibile usare le funzioni definite
   in <string.h>, come ad esempio strlen(). E' anche possibile
   definire ulteriori funzioni.

   Si ricorda che una funzione che supera i test non e' necessariamente
   corretta.
*/

int pangramma(char *s) {
    /* Utilizziamo un array c[26] di interi, i cui valori sono
       inizialmente tutti posti a zero.  Scorriamo la stringa s
       ignorando i caratteri che non sono lettere minuscole. Il valore
       c[i] vale uno se e solo se abbiamo visto almeno una occorrenza
       del carattere ('a' + i) (quindi c[0] == 1 se e solo se abbiamo
       visto almeno una lettera 'a', c[1] == 1 se e solo se abbiamo
       visto almeno una lettera 'b', ... c[25] == 1 se e solo se
       abbiamo visto almeno una volta una lettera 'z'). Alla fine
       della scansione della stringa, si controllano i valori di c[].
       Se sono tutti 1 significa che abbiamo visto almeno una volta
       una occorrenza di ogni carattere; Se invece esiste uno zero in
       c[] significa che c'e' almeno un carattere che non compare mai,
       quindi s non e' un pangramma.

       Nella soluzione mostrata sotto utilizziamo uno stratagemma per
       evitare di fare il controllo finale dell'array c[].
       Utilizziamo un contatore m, inizialmente con valore 26, che
       indica il numero di caratteri che NON abbiamo ancora incontrato
       nella stringa s. Ogni volta che incontriamo un nuovo carattere,
       dopo aver posto a 1 il corrispondente valore in c[],
       decrementiamo m. Al termine della scansione di s avremo che m
       == 0 se e solo se abbiamo incontrato almeno una volta tutti i
       26 caratteri dell'alfabeto.
    */
    int c[26] = {0};
    int m = 26; /* numero di lettere che non sono ancora state viste */
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            const int idx = s[i] - 'a';
            if (0 == c[idx]) {
                /* abbiamo incontrato il carattere s[i] per la prima volta */
                c[idx] = 1;
                m--;
            }
        }
    }
    return (0 == m);
}

void test(char *s, int expect) {
    int r = pangramma(s);
    if (r == expect) {
        printf("Test OK -- \"%s\"\n", s);
    } else {
        printf("Test FALLITO -- \"%s\" risultato atteso %d, risultato ottenuto %d\n", s, expect, r);
    }
}

int main(void) {
    test("pack my box with five dozen liquor jugs.", 1);
    test("jackdaws love my big sphinx of quartz.", 1);
    test("the five boxing wizards jump quickly.", 1);
    test("how vexingly quick daft zebras jump!", 1);
    test("bright vixens jump; dozy fowl quack.", 1);
    test("sphinx of black quartz, judge my vow.", 1);
    test("the quick brown fox jumps over the lazy dog.", 1);
    test("the wizard quickly jinxed the gnomes before they vaporized.", 1);
    test("quel vituperabile xenofobo zelante assaggia il whisky ed esclama: alleluja!", 1);
    test("let there be light!", 0);
    test("short pangrams in english are more difficult to come up with and tend to use uncommon words.", 0);
    test("many english sentences are not pangrams, as can easily be verified.", 0);
    test("", 0);
    test("abcdefghijklmnopprstuvwxyz", 0);
    return 0;
}
