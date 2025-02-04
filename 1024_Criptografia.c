#include <stdio.h>
#include <string.h>

void primeiraPassada(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] += 3;
        }
    }
}

void segundaPassada(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void terceiraPassada(char *str) {
    int len = strlen(str);
    int metade = len / 2;
    for (int i = metade; i < len; i++) {
        str[i] -= 1;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 
    
    for (int i = 0; i < N; i++) {
        char linha[1001];
        fgets(linha, 1001, stdin);

        linha[strcspn(linha, "\n")] = '\0';

        primeiraPassada(linha);
        segundaPassada(linha);
        terceiraPassada(linha);

        printf("%s\n", linha); 
    }

    return 0;
}
