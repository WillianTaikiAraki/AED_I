#include <stdio.h>

int main() {
    int test_cases, num;
    unsigned long long fibonacci[61];

    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    for (int i = 2; i < 61; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    
    scanf("%d", &test_cases);
    while (test_cases--) {
        scanf("%d", &num);
        printf("Fib(%d) = %llu\n", num, fibonacci[num]);
    }
    
    return 0;
}
