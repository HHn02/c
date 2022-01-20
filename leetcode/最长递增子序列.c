/* O(n^2) */
#include<stdio.h>
int max(int n,int m);
int N;
int main()
{
    
    int a[20];
    scanf("%d",&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }
    int dp[20];
    int rec[20];
    for (int i = 0; i < N; i++)
    {
        dp[i]=1;
        rec[i]=-1;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <i; j++)
        {
            if (a[j]<a[i]&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                rec[i]=j;
            }
        }
    }
    int max=-999;
    int index;
    for (int i = 0; i < N; i++)
    {
        if(dp[i]>max)
        {
            max=dp[i];
            index=i;   //index最大下标
        }
    }
    printf("%d\n",max);
    int len=max;
    int lst[max];  //填充最大
    lst[max-1]=a[index];
    max-=2;
    for (;max>=0;max--)
    {
        lst[max]=a[rec[index]];
        index=rec[index];
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ",lst[i]);
    }
    
    
}
//O(NlogN)
//贪心＋二分
#include <stdio.h>
int main()  
{
    int N;
    scanf("%d",&N);
    int a[N],tail[N];
    int end=0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }
    tail[0]=a[0];
    for (int i = 1; i < N; i++)
    {
        if (a[i]>tail[end])
        {
            end++;
            tail[end]=a[i];
        }
        else
        {
            int left=0;
            int right=end;
            while (left<right)
            {
                int mid=left + ((right - left) >> 1);
                if (tail[mid]<a[i])
                {
                    left=mid+1;
                }
                else
                    right=mid;
            }
            tail[left]=a[i];
        }
    }
    end++;
    printf("%d",end);

}