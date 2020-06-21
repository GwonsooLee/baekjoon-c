#include <stdio.h>
#include <stdlib.h>

int cache[101][101];

int main()
{
    int card[100];
    int n,m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &card[i]);
    }

    int answer = 0;
    int temp = 0;
    for (int i = 0; i < n ; ++i) {
        int s = card[i];
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (cache[j][k] != 0) {
                    temp = s + cache[j][k];
                    if ( m-temp <= m-answer && m >= temp) {
                        answer = temp;
                    }
                } else {
                    cache[j][k] = card[j] + card[k];
                    temp = s + cache[j][k];
                    if ( m-temp <= m-answer && m >= temp) {
                        answer = temp;
                    }
                }

            }
        }
    }

    printf("%d", answer);

    return 0;
}
