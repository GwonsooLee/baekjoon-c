#include <stdio.h>

int cache[300000] = {};
int test[2000000];

int setPrimeList()
{
    int max = 300000;
    // 1 is not prime
    cache[1] = 1;
    for (int i = 2; i <= max; ++i) {
        if (cache[i] == 0){
            for (int j = 2*i ; j <max; j += i) {
                cache[j] = 1;
            }
        }
    }
}

int main()
{
    setPrimeList();

    int n;
    int index = 0;
    while(1){
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        test[index++] = n;
    }

    for (int t = 0; t < index; t++) {
        int count = 0;
        int max = 2*test[t];
        for (int i = test[t]+1; i <= max; ++i ) {
            if (cache[i] == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}