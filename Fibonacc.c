#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter n to find Fibonacci: ");
    scanf("%d", &n);

    if (n == 1) {
        printf("Fibonacci num is 1");
        return 0;
    } else if (n == 2) {
        printf("Fibonacci num is 2");
        return 0;
    }

    long long *fibonacci = (long long *)malloc(n * sizeof(long long));

    if (fibonacci == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    fibonacci[0] = 1;
    fibonacci[1] = 2;

    for (i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    printf("Fibonacci num is %lld", fibonacci[n - 1]);

    free(fibonacci);

    return 0;
}