#include <stdio.h>

void printArray(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int isValid(int *arr, int length){
    int dup[10] = {0};
    for (int i = 0; i < length; ++i) {
        if (dup[arr[i]] >= 1){
            return 0;
        }
        dup[arr[i]] += 1;
    }

    return 1;
}

void backtracking(int *arr, int index, int n, int m) {
    // last
    if (index == m-1) {
        for (int i = 1; i <= n ; i++) {
            arr[index] = i;
            if (isValid(arr, m) == 1) {
                printArray(arr, m);
            }
        }
        return;
    }

    for (int i = 1; i <= n ; i++) {
        arr[index] = i;
        backtracking(arr, index+1, n, m);
    }
}


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[m];

    backtracking(&arr, 0, n, m);
}