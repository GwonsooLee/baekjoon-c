#include <stdio.h>

int getCreator(int n)
{
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int ret = i;
        int left = i;
        while (left != 0) {
            int a = left / 10;
            int b = left % 10;
            ret += b;

            left = a;
        }

        if (ret == n && answer == 0) {
            answer = i;
        } else if (ret == n && ret < answer) {
            answer = i;
        }

        if (ret > n) {
            break;
        }
    }

    return answer;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d", getCreator(n));

    return 0;
}

