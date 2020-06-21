#include <stdio.h>
#include <math.h>

int getFrequent(int *count) {
    int currentMax = 0;
    int dupCount = 0;
    int answer = 0;
    for (int i = 8001; i > 4000; --i) {
        int temp = 4000-i;
        if (count[i] > currentMax) {
            currentMax = count[i];
            dupCount = 0;
            answer = temp;
        } else if (count[i] == currentMax && dupCount == 0 && temp > answer) {
            answer = temp;
            dupCount++;
        }
    }

//    printf("%d %d\n", answer, dupCount);

    for (int i = 0; i < 4001; ++i) {
        int temp = i;
        if (count[i] > currentMax) {
            currentMax = count[i];
            dupCount = 0;
            answer = temp;
        } else if (count[i] == currentMax && dupCount == 0 && temp > answer) {
            answer = temp;
            dupCount++;
        }
    }

//    printf("%d %d\n", answer, dupCount);

    return answer;
}

void mergeAll(int *arr, int start, int middle, int end) {
    int leftIndex = start;
    int rightIndex = middle+1;
    int ret[end-start+1];

    int count = 0;

    while(leftIndex <= middle || rightIndex <= end) {
        if (leftIndex > middle && rightIndex <= end) {
            ret[count++] = arr[rightIndex];
            rightIndex++;
        } else if (leftIndex <= middle && rightIndex > end) {
            ret[count++] = arr[leftIndex];
            leftIndex++;
        } else if (arr[leftIndex] < arr[rightIndex]) {
            ret[count++] = arr[leftIndex];
            leftIndex++;
        } else {
            ret[count++] = arr[rightIndex];
            rightIndex++;
        }
    }


    for (int i = 0 ; i < end-start+1; i++) {
        arr[start+i] = ret[i];
    }
}

void mergeSort(int *arr, int start, int end) {
    int sub = end - start;
    if (sub == 0) {
        return;
    }
    if (sub == 1) {
        int temp = 0;
        if (arr[start] > arr[end]) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        return;
    }

    //Left mergeSort
    int middle = start + (sub / 2);
    mergeSort(arr, start, middle);
    mergeSort(arr, middle+1, end);

    mergeAll(arr, start, middle, end);
}

int main()
{
    int n;
    double sum = 0;
    int count[8002] = {0};
    int numbers[500001] = {0};
    scanf("%d", &n);

    for (int i=0; i < n; ++i) {
        scanf("%d", &numbers[i]);
        if (numbers[i] < 0) {
            count[4000-numbers[i]]++;
        } else {
            count[numbers[i]]++;
        }

        sum += numbers[i];
    }

    int f = getFrequent(count);

    mergeSort(numbers, 0, n-1);

    int avg;
    if (sum < 0) {
        avg = (int)floor((double)sum/n + 0.5);
    } else {
        avg = (int)floor((double)sum/n + 0.5);
    }
    printf("%d\n", avg);
    printf("%d\n", numbers[n/2]);
    printf("%d\n", f);
    printf("%d\n", numbers[n-1]-numbers[0]);

    return 0;
}