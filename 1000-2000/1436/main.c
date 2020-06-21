#include <stdio.h>

int getSixes(int num) {
    while (num > 0) {
        if (num % 1000 == 666) {
            return 1;
        }

        num = num /10;
    }

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int count = 0;
    int num = 666;
    while (count != n) {
        int sixes = getSixes(num);
        if (sixes == 1) {
            count++;
        }

        num++;
    }

    printf("%d", num-1);

    return 0;
}