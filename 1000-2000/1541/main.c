#include <stdio.h>

int main()
{
    char s[51];
    int nums[100];
    int operators[50];
    scanf("%s", &s);

    int index = 0;
    int sum = 0;
    int operatorIndex = 0;
    int numIndex = 0;
    while (s[index] != '\0') {
        if ((int)s[index] == 45 || (int)s[index] == 43) {
            operators[operatorIndex++] = (int)s[index];
            nums[numIndex++] = sum;
            sum = 0;
        } else {
            sum *= 10;
            sum += (s[index]+'\0' - 48);
        }
        index++;
    }

    nums[numIndex++] = sum;

    if (operatorIndex == 0) {
        printf("%d", nums[0]);
        return 0;
    }

    int curNumIndex = 0;
    int opsIndex = 0;
    sum = -1;
    int isSet = 0;
    char curOps;
    int minusOn = 0;
    while(curNumIndex != numIndex || opsIndex != operatorIndex) {
        if (isSet == 0) {
            sum = nums[curNumIndex++];
            isSet = 1;
        }

        if (operators[opsIndex] == 43)  {
            if (minusOn == 1) {
                sum -= nums[curNumIndex++];
            } else {
                sum += nums[curNumIndex++];
            }
        } else {
            minusOn = 1;
            sum -= nums[curNumIndex++];
        }
        opsIndex++;
    }

    printf("%d", sum);

    return 0;
}