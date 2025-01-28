#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numCartelas, numBolas, i, j, diferenca;
    bool encontrado;

    while (true) {
        scanf("%d %d", &numCartelas, &numBolas);

        if (numCartelas == 0 && numBolas == 0)
            break;

        int bolasSorteadas[numBolas];

        for (i = 0; i < numBolas; i++)
            scanf("%d", &bolasSorteadas[i]);

        for (diferenca = 0; diferenca <= numCartelas; diferenca++) {
            encontrado = false;
            for (i = 0; i < numBolas; i++) {
                for (j = 0; j < numBolas; j++) {
                    if (abs(bolasSorteadas[i] - bolasSorteadas[j]) == diferenca) {
                        encontrado = true;
                        break;
                    }
                }
                if (encontrado)
                    break;
            }
            if (!encontrado)
                break;
        }

        if (encontrado)
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}
