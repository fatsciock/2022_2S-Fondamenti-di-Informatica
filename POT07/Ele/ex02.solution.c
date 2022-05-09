#include <stdio.h>

struct misuraUK {
    int miglia;
    int yarde;
    int piedi;
    int pollici;
};

struct misuraEU {
    int km;
    int m;
    int mm;
};

void stampa(struct misuraEU p) {
    printf("km=%d m=%d mm=%d\n", p.km, p.m, p.mm);
}

struct misuraEU converti(struct misuraUK m) {
    double v = m.miglia * 1760 * 3 * 12 * 25.4 + //
               m.yarde * 3 * 12 * 25.4 +         //
               m.piedi * 12 * 25.4 +             //
               m.pollici * 25.4;
    
    double v1 = 25.4 * (m.pollici + 12 * (m.piedi + 3 * (m.yarde + 1760 * m.miglia)));
    printf("%f %f\n", v, v1);

    struct misuraEU c = { 
        .mm = (int) v % 1000, 
        .m = (int) v / 1000 % 1000, 
        .km = (int) v / 1000000
    };
    return c;
}

int main(void) {
    struct misuraUK m0 = {1, 0, 0, 0};
    stampa(converti(m0));
    struct misuraUK m1 = {1, 1, 1, 1};
    stampa(converti(m1));
    struct misuraUK m2 = {2, 2, 2, 2};
    stampa(converti(m2));
    struct misuraUK m3 = {3, 4, 5, 6};
    stampa(converti(m3));
}