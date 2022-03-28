#include <stdio.h>
// Qual e’ l’output del programma seguente ?
int main(void) {
    int a, b;
    a = 5;
    b = a + 1;
    printf("1. a=%3d b=%3d\n", a, b);
    b = a++;
    printf("2. a=%3d b=%3d\n", a, b);
    b= ++a;
    printf("3. a=%3d b=%3d\n", a, b);
    printf("4. %d\n", ++a + b++);
    printf("5. a=%3d b=%3d\n", a, b);
    return 0;
}