#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Vector {
    int x;
    int y;
};

double getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

int solution(struct Vector v1, struct Vector v2, int r1, int r2)
{
    double distance = getDistance(v1.x, v1.y, v2.x, v2.y);

    if (distance == 0) {
        if (r1 == r2) {
            return -1;
        }
        return 0;
    } else {
        if (r1 + r2 == distance) {
            return 1;
        } else if ( abs(r2 - r1) == distance) {
            return 1;
        }

        int max = distance;
        int sum = distance + r1 + r2;
        if (r1 > max) max = r1;
        if (r2 > max) max = r2;

        sum -= max;

        if (sum > max) return 2;
        else return 0;
    }
}

int main()
{
    struct Vector v1;
    struct Vector v2;
    int r1, r2;

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d %d %d %d %d %d", &v1.x, &v1.y, &r1, &v2.x, &v2.y, &r2);
        printf("%d\n", solution(v1, v2, r1, r2));
    }

    return 0;
}