#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Codigo para teste de desempenho do algoritmo de ordenacao Insertion Sort 
// A logica por tras do codigo se baseia em: 
// - Criar vetores com numeros aleatorios, de tamanhos definidos de 0 a 400 mil, de 50 em 50 mil
// - Utilizar uma funcao para medir o tempo de execucao do algoritmo
// Realizar a execucao em todos os casos e printar o tamanho do vetor | tempo de execucao, para 
// a obtencao dos dados para construcao de um grafico analitico


// Implementacao do InsertionSort
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
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
    printf("Tamanho do Vetor | InsertionSort\n");
    printf("--------------------------------\n");

    for (int i = 0; i < numSizes; i++) {
        int n = sizes[i];

        // Criar um vetor aleatorio para o InsertionSort
        int* arrInsertion = (int*)malloc(n * sizeof(int));
        generateRandomArray(arrInsertion, n);

        // Medir tempo do InsertionSort
        double timeInsertion = measureTime(InsertionSort, arrInsertion, n);
        free(arrInsertion);

        // Exibir resultados
        printf("%15d | %12.6f\n", n, timeInsertion);
    }

    return 0;
}
