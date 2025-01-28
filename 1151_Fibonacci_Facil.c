#include <stdio.h>

int main() {
    int quantidade, indice;

    scanf("%d", &quantidade);

    unsigned long int fibonacci[quantidade];
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (indice = 2; indice < quantidade; indice++)
        fibonacci[indice] = fibonacci[indice - 1] + fibonacci[indice - 2];

    for (indice = 0; indice < quantidade; indice++) {
        if (indice != quantidade - 1)
            printf("%lu ", fibonacci[indice]);
        else
            printf("%lu\n", fibonacci[indice]);
    }

    return 0;
}
