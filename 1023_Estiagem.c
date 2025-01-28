#include <string.h>
#include <stdio.h>
#include <math.h>

int main()
{
    double consumo_medio;
    int T = 0, N, X, Y, totalX, totalY, consumos[201];

    while (scanf("%d", &N) == 1 && N > 0)
    {
        if (T > 0)
            printf("\n");

        memset(consumos, 0, sizeof(consumos));
        totalX = 0;
        totalY = 0;

        for (int i = 0; i < N; ++i)
        {
            scanf("%d %d", &X, &Y);
            if (X > 0)
            {
                totalX += X;
                totalY += Y;
                consumos[Y / X] += X;
            }
        }

        printf("Cidade# %d:\n", ++T);
        
        int printed = 0;
        for (int i = 0; i < 201; ++i)
        {
            if (consumos[i] > 0)
            {
                if (printed)
                    printf(" ");
                printf("%d-%d", consumos[i], i);
                printed = 1;
            }
        }

        consumo_medio = floor((totalY / (double)totalX) * 100) / 100.0;
        printf("\nConsumo medio: %.2lf m3.\n", consumo_medio);
    }

    return 0;
}
