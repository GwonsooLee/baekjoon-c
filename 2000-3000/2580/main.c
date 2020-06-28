#include <stdio.h>

int arr[9][9] = {0};
int isPrint = 0;

void printArray(){
    if (isPrint >= 1) {
        return;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    isPrint = 1;
}

void fill(int x, int y)
{
    // If element is not 0;
    if (arr[x][y] != 0) {
        if (x == 8) {
            if (y == 8) {
                printArray();
                return;
            }
            fill(0, y+1);
        } else {
            fill(x+1, y);
        }
        return;
    }

    // If element is 0;

    //check vertical and horizontal;
    int nums[9] = {0};
    for (int i = 0; i < 9; ++i) {
        if (arr[i][y] != 0) {
            nums[arr[i][y]-1]  += 1;
        }

        if (arr[x][i] != 0) {
            nums[arr[x][i]-1]  += 1;
        }
    }

    //check the area;
    int startX = 0;
    if (x >=3 && x < 6) {
        startX = 3;
    } else if (x >= 6) {
        startX = 6;
    }

    int startY = 0;
    if (y >=3 && y < 6) {
        startY = 3;
    } else if (y >= 6) {
        startY = 6;
    }

    for (int i = startX; i < startX+3; ++i) {
        for (int j = startY; j < startY +3; ++j) {
            if (arr[i][j] != 0) {
                nums[arr[i][j]-1]++;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (nums[i] == 0) {
            arr[x][y] = i+1;
            if (x+1 == 9) {
                if (y+1 == 9) {
                    printArray();
                    return;
                }
                fill(0, y+1);
            } else {
                fill(x+1, y);
            }
        }
    }

    arr[x][y] = 0;
}

int main()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf("%d", &arr[j][i]);
        }
    }

    fill(0, 0);

    return 0;
}

/*
7 9 0 0 4 1 0 0 2
3 0 1 9 0 0 4 0 7
0 6 0 2 0 3 0 9 1
0 0 4 5 8 0 0 7 3
5 0 3 4 0 9 6 0 8
9 8 0 3 0 0 5 0 0
8 3 0 7 0 2 0 4 0
6 0 7 0 0 5 2 0 9
1 0 0 8 9 0 0 3 6

0 1 5 3 6 8 9 0 0
6 4 7 0 9 0 2 3 8
0 9 3 4 7 2 6 1 5
9 0 2 0 8 4 0 5 7
0 5 6 1 0 7 8 9 3
1 0 8 9 5 3 4 6 2
5 2 9 7 0 6 3 0 1
7 8 0 2 3 9 0 4 6
3 0 4 8 1 5 7 2 9

 */