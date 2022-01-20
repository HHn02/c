#include"stdio.h"
#include <math.h>
int main()
{
    int m,n;
    int a[1001]={};
    scanf("%d %d",&m,&n);
    for (int i = 0; i < 1000; i++)
    {
        a[i]=i;
    }
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (a[i]!=-1)
        {
            for (int j = i*i; j <=n; j+=i)
            {
                a[j]=-1;
            }
            
        }   
    }
    
    for (int i = m; i < n; i++)
    {
        if (a[i]!=-1)
        {
            printf("%d\n",a[i]);
        }
    }
    
}