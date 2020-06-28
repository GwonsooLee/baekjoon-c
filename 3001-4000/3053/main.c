#include <stdio.h>
const double pi = 3.14159265358979323846264338327950288;

void circle(int n)
{
    double val = n*n*pi;

    printf("%f\n", val);
}

void taxiCircle(int n)
{
    double val = n*n*2;
    printf("%f\n", val);
}

int main()
{
    int r;
    scanf("%d", &r);

    circle(r);
    taxiCircle(r);

    return 0;
}