#include <stdio.h>

struct data {
    int giorno;
    int mese;
    int anno;
};

struct persona {
    char *nome;
    char *cognome;
    char *indirizzo;
    char *citta;
    struct data datanascita;
};

void stampa(struct persona p) {
    printf("Nome=%s Cognome=%s Indirizzo=%s Citta=%s DataNascita={%d/%d/%d}\n",
           p.nome, p.cognome, p.indirizzo, p.citta, p.datanascita.giorno, p.datanascita.mese, p.datanascita.anno);
}

int main(void) {
    struct persona p1 = {"Alan", "Turing", "foo street, 42", "London", {23, 6, 1957}};
    // struct persona p1 = {"Alan", "Turing", "foo street, 42", "London", 23, 6, 1957};
    stampa(p1);
    
    struct persona p2 = { .cognome = "Turing", .nome = "Alan", .datanascita = {.anno=1957, .mese=06, .giorno=23}};
    stampa(p2);
    
    struct persona p3 = {};
    p3.nome = "Alan";
    p3.cognome = "Turing";
    p3.datanascita = (struct data){.anno=1957, .giorno=23};
    stampa(p3);
    
    struct persona p4 = {"Alan", "Turing"};
    stampa(p4);
}