// A logica deste problema se baseia no seguinte: criamos uma array para armazenar os nomes 
// dos alunos, com no maximo 20 caracteres. Após ler cada nome ordenamos cada subarray com
// base no primeiro indice (ou seja, primeira letra, ja que queremos ordenar o conjunto por
// ordem alfabetica), comparando e trocando cada nome. Assim, com a lista de nomes ordenada,
// procuramos pelo K-esimo nome, e printamos ele.

#include <stdio.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    // Array para armazenar os nomes
    char nomes[N][21]; // Cada nome pode ter no máximo 20 caracteres + '\0'

    // Ler os nomes
    for (int i = 0; i < N; i++) {
        scanf("%s", nomes[i]);
    }

    // Ordenar os nomes manualmente usando Selection Sort
    for (int i = 0; i < N - 1; i++) {
        int min_idx = i; // Índice do menor elemento
        for (int j = i + 1; j < N; j++) {
            if (strcmp(nomes[j], nomes[min_idx]) < 0) {
                min_idx = j;
            }
        }
        // Trocar o menor elemento encontrado com o elemento atual
        if (min_idx != i) {
            char temp[21];
            strcpy(temp, nomes[i]);
            strcpy(nomes[i], nomes[min_idx]);
            strcpy(nomes[min_idx], temp);
        }
    }

    // Imprimir o K-ésimo nome (ajustando para índice 0)
    printf("%s\n", nomes[K - 1]);

    return 0;
}
