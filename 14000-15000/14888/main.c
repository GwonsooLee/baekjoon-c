#include <stdio.h>
#include <stdlib.h>

char ops[4] = {'+', '-', '*', '/'};
int max = -2100000000;
int min = 2100000000;

void checkMinMax(char *arr, int *nums, int length, int numCnt) {
    int result = 0;
    int num1, num2;
    int index = 0;
    for (int i = 0; i < length; ++i) {
        if (i == 0) {
            num1 = nums[index++];
        }
        num2 = nums[index++];

        char ops = arr[i];

        switch (ops) {
        case '+':
            result = (num1 + num2);
            break;
        case '-':
            result = (num1 - num2);
            break;
        case '*':
            result = (num1 * num2);
            break;
        case '/':
            if (num1 < 0 ) {
                int temp = (abs(num1) / num2);
                result = 0-temp;
            } else {
                result = (num1 / num2);
            }
            break;
        }

        num1 = result;
    }
    if (max < result) {
        max = result;
    }
    if (min > result) {
        min = result;
    }
}

void calOps(char *arr, int *opsMap, int *nums, int index, int length, int numCnt) {
    if (index == length) {
        checkMinMax(arr, nums, length, numCnt);
        return;
    }

   for (int i = 0; i < 4; ++i) {
        int cnt = opsMap[i];
        for (int j = 0; j < cnt; ++j) {
            arr[index] = ops[i];
            opsMap[i]--;
            calOps(arr, opsMap, nums, index+1, length, numCnt);
            opsMap[i]++;
        }
    }
}

int main()
{
    int t;
    int nums[1000000];
    int operators[4];

    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        scanf("%d", &nums[i]);
    }

    scanf("%d %d %d %d", &operators[0], &operators[1], &operators[2], &operators[3]);

    int operationCnt = operators[0] + operators[1] + operators[2] + operators[3];
    char opsList[operationCnt+1];

    calOps(opsList, operators, nums, 0, operationCnt, t);

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}