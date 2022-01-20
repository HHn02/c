#include "stdio.h"
#include "string.h"
int N;
int max = 0;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
void updata_attack(int x, int y, int attack[][N])
{
    int flag[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    attack[x][y] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (flag[j] == 0)
                continue;
            int nx = x + i * dx[j];
            int ny = y + i * dy[j];
            if (attack[nx][ny] == 5)
            {
                flag[j] = 0;
                continue;
            }
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                attack[nx][ny] = 1;
        }
    }
}
void copy_int_arry(int destarry[][N], int arr[][N])
{
    for (int i = 0; i < N; i++)
    {
        memcpy(&destarry[i], &arr[i], sizeof(int) * N);
    }
}
int check(int row, int attack[][N])
{
    int i;
    for (i = row; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (attack[i][j] == 0)
                return i;
        }
    }
    return i;
}
int checkmap(int attack[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (attack[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

void func(int row, int ans, int attack[][N])
{
    if (row == N || checkmap(attack))
    {
        if (ans > max)
        {
            max = ans;
        }
        return;
    }
    int attack_1[N][N];
    char queen_1[N][N];
    while (row < N)
    {
        for (int j = 0; j < N; j++)
        {
            if (attack[row][j] == 0)
            {
                copy_int_arry(attack_1, attack);
                updata_attack(row, j, attack);
                func(check(row, attack), ans + 1, attack);
                copy_int_arry(attack, attack_1);
                attack[row][j] = 1;
            }
        }
        row++;
    }
}
int main()
{
    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
            break;
        char ch;
        int attack[N][N];
        getchar();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%c", &ch);
                attack[i][j] = 0;
                if (ch == 'X')
                    attack[i][j] = 5;
            }
            getchar();
        }
        func(check(0, attack), 0, attack);
        printf("%d\n", max);
        max = 0;
    }
    return 0;
}
