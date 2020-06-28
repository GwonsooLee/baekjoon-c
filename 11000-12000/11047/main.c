#include <stdio.h>

int coins[10];

int solutions(int n, int k)
{
    int cnt = 0;
    int cur = k;
    for (int i = n-1; i >=0; --i) {
        if (coins[i] <= cur) {
            int v = cur / coins[i];
            cnt += v;
            cur = cur - v * coins[i];
        }
    }

    return cnt;
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n ; ++i) {
        scanf("%d", &coins[i]);
    }

    int answer = solutions(n, k);

    printf("%d", answer);

    return 0;
}