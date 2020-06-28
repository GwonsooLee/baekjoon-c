#include <stdio.h>

int primes[10000001];

void setPrime() {
    primes[0] = 1;
    primes[1] = 1;

    for (int i = 2; i < 10000001; ++i) {
        if (primes[i] == 0) {
            for (int j = 2*i; j < 10000001; j+=i) {
                primes[j] = 1;
            }
        }
    }
}


int main()
{
    setPrime();
    int t;
    scanf("%d", &t);

    int countMap[10000001]={0};
    for (int j = 2; j < 10000001; ++j) {
        int cur = t;
        if (j > cur) {
            break;
        }
        int cnt = 0;
        if ( primes[j] == 0 && cur % j == 0) {
            while(cur > 0) {
                if (cur % j == 0) {
                    cnt++;
                    cur /= j;
                } else {
                    if (countMap[j] < cnt) {
                        countMap[j] = cnt;
                    }
                    break;
                }
            }
        }
    }

    for (int i = 2; i < 10000001; ++i) {
        if (i > t) {
            break;
        }
        if (countMap[i] > 0){
            for (int j = 0; j  < countMap[i]; ++j){
                printf("%d\n", i);
            }
        }
    }

    return 0;
}