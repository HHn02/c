#include"stdio.h"
int N;
int a[100][100];
void ans(int n)
{
    if(n>N)return ;
    int row=n-1;
    for (int line = 0; line < n; line++)
    {
        if(line==0||line==n-1)
            a[row][line]=1;
        else
            a[row][line]=a[row-1][line]+a[row-1][line-1];
    }
    return ans(n+1);
    
}
int main()
{
    scanf("%d",&N);
    ans(1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(a[i][j]!=0)
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}