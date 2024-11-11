#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 1000
#define MAX_TAMANHO_ITEM 21

// Função de comparação para ordenação alfabética
int compara(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // Consome a nova linha após o número de listas

    for (int i = 0; i < n; i++) {
        char linha[MAX_ITENS * MAX_TAMANHO_ITEM];
        fgets(linha, sizeof(linha), stdin);

        char *itens[MAX_ITENS];
        int contador = 0;

        // Divide a linha em palavras e armazena os ponteiros em "itens"
        char *token = strtok(linha, " \n");
        while (token != NULL) {
            int duplicado = 0;
            for (int j = 0; j < contador; j++) {
                if (strcmp(itens[j], token) == 0) {
                    duplicado = 1;
                    break;
                }
            }
            if (!duplicado) {
                itens[contador++] = token;
            }
            token = strtok(NULL, " \n");
        }

        // Ordena os itens em ordem alfabética
        qsort(itens, contador, sizeof(char *), compara);

        // Imprime os itens sem duplicados e em ordem alfabética
        for (int j = 0; j < contador; j++) {
            printf("%s", itens[j]);
            if (j < contador - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
