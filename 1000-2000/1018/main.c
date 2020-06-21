#include <stdio.h>

char revert[2];

int getChange(char board[51][51], int x, int y, char start)
{
    int count = 0;
    for (int i = x; i < x+8; ++i) {
        for (int j = y; j < y+8; ++j) {
            if (board[j][i] != start) {
                count++;
            }

            if (j < y+7) {
                start = revert[start];
            }
        }
    }

    return count;
}

int findTheSmallChange(char board[51][51], int x, int y)
{
    int countB = getChange(board, x, y, 'B');
    int countW = getChange(board, x, y, 'W');

    if (countB > countW) {
        return countW;
    } else {
        return countB;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char board[51][51];
    revert['B'] = 'W';
    revert['W'] = 'B';

    for (int i = 0; i < n; ++i) {
        scanf("%s", board[i]);
    }

    int min = 1000;
    for (int x = 0; x <= m-8; ++x) {
        for (int y = 0; y <= n-8 ; ++y) {
            int a = findTheSmallChange(board, x, y);
            if (a < min) {
                min = a;
            }
        }
    }

    printf("%d", min);

    return 0;
}