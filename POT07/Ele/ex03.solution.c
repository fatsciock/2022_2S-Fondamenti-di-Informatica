#include <stdio.h>

struct corsi {
    char denominazione[20];
    char cognome[15];
    int iscritti;
};

void stampa(struct corsi p) {
    printf("denominazione=%s cognome=%s iscritti=%d\n", p.denominazione, p.cognome, p.iscritti);
}

int main(void) {
    struct corsi c[] = {
        {"a", "Bob", 50},     //
        {"b", "Alice", 20},   //
        {"c", "Eve", 30},     //
        {"d", "Charlie", 40}, //
        {"e", "Foo", 10},     //
    };

    int N = sizeof(c) / sizeof(struct corsi);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += c[i].iscritti;
    }
    printf("N: %d Somma: %d Media: %d\n", N, sum, sum / N);

    for (int i = 0; i < N; i++) {
        if (c[i].iscritti >= sum / N) {
            stampa(c[i]);
        }
    }
}