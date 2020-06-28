#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    if (*(int*)a > *(int*)b) {
        return 1;
    } else if (*(int*)a < *(int*)b) {
        return -1;
    }

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i=0; i<n; ++i) {
        scanf("%d", &nums[i]);
    }

    qsort(&nums,n, sizeof(int), compare);

    int sum = 0;
    int cur = n;
    for (int i=0; i<n; ++i) {
        sum += (cur*nums[i]);
        cur--;
    }

    printf("%d", sum);
    return 0;
}