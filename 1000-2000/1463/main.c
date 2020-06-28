#include <stdio.h>

int minOperation(int n, int count)
{
    if (n == 1) {
        return count;
    }

    if (n % 3 == 0) {
        n = n / 3;
        count += 1;
    } else if ((n-1) % 3 == 0) {
        n = n-1;
        count += 1;
    } else if (n % 2 == 0) {
        n /= 2;
        count += 1;
    } else {
        n = n- 1;
        count += 1;
    }

    return minOperation(n, count);
}

int min(int a, int b) {
    if (a > b) {
        return b;
    }

    return a;
}

int dynamic(int n)
{
    int cache[1000001] = {0, };

    cache[1] = 0;
    for (int i = 2; i <= n; ++i) {
        cache[i] = cache[i-1] + 1;
        if(i%2 == 0) cache[i] = min(cache[i], cache[i/2] + 1);
        if(i%3 == 0) cache[i] = min(cache[i], cache[i/3] + 1);
    }

    return cache[n];
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d", dynamic(n));

    return 0;
}