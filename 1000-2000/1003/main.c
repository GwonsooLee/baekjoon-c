#include <stdio.h>

int cache0[50];
int cache1[50];

int fibonacciCountZero(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 0;
    }

    if (cache0[n] > 0 ) {
        return cache0[n];
    }

    cache0[n] = fibonacciCountZero(n-1) + fibonacciCountZero(n-2);

    return cache0[n];
}


int fibonacciCountOne(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    if (cache1[n] > 0 ) {
        return cache1[n];
    }

    cache1[n] = fibonacciCountOne(n-1) + fibonacciCountOne(n-2);

    return cache1[n];
}

int main()
{
    int t;
    scanf("%d", &t);

    int num[t];
    for (int i=0; i < t; ++i) {
        scanf("%d", &num[i]);
    }


    for (int i=0; i < t; ++i) {
        printf("%d %d\n", fibonacciCountZero(num[i]), fibonacciCountOne(num[i]));
    }

    return 0;
}