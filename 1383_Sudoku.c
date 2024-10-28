/* Aluno: Willian Taiki Araki
RA: 176540
Exercício da plataforma Beecrowd - 1383 (SUDOKU)
28/10/2024
*/

#include <stdio.h>
#define TAMANHO 9

// Função para verificar se um vetor de 9 elementos contém todos os números de 1 a 9
int vetor_valido(int *vetor) {
    int contagem[TAMANHO + 1] = {0}; // Inicializa o array de contagem com zeros

    for (int i = 0; i < TAMANHO; i++) {
        if (vetor[i] < 1 || vetor[i] > 9 || contagem[vetor[i]] > 0) {
            return 0; // Número fora do intervalo ou repetido
        }
        contagem[vetor[i]]++;
    }
    return 1;
}

// Função para verificar todas as linhas de uma matriz 9x9
int verifica_linha(int matriz[TAMANHO][TAMANHO]) {
    int linha[TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            linha[j] = matriz[i][j];
        }
        if (!vetor_valido(linha)) {
            return 0; // Linha inválida
        }
    }
    return 1;
}

// Função para verificar todas as colunas de uma matriz 9x9
int verifica_coluna(int matriz[TAMANHO][TAMANHO]) {
    int coluna[TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            coluna[j] = matriz[j][i];
        }
        if (!vetor_valido(coluna)) {
            return 0; // Coluna inválida
        }
    }
    return 1;
}

// Função para verificar todas as regiões 3x3 de uma matriz 9x9
int verifica_submatriz_3x3(int matriz[TAMANHO][TAMANHO]) {
    int submatriz[TAMANHO];
    for (int linha = 0; linha < TAMANHO; linha += 3) {
        for (int coluna = 0; coluna < TAMANHO; coluna += 3) {
            int indice = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    submatriz[indice++] = matriz[linha + i][coluna + j];
                }
            }
            if (!vetor_valido(submatriz)) {
                return 0; // Submatriz 3x3 inválida
            }
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    // Para armazenar todas as matrizes de entrada antes de processar
    int matrizes[n][TAMANHO][TAMANHO];

    // Lê todas as matrizes de entrada
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                scanf("%d", &matrizes[k][i][j]);
            }
        }
    }

    // Processa cada matriz após toda a entrada ser lida
    for (int k = 0; k < n; k++) {
        int valido = verifica_linha(matrizes[k]) && verifica_coluna(matrizes[k]) && verifica_submatriz_3x3(matrizes[k]);

        // Imprime o resultado para a instância atual
        printf("Instancia %d\n", k + 1);
        if (valido) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        // Imprime uma linha em branco após cada instância, exceto na última
        if (k < n - 1) {
            printf("\n");
        }
    }

    return 0;
}
