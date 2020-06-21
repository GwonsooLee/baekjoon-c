#include <stdio.h>

void insertionSort(int *arr, int index)
{
    for (int i=1; i < index; i++){
        int target = arr[i];
        int isFinished = 0;
        for (int j=i-1; j >= 0; --j) {
            if (arr[j] < target ) {
                arr[j+1] = arr[j];
            } else {
                arr[j+1] = target;
                isFinished = 1;
                break;
            }
        }

        if (isFinished == 0) {
            arr[0] = target;
        }
    }
}

int main()
{
    int number;
    int digits[11];
    scanf("%d", &number);

    int index = 0;
    int temp = number;
    while (temp > 0) {
        digits[index++] = temp % 10;

        temp /= 10;
    }

    insertionSort(digits, index);

    for (int i=0; i < index; ++i) {
        printf("%d", digits[i]);
    }

    return 0;
}