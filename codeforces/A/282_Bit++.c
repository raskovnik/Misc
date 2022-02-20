#include <stdio.h>
#include <string.h>

int main() {
    int n, number = 0;
    char operation[7];
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", operation);
        if (strchr(operation, '++') != NULL) {number++;}
        if (strchr(operation, '--') != NULL) {number--;}
    }
    printf("%d\n", number);
    return 0;
}