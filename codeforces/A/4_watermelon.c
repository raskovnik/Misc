#include <stdio.h>

int main() {
    int kilos;
    scanf("%d", &kilos);
    if (kilos > 2 && kilos % 2 == 0) {
        printf("YES\n");
    } else {printf("NO\n");}
}
