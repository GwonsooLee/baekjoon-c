#include <stdio.h>

int min (int a, int b)
{
    return a > b ? b : a;
}

int solution(int x, int y, int w, int h)
{
    int widthDiff = min(w-x, x-0);
    int heightDiff = min(h-y, y-0);

    return min(widthDiff, heightDiff);
}

int main()
{
    int x, y, w ,h;
    scanf("%d %d %d %d", &x, &y ,&w, &h);

    printf("%d", solution(x, y, w, h));
    return 0;
}