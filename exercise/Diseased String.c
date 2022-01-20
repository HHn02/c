#include"stdio.h"
int main()
{
    int n;
    scanf("%d",&n);
    char a[105]={};
    int m;
    
    for (int i = 0; i < n; i++)
    {
        int sum=0;
        scanf("%d",&m);
        getchar();
        for (int i = 0; i < m; i++)
        {
            scanf("%c",&a[i]);
        }
        int pre=0,rear=0;
        int k=0;
        while (rear<m)
        {
            rear++;
            if(a[rear]=='y')
            {
                pre=rear;
                k=0;
            }   
            if(a[rear]=='b'&&a[pre]=='y'&&a[pre+1]=='b')
            {
               k++;
               if(k>=2)sum++;
            }
        }
        printf("%d",sum);
    }
    
}
