#include <stdio.h>

int main() {
    int h, m, s;
    int tt = 0;
    double d = 0;
    int vel = 0;
    char c;

    while (scanf("%d:%d:%d", &h, &m, &s) != EOF) {
        scanf("%c", &c);

        if (c == ' ') {
            if (tt != 0) 
                d += (double)(((h * 3600 + m * 60 + s) - tt) * vel) / 3600;

            scanf("%d%*c", &vel);
            tt = h * 3600 + m * 60 + s;

        } else {
            d += (double)(((h * 3600 + m * 60 + s) - tt) * vel) / 3600;
            printf("%02d:%02d:%02d %.2lf km\n", h, m, s, d);
            tt = h * 3600 + m * 60 + s;
        }
    }

    return 0;
}
