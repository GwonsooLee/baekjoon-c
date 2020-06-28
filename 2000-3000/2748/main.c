#include <stdio.h>

long cache[100];

long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    if (cache[n] > 0) {
        return cache[n];
    }

    cache[n] = fibonacci(n-1) + fibonacci(n-2);

    return cache[n];
}

int main()
{
    int n;
    scanf("%d", &n);

    long answer = fibonacci(n);

    printf("%ld", answer);

    return 0;
}