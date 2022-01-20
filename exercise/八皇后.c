#include "stdio.h"
#include "string.h"
int N=8;
int ans=0;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
void updata_attack(int x, int y, int attack[][N])
{
    attack[x][y] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int nx = x + i * dx[j];
            int ny = y + i * dy[j];
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

void func(int row,int attack[][N], char queen[][N])
{
    if (row==N)
    {
        ans++;
        return ;
    }
    
    int attack_1[N][N];
    char queen_1[N][N];
    for (int i = 0; i < N; i++)
    {
        if (attack[row][i] == 0)
        {
            queen[row][i] = 'Q';
            copy_int_arry(attack_1, attack);
            updata_attack(row, i, attack);
            func(row+1,attack, queen);
            queen[row][i]='.';
            copy_int_arry(attack, attack_1);
        }
    }
  
}
int main()
{

    int attack[8][8]={};
    char queen[8][8]={};
    func(0,attack,queen);
    printf("%d",ans);
    return 0;
}