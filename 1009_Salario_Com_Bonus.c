#include <stdio.h>

int main() {
    char nome[100];
    double salario_fixo, vendas, total;
    
    scanf("%s %lf %lf", nome, &salario_fixo, &vendas);
    
    total = salario_fixo + (vendas * 0.15);
    
    printf("TOTAL = R$ %.2lf\n", total);
    
    return 0;
}
