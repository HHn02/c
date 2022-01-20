#include "stdio.h"
int N;
int a[20][20];
int b[20];
int min_fee[20];
int t = 0, min = 9999;
int now_fee = 0;
void find_min(int row)
{
    for (int i = row; i < N; i++)
    {
        int min1=999;
        for (int j = 0; j < N; j++)
        {
            if (b[j]==0&&b[j]<min)
            {
                min1=b[j];
            }
        }
        min_fee[i]=min1;
    }
    
}
int bound(int n)
{
    find_min(n);
    int sum=0;
    for (int i = n; i < N; i++)
    {
        sum+=min_fee[i];
    }
    if(now_fee+sum>min)
        return 1;
    return 0;
}
void func(int row)
{
    if (bound(row) || row == N)
    {
        if (now_fee < min)
            min = now_fee;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            now_fee += a[row][i];
            func(row + 1);
            b[i] = 0;
            now_fee -= a[row][i];
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &a[i][j]);
    func(0);
    printf("%d", min);
    return 0;
}