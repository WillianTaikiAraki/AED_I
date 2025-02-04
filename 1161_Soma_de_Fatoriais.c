#include <stdio.h>

unsigned long long calcular_fatorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    
    unsigned long long fatorial = 1;
    for (int i = num; i > 1; i--)
        fatorial *= i;
    
    return fatorial;
}

int main() {
    int num1, num2;
    while (scanf("%d %d", &num1, &num2) != EOF) {
        unsigned long long soma_fatoriais = calcular_fatorial(num1) + calcular_fatorial(num2);
        printf("%llu\n", soma_fatoriais);
    }
    return 0;
}
