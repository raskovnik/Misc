#include <stdio.h>

int main() {
    int n, petya, vasya, tonya, number = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &petya, &vasya, &tonya);
        if (petya + vasya + tonya >= 2) {number += 1;}
    }
    printf("%d", number);
    return 0;
}