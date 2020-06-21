#include <stdio.h>
#include <string.h>

int compareWord(char *a, char *b){
    int prev = strlen(a);
    int cur = strlen(b);

    int max = prev;
    if (prev < cur) {
        max = cur;
    }

    // 0 : a is smaller, 1 : b is.
    for (int i=0; i < max; ++i){
        if (a[i] < b[i]) {
            return 0;
        } else if (a[i] > b[i]) {
            return 1;
        }
    }

    return 2;
}

int main()
{
    char words[20000][51];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", &words[i]);
    }

//    for (int i = 1; i < n; ++i) {
//        printf("%s %s %d\n", words[i-1], words[i], compareWord(words[i-1], words[i]));
//    }

    for (int i = 1; i < n; ++i) {
        char target[51];
        int targetLength = strlen(words[i]);
        strcpy(target, words[i]);
        int isFinished = 0;
        for (int j = i-1; j >= 0; --j) {
            if (strlen(words[j]) > targetLength || (strlen(words[j]) == targetLength && compareWord(words[j], target) == 1)) {
                strcpy(words[j+1], words[j]);
            } else {
                strcpy(words[j+1], target);
                isFinished = 1;
                break;
            }
        }
        if (isFinished == 0) {
            strcpy(words[0], target);
        }
    }


    char prev[51];
    strcpy(prev, "");
    for (int i = 0; i < n; ++i) {
        if (strcmp(prev, words[i]) != 0) {
            printf("%s\n", words[i]);
            strcpy(prev, words[i]);
        }
    }

    return 0;
}