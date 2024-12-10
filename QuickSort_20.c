#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Codigo para teste de desempenho do algoritmo de ordenacao Quick Sort 
// A logica por tras do codigo se baseia em: 
// - Criar vetores com numeros aleatorios, de tamanhos definidos de 0 a 400 mil, de 50 em 50 mil
// - Utilizar uma funcao para medir o tempo de execucao do algoritmo
// Realizar a execucao em todos os casos e printar o tamanho do vetor | tempo de execucao, para 
// a obtencao dos dados para construcao de um grafico analitico

// Funcao para separa os elementos do vetor relacionando entre pequenos e grandes
int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++)
        if (v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            j++;
        }
    v[r] = v[j], v[j] = c;
    return j;
}

// Funcao principal do QuickSort
void QuickSort (int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa (p, r, v);
        QuickSort (p, j - 1, v);
        QuickSort (j + 1, r, v);
    }
}

void wrapperQuickSort(int arr[], int n) {
    QuickSort(0, n - 1, arr); 
}

// Funcao para gerar vetores aleatorios
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Valores aleatorios ate 1000000
    }
}

// Funcao para medir o tempo de execucao
double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start, end;
    start = clock();
    sortFunc(arr, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Funcao principal
int main() {
    int sizes[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Teste execucao (em segundos):\n\n");
    printf("Tamanho do Vetor | QuickSort\n");
    printf("--------------------------------\n");

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];

        // Criar vetor aleatorio para o QuickSort
        int* arrQuick = (int*)malloc(n * sizeof(int));
        generateRandomArray(arrQuick, n);

        // Medir tempo do QuickSort
        double timeQuick = measureTime(wrapperQuickSort, arrQuick, n);
        free(arrQuick);

        // Exibir resultados
        printf("%15d | %12.6f\n", n, timeQuick);
    }

    return 0;
}
