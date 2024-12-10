#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Codigo para teste de desempenho do algoritmo de ordenacao Merge Sort 
// A logica por tras do codigo se baseia em: 
// - Criar vetores com numeros aleatorios, de tamanhos definidos de 0 a 400 mil, de 50 em 50 mil
// - Utilizar uma funcao para medir o tempo de execucao do algoritmo
// Realizar a execucao em todos os casos e printar o tamanho do vetor | tempo de execucao, para 
// a obtencao dos dados para construcao de um grafico analitico

// Funcao para intercalar as duas partes do vetor
void Intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p; j = q; k = 0;

    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }

    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    for (i = p; i < r; i++) {
        v[i] = w[i - p];
    }
    free(w);
}

// Funcao recursiva do MergeSort
void MergeSort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        MergeSort(p, q, v);
        MergeSort(q, r, v);
        Intercala(p, q, r, v);
    }
}

void wrapperMergeSort(int arr[], int n) {
    MergeSort(0, n, arr);
}

// Funcao para gerar vetores aleatorios
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; // Valores aleatorios até 1000000
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

// Função principal
int main() {
    int sizes[] = {50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("Teste execucao (em segundos):\n\n");
    printf("Tamanho do Vetor | MergeSort\n");
    printf("--------------------------------\n");

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];

        // Criar vetor aleatório para o MergeSort
        int* arrMerge = (int*)malloc(n * sizeof(int));
        generateRandomArray(arrMerge, n);

        // Medir tempo do MergeSort
        double timeMerge = measureTime(wrapperMergeSort, arrMerge, n);
        free(arrMerge);

        // Exibir resultados
        printf("%15d | %12.6f\n", n, timeMerge);
    }

    return 0;
}
