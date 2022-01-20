#include "stdio.h"
int a[200][200];
int n;
int row = 0;
int line = 0;
int t1=0,t2=1,t3=0,t4;
int val = 0;
void ans(int n)
{
    
    t4=n-2;
    if(n<=0)return ;
    for ( line = t1; line < n; line++)
    {
        a[row][line]=++val;
    }
    line--;
    for ( row = t2; row < n; row++)
    {
        a[row][line]=++val;
    }
    row--;
    for (line=n-2; line >=t3; line--)
    {
        a[row][line]=++val;    
    }
    line++;
    for ( row = t4; row > t1; row--)
    {
        a[row][line]=++val;
    }
    row++;
    t1++;
    t2++;
    t3++;
    ans(n-1);
}
int main()
{
    scanf("%d",&n);
    ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    
}