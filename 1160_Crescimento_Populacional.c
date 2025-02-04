#include <stdio.h>

int main() {
    int num_testes, anos;
    unsigned long int populacao_A, populacao_B;
    double taxa_crescimento_A, taxa_crescimento_B;

    scanf("%d", &num_testes);

    while (num_testes--) {
        scanf("%lu %lu %lf %lf", &populacao_A, &populacao_B, &taxa_crescimento_A, &taxa_crescimento_B);

        anos = 0;

        while (populacao_A <= populacao_B) {
            populacao_A += populacao_A * (taxa_crescimento_A / 100.0);
            populacao_B += populacao_B * (taxa_crescimento_B / 100.0);
            anos++;

            if (anos > 100) {
                break;
            }
        }

        if (anos <= 100) {
            printf("%d anos.\n", anos);
        } else {
            printf("Mais de 1 seculo.\n");
        }
    }

    return 0;
}
