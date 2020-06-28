#include <stdio.h>

void solution(int arr[3])
{
    int max = arr[0];
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i]*arr[i];
    }
    int maxSum = max*max;
    sum -= maxSum;

    if (sum == maxSum) {
        printf("right\n");
    } else {
        printf("wrong\n");
    }
}


int main()
{
    while(1){
        int arr[3];
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        if (arr[0] == 0) {
            break;
        }

        solution(arr);
    }

    return 0;
}