#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

long long int minimo(long long int a, long long int b) {
    return a < b ? a : b;
}

void algoritmoFloydWarshall(long long int **matrizDistancia, int numVertices) {
    for (int intermediario = 1; intermediario <= numVertices; ++intermediario) {
        for (int origem = 1; origem <= numVertices; ++origem) {
            for (int destino = 1; destino <= numVertices; ++destino) {
                matrizDistancia[origem][destino] = minimo(
                    matrizDistancia[origem][destino],
                    matrizDistancia[origem][intermediario] + matrizDistancia[intermediario][destino]
                );
            }
        }
    }
}

int main(void) {
    long long int **matrizDistancia;
    int numCidades, numCaminhos, cidadeA, cidadeB, distancia, numConsultas, origem, destino;

    while (scanf("%d %d\n", &numCidades, &numCaminhos) != EOF) {
        if (numCidades == 0 && numCaminhos == 0) {
            break;
        }

        matrizDistancia = (long long int **)malloc((numCidades + 1) * sizeof(long long int *));
        for (int i = 1; i <= numCidades; ++i) {
            matrizDistancia[i] = (long long int *)malloc((numCidades + 1) * sizeof(long long int));
            for (int j = 1; j <= numCidades; ++j) {
                matrizDistancia[i][j] = INT_MAX;
            }
        }

        for (int i = 0; i < numCaminhos; ++i) {
            scanf("%d %d %d\n", &cidadeA, &cidadeB, &distancia);
            matrizDistancia[cidadeA][cidadeB] = distancia;
        }

        for (int i = 1; i <= numCidades; ++i) {
            for (int j = i; j <= numCidades; ++j) {
                if (matrizDistancia[i][j] != INT_MAX && matrizDistancia[j][i] != INT_MAX) {
                    matrizDistancia[i][j] = 0;
                    matrizDistancia[j][i] = 0;
                }
            }
        }

        algoritmoFloydWarshall(matrizDistancia, numCidades);

        scanf("%d\n", &numConsultas);
        for (int i = 0; i < numConsultas; ++i) {
            scanf("%d %d\n", &origem, &destino);

            if (matrizDistancia[origem][destino] == INT_MAX) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%lld\n", matrizDistancia[origem][destino]);
            }
        }
        printf("\n");

        for (int i = 1; i <= numCidades; ++i) {
            free(matrizDistancia[i]);
        }
        free(matrizDistancia);
    }

    return 0;
}
