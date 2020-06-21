#include <stdio.h>

void mergeAll(int *x, int *y, int start, int middle, int end) {
    int leftIndex = start;
    int rightIndex = middle+1;
    int retX[end-start+1];
    int retY[end-start+1];

    int count = 0;

    while(leftIndex <= middle || rightIndex <= end) {
        if (leftIndex > middle && rightIndex <= end) {
            retX[count] = x[rightIndex];
            retY[count] = y[rightIndex];
            rightIndex++;
        } else if (leftIndex <= middle && rightIndex > end) {
            retX[count] = x[leftIndex];
            retY[count] = y[leftIndex];
            leftIndex++;
        } else if (x[leftIndex] < x[rightIndex]) {
            retX[count] = x[leftIndex];
            retY[count] = y[leftIndex];
            leftIndex++;
        } else if (x[leftIndex] == x[rightIndex] && y[leftIndex] < y[rightIndex]) {
            retX[count] = x[leftIndex];
            retY[count] = y[leftIndex];
            leftIndex++;
        } else {
            retX[count] = x[rightIndex];
            retY[count] = y[rightIndex];
            rightIndex++;
        }

        count++;
    }


    for (int i = 0 ; i < end-start+1; i++) {
        x[start+i] = retX[i];
        y[start+i] = retY[i];
    }
}

void mergeSort(int *x, int *y, int start, int end) {
    int sub = end - start;
    if (sub == 0) {
        return;
    }
    if (sub == 1) {
        int tempX = 0;
        int tempY = 0;
        if (x[start] > x[end] || (x[start] == x[end] && y[start] > y[end])) {
            tempX = x[start];
            tempY = y[start];

            x[start] = x[end];
            x[end] = tempX;

            y[start] = y[end];
            y[end] = tempY;
        }
        return;
    }

    //Left mergeSort
    int middle = start + (sub / 2);
    mergeSort(x, y, start, middle);
    mergeSort(x, y, middle+1, end);

    mergeAll(x, y, start, middle, end);
}

int main()
{
    int n;
    int x[100000];
    int y[100000];
    scanf("%d", &n);

    for (int i=0; i < n ; ++i){
        scanf("%d %d", &x[i], &y[i]);
    };

    mergeSort(x, y, 0, n-1);

    for (int i=0; i < n ; ++i){
        printf("%d %d\n", x[i], y[i]);
    };

    return 0;
}