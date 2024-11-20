#include <stdio.h>
#include <stdlib.h>

// Função de comparação para ordenar os pares em ordem crescente
int compare_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Função de comparação para ordenar os ímpares em ordem decrescente
int compare_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N;

    // Lê a quantidade de números
    scanf("%d", &N);

    int numeros[N], pares[N], impares[N];
    int count_pares = 0, count_impares = 0;

    // Lê os números e separa em pares e ímpares
    for (int i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
        if (numeros[i] % 2 == 0) {
            pares[count_pares++] = numeros[i];
        } else {
            impares[count_impares++] = numeros[i];
        }
    }

    // Ordena os pares em ordem crescente
    qsort(pares, count_pares, sizeof(int), compare_asc);

    // Ordena os ímpares em ordem decrescente
    qsort(impares, count_impares, sizeof(int), compare_desc);

    // Imprime os pares
    for (int i = 0; i < count_pares; i++) {
        printf("%d\n", pares[i]);
    }

    // Imprime os ímpares
    for (int i = 0; i < count_impares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
