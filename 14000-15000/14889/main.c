#include <stdio.h>
#include <stdlib.h>

int board[20][20];

int min = 2100000000;

void printArray(int *teams, int memCnt)
{
    for (int i = 0; i < memCnt; ++i) {
        printf("%d ", teams[i]);
    }

    printf("\n");
}

void solutions(int *teams, int memCnt)
{
    int teamA = 0;
    int dupCount[2000] = {0};
    int half = memCnt /2;
    for (int i = 0; i < half; ++i) {
        dupCount[teams[i]-1]++;
        for (int j = 0; j < half; ++j) {
            teamA += board[teams[j]-1][teams[i]-1];
        }
    }

    int teamB = 0;
    int list[1000];
    int index = 0;
    for (int i = 0; i < memCnt; ++i) {
        if (dupCount[i] == 0) {
            for (int j =0; j < memCnt; ++j) {
                if (dupCount[j] == 0) {
                    teamB += board[j][i];
                }
            }
        }
    }

    int diff = abs(teamB -teamA);
    if( diff < min ) {
        min = diff;
    }
}


void divideTeam(int *players, int *teams, int memCnt, int index, int currentMax)
{
    if (index == memCnt/2) {
//        printArray(teams, memCnt/2);
        solutions(teams,memCnt);
        return;
    }

    for (int i = 0; i < memCnt; ++i) {
        if (players[i] != 0 && i > currentMax){
            teams[index] = i+1;
            players[i]--;
            divideTeam(players, teams, memCnt, index+1, i);
            players[i]++;
        }
    }
};

int main()
{
    int players[20];

    int N;
    scanf("%d",&N);

    int idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &board[j][i]);
        }

        players[idx++] = 1;
    }

    int teams[20];
    idx = 0;
    divideTeam(players, teams, N, idx, -1);

    printf("%d", min);

    return 0;
}