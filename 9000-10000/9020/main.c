#include <stdio.h>
#include <stdlib.h>

int cache[10001] = {0};

void makePrimeSet()
{
    cache[1] = 1;

    for (int i = 2; i < 10001; ++i ) {
        if (cache[i] == 0) {
            for (int j = i+i; j < 10001; j += i) {
                cache[j] = 1;
            }
        }
    }
}

void solution(int n)
{
    int half = n / 2;

    int f1 = 0;
    int f2 = 0;
    int diff = n;
    for (int i = 1; i <= half; ++i) {
        if (cache[i] == 1) {
            continue;
        }

        if (cache[i] == 0 && cache[n-i] == 0) {
            if (abs(i - (n-i)) < diff) {
                diff = abs(i - (n-i));
                f1 = i;
                f2 = n-i;
            }
        }
    }

    printf("%d %d\n", f1, f2);
}

int main()
{
    makePrimeSet();

    int t;
    scanf("%d", &t);

    int nums[t];

    for (int i = 0; i < t; ++i) {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < t; ++i) {
        solution(nums[i]);
    }

    return 0;
}