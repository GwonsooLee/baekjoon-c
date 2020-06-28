#include <stdio.h>

int cacheX[1001] = {0};
int cacheY[1001] = {0};

struct Vector {
    int x;
    int y;
};

void solution(struct Vector arr[3]) {
    int x, y;
    for (int i = 0; i < 3; ++i) {
        if (cacheX[arr[i].x] == 1) {
            x = arr[i].x;
        }

        if (cacheY[arr[i].y] == 1) {
            y = arr[i].y;
        }
    }

    printf("%d %d", x, y);
}

int main()
{
    struct Vector vectors[3];

    for (int i = 0; i < 3 ; ++i) {
        scanf("%d %d", &vectors[i].x , &vectors[i].y);
        cacheX[vectors[i].x]++;
        cacheY[vectors[i].y]++;
    }

    solution(vectors);
}