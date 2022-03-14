#include <stdio.h>

int main(void) {
    int input;
    unsigned char opzioni = 0;

    printf("Sesso (maschio = 0, femmina = 1): ");
    scanf("%d", &input);
    opzioni = opzioni | (input & 1);

    printf("Eta’: ");
    scanf("%d", & input);
    opzioni = opzioni | ((input >= 18) << 1);
    
    printf("Cittadinanza (italiana = 0, estera = 1): ");
    scanf("%d", &input);
    opzioni = opzioni | ((input & 1) << 2);

    printf("Segni particolari (no = 0, si = 1): ");
    scanf("%d", &input);
    opzioni = opzioni | ((input & 1) << 3);
    
    printf("Possesso patente B (no = 0, si = 1): ");
    scanf("%d", &input);
    opzioni = opzioni | ((input & 1) << 4);
    
    printf("\nPACCHETTO INFORMATIVO: %d\n", opzioni);
    printf("\n%s!\n", opzioni & (1 << 2) ? "Thank you" : "Grazie");
    return 0;
}