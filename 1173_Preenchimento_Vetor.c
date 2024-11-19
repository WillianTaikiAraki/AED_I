#include <stdio.h>
#include <stdlib.h>

int N[10];
int x;

int main(){
    scanf("%d", &x);
    N[0] = x;
    for(int i=0; i<10; i++){
        N[i] = x;
        x = x * 2;
    }
    for(int i=0; i<10; i++){
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
