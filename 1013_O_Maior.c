#include <stdio.h>
#include <stdlib.h>

int maiorAB(int a, int b) {
    return (a + b + abs(a - b)) / 2;
}

int main() {
    int a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    
    int maior = maiorAB(a, b);
    
    maior = maiorAB(maior, c);
    
    printf("%d eh o maior\n", maior);
    
    return 0;
}
