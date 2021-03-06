#include <stdio.h>
//#include <stdlib.h>

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

int main() {
    int n;
    scanf("%d", &n);
    int arr[10001] = {};
    int dup[10001] = {};

    int a = 0;
    long index = 0;
    for (int i = 0 ; i < n ; i++ ){
        scanf("%d", &a);
//        a = rand() % 9999 + 1;
        if (dup[a] == 0) {
            arr[index++] = a;
            dup[a]++;
        } else {
            dup[a]++;
        }
    }

    mergeSort(arr,0, index-1);

    for (int i = 0; i < index; i++) {
        int num = arr[i];
        for (int j = 0; j < dup[num]; j++) {
            printf("%d\n", num);
        }
    }
}

